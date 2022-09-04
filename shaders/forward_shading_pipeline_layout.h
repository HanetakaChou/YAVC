#ifndef _FORWARD_SHADING_PIPELINE_LAYOUT_H_
#define _FORWARD_SHADING_PIPELINE_LAYOUT_H_ 1

#if defined(__STDC__) || defined(__cplusplus)

struct forward_shading_layout_global_set_frame_uniform_buffer_binding
{
    DirectX::XMFLOAT4X4 view_transform;
    DirectX::XMFLOAT4X4 projection_transform;
};

struct forward_shading_layout_global_set_object_uniform_buffer_binding
{
    DirectX::XMFLOAT4X4 model_transform;
};

#elif defined(GL_SPIRV) || defined(VULKAN)

layout(set = 0, binding = 0, column_major) uniform _global_set_frame_binding
{
    highp mat4x4 V;
    highp mat4x4 P;
};

layout(set = 0, binding = 1, column_major) uniform _global_set_object_binding
{
    highp mat4x4 M;
};

layout(set = 1, binding = 0) highp uniform sampler2D _material_set_emissive_texture_binding;

#else
#error Unknown Compiler
#endif

#endif