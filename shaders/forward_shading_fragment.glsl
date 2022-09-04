#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "forward_shading_pipeline_layout.h"

layout(location = 0) in highp vec2 interpolated_uv;

layout(location = 0) out highp vec4 fragment_output_color;

void main()
{
   fragment_output_color = texture(_material_set_emissive_texture_binding, interpolated_uv);
}