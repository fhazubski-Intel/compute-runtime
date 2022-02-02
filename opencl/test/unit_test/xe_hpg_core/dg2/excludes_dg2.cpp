/*
 * Copyright (C) 2021-2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/test/common/test_macros/test.h"

HWTEST_EXCLUDE_PRODUCT(HwHelperTest, GivenZeroSlmSizeWhenComputeSlmSizeIsCalledThenCorrectValueIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, WhenAllowCompressionIsCalledThenTrueIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHardwareInfoWhenCallingIsAdditionalStateBaseAddressWARequiredThenFalseIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHardwareInfoWhenCallingIsMaxThreadsForWorkgroupWARequiredThenFalseIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedForDefaultEngineTypeAdjustmentThenFalseIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedIfAllocationSizeAdjustmentIsRequiredThenFalseIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedIfPrefetchDisablingIsRequiredThenFalseIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedIfTile64With3DSurfaceOnBCSIsSupportedThenTrueIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTestXeHpAndLater, givenXeHPAndLaterPlatformWhenAskedIfTile64With3DSurfaceOnBCSIsSupportedThenFalseIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(WddmMemoryManagerSimpleTest, givenLinearStreamWhenItIsAllocatedThenItIsInLocalMemoryHasCpuPointerAndHasStandardHeap64kbAsGpuAddress, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, WhenAllowRenderCompressionIsCalledThenTrueIsReturned, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, whenConvertingTimestampsToCsDomainThenNothingIsChanged, IGFX_DG2);
HWTEST_EXCLUDE_PRODUCT(HwHelperTestXeHPAndLater, GiveCcsNodeThenDefaultEngineTypeIsCcs, IGFX_DG2);
