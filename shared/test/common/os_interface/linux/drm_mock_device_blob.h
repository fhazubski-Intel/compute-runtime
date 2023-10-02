/*
 * Copyright (C) 2021-2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "drm/intel_hwconfig_types.h"

alignas(64) static constexpr uint32_t dummyDeviceBlobData[] = {
    INTEL_HWCONFIG_MAX_SLICES_SUPPORTED,
    1,
    0x01,
    INTEL_HWCONFIG_MAX_DUAL_SUBSLICES_SUPPORTED,
    1,
    0x04,
    INTEL_HWCONFIG_MAX_NUM_EU_PER_DSS,
    1,
    0x03,
    INTEL_HWCONFIG_NUM_PIXEL_PIPES,
    1,
    0x04,
    INTEL_HWCONFIG_L3_CACHE_WAYS_SIZE_IN_BYTES,
    1,
    0x08,
    INTEL_HWCONFIG_L3_CACHE_WAYS_PER_SECTOR,
    1,
    0x09,
    INTEL_HWCONFIG_MAX_MEMORY_CHANNELS,
    1,
    0x0A,
    INTEL_HWCONFIG_MEMORY_TYPE,
    1,
    0x0B,
    INTEL_HWCONFIG_CACHE_TYPES,
    1,
    0x0C,
    INTEL_HWCONFIG_LOCAL_MEMORY_PAGE_SIZES_SUPPORTED,
    1,
    0x0D,
    INTEL_HWCONFIG_NUM_THREADS_PER_EU,
    1,
    0x0F,
    INTEL_HWCONFIG_TOTAL_VS_THREADS,
    1,
    0x10,
    INTEL_HWCONFIG_TOTAL_GS_THREADS,
    1,
    0x11,
    INTEL_HWCONFIG_TOTAL_HS_THREADS,
    1,
    0x12,
    INTEL_HWCONFIG_TOTAL_DS_THREADS,
    1,
    0x13,
    INTEL_HWCONFIG_TOTAL_VS_THREADS_POCS,
    1,
    0x14,
    INTEL_HWCONFIG_TOTAL_PS_THREADS,
    1,
    0x15,
    INTEL_HWCONFIG_MAX_RCS,
    1,
    0x17,
    INTEL_HWCONFIG_MAX_CCS,
    1,
    0x18,
    INTEL_HWCONFIG_MAX_VCS,
    1,
    0x19,
    INTEL_HWCONFIG_MAX_VECS,
    1,
    0x1A,
    INTEL_HWCONFIG_MAX_COPY_CS,
    1,
    0x1B,
    INTEL_HWCONFIG_MIN_VS_URB_ENTRIES,
    1,
    0x1D,
    INTEL_HWCONFIG_MAX_VS_URB_ENTRIES,
    1,
    0x1E,
    INTEL_HWCONFIG_MIN_PCS_URB_ENTRIES,
    1,
    0x1E,
    INTEL_HWCONFIG_MAX_PCS_URB_ENTRIES,
    1,
    0x1F,
    INTEL_HWCONFIG_MIN_HS_URB_ENTRIES,
    1,
    0x20,
    INTEL_HWCONFIG_MAX_HS_URB_ENTRIES,
    1,
    0x21,
    INTEL_HWCONFIG_MIN_GS_URB_ENTRIES,
    1,
    0x22,
    INTEL_HWCONFIG_MAX_GS_URB_ENTRIES,
    1,
    0x23,
    INTEL_HWCONFIG_MIN_DS_URB_ENTRIES,
    1,
    0x24,
    INTEL_HWCONFIG_MAX_DS_URB_ENTRIES,
    1,
    0x25,
    INTEL_HWCONFIG_PUSH_CONSTANT_URB_RESERVED_SIZE,
    1,
    0x26,
    INTEL_HWCONFIG_POCS_PUSH_CONSTANT_URB_RESERVED_SIZE,
    1,
    0x27,
    INTEL_HWCONFIG_URB_REGION_ALIGNMENT_SIZE_IN_BYTES,
    1,
    0x28,
    INTEL_HWCONFIG_URB_ALLOCATION_SIZE_UNITS_IN_BYTES,
    1,
    0x29,
    INTEL_HWCONFIG_MAX_URB_SIZE_CCS_IN_BYTES,
    1,
    0x2A,
    INTEL_HWCONFIG_VS_MIN_DEREF_BLOCK_SIZE_HANDLE_COUNT,
    1,
    0x2B,
    INTEL_HWCONFIG_DS_MIN_DEREF_BLOCK_SIZE_HANDLE_COUNT,
    1,
    0x2C,
    INTEL_HWCONFIG_L3_BANK_SIZE_IN_KB,
    1,
    0x2D,
};

const std::vector<uint64_t> inputBlobData(reinterpret_cast<const uint64_t *>(dummyDeviceBlobData),
                                          reinterpret_cast<const uint64_t *>(ptrOffset(dummyDeviceBlobData, sizeof(dummyDeviceBlobData))));
