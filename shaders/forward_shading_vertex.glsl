#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "forward_shading_pipeline_layout.h"

layout(location = 0) in highp vec3 vertex_input_position;
layout(location = 1) in highp vec2 vertex_input_uv;

layout(location = 0) out highp vec2 vertex_output_uv;

void main()
{
    gl_Position = P * V * M * vec4(vertex_input_position, 1.0f);
    vertex_output_uv = vertex_input_uv;
}
