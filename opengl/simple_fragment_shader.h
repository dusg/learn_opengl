//
// Created by Du Carl on 2018/6/18.
//

#ifndef OPENGL_SIMPLE_FRAGMENT_SHADER_H
#define OPENGL_SIMPLE_FRAGMENT_SHADER_H
const char* simple_fragment_shader_src = "#version 210 core \n\
out vec4 FragColor;\
void main()\n\
{\n\
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\
}\n\
\
";
#endif //OPENGL_SIMPLE_FRAGMENT_SHADER_H
