// based on
// https://github.com/elima/gpu-playground/blob/master/render-nodes-minimal/main.c

#include <QCoreApplication>
#include <QDebug>

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl31.h>
#include <fcntl.h>
#include <gbm.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    bool result = false;
    QCoreApplication a(argc, argv);
    int32_t fd = open ("/dev/dri/renderD128", O_RDWR);

    struct gbm_device *gbm = gbm_create_device (fd);

    /* setup EGL from the GBM device */
    EGLDisplay egl_dpy = eglGetPlatformDisplay (EGL_PLATFORM_GBM_MESA, gbm, NULL);
    result = eglInitialize (egl_dpy, NULL, NULL);
    if (!result){
        qErrnoWarning("EGL can't initialized, exiting...");
        return -1;
    }

    QString esExt(eglQueryString (egl_dpy, EGL_EXTENSIONS));
    //qInfo() << "Extentions" << esExt;
    if (!esExt.contains("EGL_KHR_create_context")){
        qErrnoWarning("Missing EGL_KHR_create_context, exiting...");
        return -2;
    }
    if (!esExt.contains("GL_KHR_surfaceless_context")){
        qErrnoWarning("Missing GL_KHR_surfaceless_context, exiting...");
        return -3;
    }

    static const EGLint config_attribs[] = {
          EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT_KHR,
          EGL_NONE
       };
       EGLConfig cfg;
       EGLint count;

       result = eglChooseConfig (egl_dpy, config_attribs, &cfg, 1, &count);

       if (!result){
           qErrnoWarning("Can't create ES3, exiting...");
           return -4;
       }

       result = eglBindAPI (EGL_OPENGL_ES_API);
       if (!result){
           qErrnoWarning("Can't bind ES API, exiting...");
           return -5;
       }

       static const EGLint attribs[] = {
          EGL_CONTEXT_CLIENT_VERSION, 3,
          EGL_NONE
       };
       EGLContext core_ctx = eglCreateContext (egl_dpy,
                                               cfg,
                                               EGL_NO_CONTEXT,
                                               attribs);
     if (core_ctx == EGL_NO_CONTEXT){
         qErrnoWarning("Can't create surfaceless context, exiting...");
         return -6;
     }

     result = eglMakeCurrent (egl_dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, core_ctx);
     if (!result){
         qErrnoWarning("Can't make ES Current, exiting...");
         return -7;
     }
 
    GLint max_invocations;
    glGetIntegerv (GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &max_invocations);
    qInfo() << "GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS" << max_invocations;

    GLint mem_size;
    glGetIntegerv (GL_MAX_COMPUTE_SHARED_MEMORY_SIZE, &mem_size);
    qInfo() << "GL_MAX_COMPUTE_SHARED_MEMORY_SIZE" << mem_size;

    //the end
    eglDestroyContext (egl_dpy, core_ctx);
   eglTerminate (egl_dpy);
   gbm_device_destroy (gbm);
   //fclose (fd);
    return a.exec();
}
