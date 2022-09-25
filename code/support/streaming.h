#ifndef _STREAMING_H_
#define _STREAMING_H_ 1

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#ifndef VK_USE_PLATFORM_WIN32_KHR
#define VK_USE_PLATFORM_WIN32_KHR 1
#endif
#include <sdkddkver.h>
#include <windows.h>
#include "../../vulkansdk/include/vulkan/vulkan.h"

enum STREAMING_ASSET_BUFFER_TYPE
{
	ASSET_VERTEX_BUFFER,
	ASSET_INDEX_BUFFER,
	ASSET_UNIFORM_BUFFER
};

void streaming_staging_to_asset_buffer(
	PFN_vkCmdPipelineBarrier pfn_cmd_pipeline_barrier, PFN_vkCmdCopyBuffer pfn_cmd_copy_buffer,
	bool vulkan_has_dedicated_transfer_queue, uint32_t vulkan_queue_transfer_family_index, uint32_t vulkan_queue_graphics_family_index, VkCommandBuffer vulkan_streaming_transfer_command_buffer, VkCommandBuffer vulkan_streaming_graphics_command_buffer,
	VkBuffer staging_buffer, VkBuffer asset_buffer, uint32_t region_count, VkBufferCopy *const regions, enum STREAMING_ASSET_BUFFER_TYPE asset_buffer_type);

void streaming_staging_to_asset_image(
	PFN_vkCmdPipelineBarrier pfn_cmd_pipeline_barrier, PFN_vkCmdCopyBufferToImage pfn_cmd_copy_buffer_to_image,
	bool vulkan_has_dedicated_transfer_queue, uint32_t vulkan_queue_transfer_family_index, uint32_t vulkan_queue_graphics_family_index, VkCommandBuffer vulkan_streaming_transfer_command_buffer, VkCommandBuffer vulkan_streaming_graphics_command_buffer,
	VkBuffer staging_buffer, VkImage asset_image, uint32_t region_count, VkBufferImageCopy *const regions, VkImageSubresourceRange const &asset_image_subresource_range);

#endif