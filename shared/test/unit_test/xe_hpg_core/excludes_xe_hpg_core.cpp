/*
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "shared/test/common/test_macros/hw_test_base.h"

HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenSamplerStateWhenAdjustSamplerStateThenNothingIsChanged, IGFX_XE_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedIfBlitterForImagesIsSupportedThenFalseIsReturned, IGFX_XE_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(HwInfoConfigTest, givenHwInfoConfigWhenAskedIfTile64With3DSurfaceOnBCSIsSupportedThenTrueIsReturned, IGFX_XE_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(CommandEncodeStatesTest, givenEventAddressWhenEncodeThenMocsFromGmmHelperIsSet, IGFX_XE_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(XeHPAndLaterPreemptionTests, GivenDebuggerUsedWhenProgrammingStateSipThenStateSipIsAdded, IGFX_XE_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenComputeModeCmdSizeWhenLargeGrfModeChangeIsRequiredThenSCMCommandSizeIsCalculated, IGFX_XE_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenCoherencyWithSharedHandlesWhenCommandSizeIsCalculatedThenCorrectCommandSizeIsReturned, IGFX_XE_HPG_CORE);
HWTEST_EXCLUDE_PRODUCT(ComputeModeRequirements, givenCoherencyWithoutSharedHandlesWhenCommandSizeIsCalculatedThenCorrectCommandSizeIsReturned, IGFX_XE_HPG_CORE);