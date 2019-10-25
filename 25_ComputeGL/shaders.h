#ifndef SHADERS_H
#define SHADERS_H
static const char *vsDisplaySource =
    "const vec4 vertices[8] = vec4[8] (\n"
    "        vec4( -2.0,  1.0, 0.0, 1.0),\n"
    "        vec4( -2.0, -1.0, 0.0, 1.0),\n"
    "        vec4(  0.0,  1.0, 0.0, 1.0),\n"
    "        vec4(  0.0, -1.0, 0.0, 1.0),\n"
    "        vec4(  0.0,  1.0, 0.0, 1.0),\n"
    "        vec4(  0.0, -1.0, 0.0, 1.0),\n"
    "        vec4(  2.0,  1.0, 0.0, 1.0),\n"
    "        vec4(  2.0, -1.0, 0.0, 1.0)\n"
    ");\n"
    "const vec2 texCoords[8] = vec2[8] (\n"
    "        vec2( 0.0,  1.0),\n"
    "        vec2( 0.0,  0.0),\n"
    "        vec2( 1.0,  1.0),\n"
    "        vec2( 1.0,  0.0),\n"
    "        vec2( 0.0,  1.0),\n"
    "        vec2( 0.0,  0.0),\n"
    "        vec2( 1.0,  1.0),\n"
    "        vec2( 1.0,  0.0)\n"
    ");\n"
    "out vec2 texCoord;\n"
    "out vec2 selectTX;\n"
    "uniform mat4 matProjection;\n"
    "void main() {\n"
    "   gl_Position = matProjection * vertices[gl_VertexID];\n"
    "   texCoord = texCoords[gl_VertexID];\n"
    "   if(gl_VertexID > 3) {\n"
    "      selectTX.x=1;\n"
    "   } else {\n"
    "       selectTX.x=0;\n"
    "   }\n"
    "}\n";

static const char *fsDisplaySource =
    "in lowp vec2 texCoord; \n"
    "in lowp vec2 selectTX; \n"
    "uniform sampler2D samImage; \n"
    "uniform sampler2D resImage; \n"
    "layout(location = 0) out lowp vec4 color;\n"
    "void main() {\n"
    "   lowp vec4 texColor;\n"
        "if (selectTX.x>0){\n"
    "    texColor = texture(samImage,texCoord);\n"
        "} else {\n"
        "    texColor = texture(resImage,texCoord);\n"
        "}\n"
    "   color = vec4(texColor.rgb, 1.0);\n"
    "}\n";

//just copy one texture to another
static const char *csComputeSource =
        "layout(local_size_x=16, local_size_y=16) in;\n"
        "layout(binding=0, rgba8) uniform readonly highp image2D inputImage;\n"
        "layout(binding=1, rgba8) uniform writeonly highp image2D resultImage;\n"
        "void main() {\n"
        "  int x = int(gl_GlobalInvocationID.x);\n"
        "  int y = int(gl_GlobalInvocationID.y);\n"
        "  vec4 imgValue =  imageLoad(inputImage, ivec2(x,y));\n"
        "  imageStore(resultImage, ivec2(x,y), imgValue);\n"
        "}\n";
#endif // SHADERS_H
