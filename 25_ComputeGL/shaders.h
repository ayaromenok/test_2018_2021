#ifndef SHADERS_H
#define SHADERS_H
static const char *vsDisplaySource =
    "const vec4 vertices[4] = vec4[4] (\n"
    "        vec4( -1.0,  1.0, 0.0, 1.0),\n"
    "        vec4( -1.0, -1.0, 0.0, 1.0),\n"
    "        vec4(  1.0,  1.0, 0.0, 1.0),\n"
    "        vec4(  1.0, -1.0, 0.0, 1.0)\n"
    ");\n"
    "const vec2 texCoords[4] = vec2[4] (\n"
    "        vec2( 0.0,  1.0),\n"
    "        vec2( 0.0,  0.0),\n"
    "        vec2( 1.0,  1.0),\n"
    "        vec2( 1.0,  0.0)\n"
    ");\n"
    "out vec2 texCoord;\n"
    "uniform mat4 matProjection;\n"
    "void main() {\n"
    "   gl_Position = matProjection * vertices[gl_VertexID];\n"
    "   texCoord = texCoords[gl_VertexID];\n"
    "}\n";

static const char *fsDisplaySource =
    "in lowp vec2 texCoord; \n"
    "uniform sampler2D samImage; \n"
    "layout(location = 0) out lowp vec4 color;\n"
    "void main() {\n"
    "   lowp vec4 texColor = texture(samImage,texCoord);\n"
    "   color = vec4(texColor.rgb, 1.0);\n"
    "}\n";

//just copy one texture to another
static const char *csComputeSource =
        "layout(binding=0, rgba8) uniform readonly highp image2D inputImage;\n"
        "layout(binding=1, rgba8) uniform writeonly highp image2D resultImage;\n"
        "void main() {\n"
        "  int x = int(gl_GlobalInvocationID.x);\n"
        "  int y = int(gl_GlobalInvocationID.y);\n"
        "  vec4 imgValue =  imageLoad(inputImage, ivec2(x,y));\n"
        "  imageStore(resultImage, ivec2(x,y), imgValue);\n"
        "}\n";
#endif // SHADERS_H
