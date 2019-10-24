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
    "   color = vec4(0.8,0.5,0.5,1.0);//vec4(texColor.rgb, 1.0);\n"
    "}\n";

#endif // SHADERS_H
