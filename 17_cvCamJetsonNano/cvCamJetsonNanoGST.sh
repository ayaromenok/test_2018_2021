gst-launch-1.0 nvarguscamerasrc ! 'video/x-raw(memory:NVMM),width=1280, height=720, framerate=120/1, format=NV12' ! nvvidconv flip-method=0 ! 'video/x-raw' ! nvvidconv ! nvegltransform ! nveglglessink -e

