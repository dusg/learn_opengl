//
// Created by Du Carl on 2018/6/18.
//

#include "ShaderStore.h"

const GLchar *ShaderStore::GetSimpleVertexShaderSource() {
#include "simple_vertex_shader.h"
    return simple_vertex_shader_src;
}

const GLchar *ShaderStore::GetSimpleFragmentShaderSource() {
#include "simple_fragment_shader.h"
    return simple_fragment_shader_src;
}
