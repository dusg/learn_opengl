
const char * simple_vertex_shader_src = "\
#version 210 core  \n\
\
layout (location = 0) in vec3 aPos; \n\
void main()\n\
{\n\
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n\
}\n\
";