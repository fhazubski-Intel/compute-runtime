/*
 * Copyright (C) 2021-2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once

#include "shared/source/os_interface/linux/ioctl_helper.h"
#include "shared/source/os_interface/linux/memory_info.h"
#include "shared/source/os_interface/linux/system_info.h"

#include "level_zero/sysman/source/linux/zes_os_sysman_imp.h"
#include "level_zero/sysman/source/memory/linux/sysman_os_memory_imp_prelim.h"
#include "level_zero/sysman/source/memory/sysman_memory_imp.h"
#include "level_zero/sysman/test/unit_tests/sources/linux/mock_sysman_hw_device_id.h"

#include "drm/i915_drm.h"
#include "drm/intel_hwconfig_types.h"

using namespace NEO;

constexpr uint16_t vF0VfidIndex = 88;
constexpr uint16_t vF0Hbm0ReadIndex = 92;
constexpr uint16_t vF0Hbm0WriteIndex = 96;
constexpr uint16_t vF0Hbm1ReadIndex = 104;
constexpr uint16_t vF0Hbm1WriteIndex = 108;
constexpr uint16_t vF0TimestampLIndex = 168;
constexpr uint16_t vF0TimestampHIndex = 172;
constexpr uint16_t vF1VfidIndex = 176;
constexpr uint16_t vF1Hbm0ReadIndex = 180;
constexpr uint16_t vF1Hbm0WriteIndex = 184;
constexpr uint16_t vF1Hbm1ReadIndex = 192;
constexpr uint16_t vF1Hbm1WriteIndex = 196;
constexpr uint16_t vF1TimestampLIndex = 256;
constexpr uint16_t vF1TimestampHIndex = 260;
constexpr uint16_t vF0Hbm2ReadIndex = 312;
constexpr uint16_t vF0Hbm2WriteIndex = 316;
constexpr uint16_t vF0Hbm3ReadIndex = 328;
constexpr uint16_t vF0Hbm3WriteIndex = 332;
constexpr uint16_t vF1Hbm2ReadIndex = 344;
constexpr uint16_t vF1Hbm2WriteIndex = 348;
constexpr uint16_t vF1Hbm3ReadIndex = 360;
constexpr uint16_t vF1Hbm3WriteIndex = 364;
constexpr uint32_t VF0HbmLRead = 16;
constexpr uint32_t VF0HbmHRead = 2;
constexpr uint32_t VF0HbmLWrite = 8;
constexpr uint32_t VF0HbmHWrite = 2;
constexpr uint32_t VF1HbmLRead = 16;
constexpr uint32_t VF1HbmHRead = 2;
constexpr uint32_t VF1HbmLWrite = 8;
constexpr uint32_t VF1HbmHWrite = 2;

constexpr uint8_t vF0VfidValue = 1;
constexpr uint8_t vF0Hbm0ReadValue = 92;
constexpr uint8_t vF0Hbm0WriteValue = 96;
constexpr uint8_t vF0Hbm1ReadValue = 104;
constexpr uint8_t vF0Hbm1WriteValue = 108;
constexpr uint8_t vF0TimestampLValue = 168;
constexpr uint8_t vF0TimestampHValue = 172;
constexpr uint8_t vF1VfidValue = 0;
constexpr uint8_t vF0Hbm2ReadValue = 113;
constexpr uint8_t vF0Hbm2WriteValue = 125;
constexpr uint8_t vF0Hbm3ReadValue = 135;
constexpr uint8_t vF0Hbm3WriteValue = 20;

constexpr uint8_t vF1Hbm0ReadValue = 92;
constexpr uint8_t vF1Hbm0WriteValue = 96;
constexpr uint8_t vF1Hbm1ReadValue = 104;
constexpr uint8_t vF1Hbm1WriteValue = 108;
constexpr uint8_t vF1TimestampLValue = 168;
constexpr uint8_t vF1TimestampHValue = 172;
constexpr uint8_t vF1Hbm2ReadValue = 113;
constexpr uint8_t vF1Hbm2WriteValue = 125;
constexpr uint8_t vF1Hbm3ReadValue = 135;
constexpr uint8_t vF1Hbm3WriteValue = 20;
constexpr uint64_t mockIdiReadVal = 8u;
constexpr uint64_t mockIdiWriteVal = 9u;
constexpr uint64_t mockDisplayVc1ReadVal = 10u;
constexpr uint64_t numberMcChannels = 16;
constexpr uint64_t transactionSize = 32;

namespace L0 {
namespace Sysman {
namespace ult {

uint32_t mockMemoryType = INTEL_HWCONFIG_MEMORY_TYPE_HBM2e;
std::string mockPhysicalSize = "0x00000040000000";
uint64_t hbmRP0Frequency = 4200; // in MHz
const std::string deviceMemoryHealth("device_memory_health");
std::string gpuUpstreamPortPathInMemory = "/sys/devices/pci0000:89/0000:89:02.0/0000:8a:00.0";
const std::string baseTelemSysFS("/sys/class/intel_pmt");
const std::string realPathTelem1 = "/sys/devices/pci0000:89/0000:89:02.0/0000:86:00.0/0000:8b:02.0/0000:8e:00.1/pmt_telemetry.1.auto/intel_pmt/telem1";
const std::string realPathTelem2 = "/sys/devices/pci0000:89/0000:89:02.0/0000:86:00.0/0000:8b:02.0/0000:8e:00.1/pmt_telemetry.1.auto/intel_pmt/telem2";
const std::string realPathTelem3 = "/sys/devices/pci0000:89/0000:89:02.0/0000:86:00.0/0000:8b:02.0/0000:8e:00.1/pmt_telemetry.1.auto/intel_pmt/telem3";
const std::string realPathTelem4 = "/sys/devices/pci0000:89/0000:89:02.0/0000:86:00.0/0000:8b:02.0/0000:8e:00.1/pmt_telemetry.1.auto/intel_pmt/telem4";
const std::string realPathTelem5 = "/sys/devices/pci0000:89/0000:89:02.0/0000:86:00.0/0000:8b:02.0/0000:8e:00.1/pmt_telemetry.1.auto/intel_pmt/telem5";
const std::string sysfsPahTelem1 = "/sys/class/intel_pmt/telem1";
const std::string sysfsPahTelem2 = "/sys/class/intel_pmt/telem2";
const std::string sysfsPahTelem3 = "/sys/class/intel_pmt/telem3";
const std::string sysfsPahTelem4 = "/sys/class/intel_pmt/telem4";
const std::string sysfsPahTelem5 = "/sys/class/intel_pmt/telem5";

struct MockMemorySysfsAccess : public L0::Sysman::SysfsAccess {

    std::vector<ze_result_t> mockReadReturnStatus{};
    std::vector<std::string> mockReadStringValue{};
    std::vector<uint64_t> mockReadUInt64Value{};
    bool isRepeated = false;

    ze_result_t getVal(const std::string file, std::string &val) {
        if ((file.compare("gt/gt0/addr_range") == 0) || (file.compare("gt/gt1/addr_range") == 0)) {
            val = mockPhysicalSize;
            return ZE_RESULT_SUCCESS;
        }
        val = "0";
        return ZE_RESULT_ERROR_NOT_AVAILABLE;
    }

    ze_result_t getValError(const std::string file, std::string &val) {
        val = "0";
        return ZE_RESULT_ERROR_NOT_AVAILABLE;
    }

    ze_result_t getMemHealthValReturnErrorNotAvailable(const std::string file, std::string &val) {
        if (file.compare(deviceMemoryHealth) == 0) {
            return ZE_RESULT_ERROR_NOT_AVAILABLE;
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t getMemHealthReturnErrorUnknown(const std::string file, std::string &val) {
        if (file.compare(deviceMemoryHealth) == 0) {
            return ZE_RESULT_ERROR_UNKNOWN;
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t read(const std::string file, std::string &val) override {
        ze_result_t result = ZE_RESULT_SUCCESS;
        if (!mockReadReturnStatus.empty()) {
            result = mockReadReturnStatus.front();
            if (!mockReadStringValue.empty()) {
                val = mockReadStringValue.front();
            }

            if (isRepeated != true) {
                mockReadReturnStatus.erase(mockReadReturnStatus.begin());
                if (!mockReadStringValue.empty()) {
                    mockReadStringValue.erase(mockReadStringValue.begin());
                }
            }
            return result;
        }

        if (file.compare(deviceMemoryHealth) == 0) {
            val = "OK";
        }
        return result;
    }

    ze_result_t read(const std::string file, uint64_t &val) override {
        ze_result_t result = ZE_RESULT_SUCCESS;
        if (!mockReadReturnStatus.empty()) {
            result = mockReadReturnStatus.front();
            if (!mockReadUInt64Value.empty()) {
                val = mockReadUInt64Value.front();
            }

            if (isRepeated != true) {
                mockReadReturnStatus.erase(mockReadReturnStatus.begin());
                if (!mockReadUInt64Value.empty()) {
                    mockReadUInt64Value.erase(mockReadUInt64Value.begin());
                }
            }
        }
        return result;
    }

    ze_result_t getMemHealthDegraded(const std::string file, std::string &val) {
        if (file.compare(deviceMemoryHealth) == 0) {
            val = "REBOOT_ALARM";
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t getMemHealthCritical(const std::string file, std::string &val) {
        if (file.compare(deviceMemoryHealth) == 0) {
            val = "DEGRADED";
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t getMemHealthReplace(const std::string file, std::string &val) {
        if (file.compare(deviceMemoryHealth) == 0) {
            val = "DEGRADED_FAILED";
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t getMemHealthUnknown(const std::string file, std::string &val) {
        if (file.compare(deviceMemoryHealth) == 0) {
            val = "RANDOM";
        }
        return ZE_RESULT_SUCCESS;
    }
};

struct MockMemoryNeoDrm : public NEO::Drm {
    using Drm::ioctlHelper;
    const int mockFd = 33;
    std::vector<bool> mockQuerySystemInfoReturnValue{};
    bool isRepeated = false;
    bool mockReturnEmptyRegions = false;
    MockMemoryNeoDrm(RootDeviceEnvironment &rootDeviceEnvironment) : Drm(std::make_unique<MockSysmanHwDeviceIdDrm>(mockFd, ""), rootDeviceEnvironment) {}

    void setMemoryType(uint32_t memory) {
        mockMemoryType = memory;
    }

    std::vector<uint64_t> getMemoryRegionsReturnsEmpty() {
        return {};
    }

    void resetSystemInfo() {
        systemInfo.reset(nullptr);
    }

    bool querySystemInfo() override {
        bool returnValue = true;
        if (!mockQuerySystemInfoReturnValue.empty()) {
            returnValue = mockQuerySystemInfoReturnValue.front();
            if (isRepeated != true) {
                mockQuerySystemInfoReturnValue.erase(mockQuerySystemInfoReturnValue.begin());
            }
            resetSystemInfo();
            return returnValue;
        }

        alignas(64) uint32_t hwBlob[] = {INTEL_HWCONFIG_MAX_MEMORY_CHANNELS, 1, 8, INTEL_HWCONFIG_MEMORY_TYPE, 0, mockMemoryType};
        std::vector<uint64_t> inputBlobData(reinterpret_cast<uint64_t *>(hwBlob), reinterpret_cast<uint64_t *>(ptrOffset(hwBlob, sizeof(hwBlob))));
        this->systemInfo.reset(new SystemInfo(inputBlobData));
        return returnValue;
    }
};

struct MockMemoryPmt : public L0::Sysman::PlatformMonitoringTech {

    using L0::Sysman::PlatformMonitoringTech::guid;
    using L0::Sysman::PlatformMonitoringTech::keyOffsetMap;
    std::vector<ze_result_t> mockReadValueReturnStatus{};
    std::vector<uint32_t> mockReadArgumentValue{};
    ze_result_t mockIdiReadValueFailureReturnStatus = ZE_RESULT_SUCCESS;
    ze_result_t mockIdiWriteFailureReturnStatus = ZE_RESULT_SUCCESS;
    ze_result_t mockDisplayVc1ReadFailureReturnStatus = ZE_RESULT_SUCCESS;
    ze_result_t mockReadTimeStampFailureReturnStatus = ZE_RESULT_SUCCESS;
    bool mockVfid0Status = false;
    bool mockVfid1Status = false;
    bool isRepeated = false;

    void setGuid(std::string guid) {
        this->guid = guid;
    }

    MockMemoryPmt(L0::Sysman::FsAccess *pFsAccess, ze_bool_t onSubdevice, uint32_t subdeviceId) : L0::Sysman::PlatformMonitoringTech(pFsAccess, onSubdevice, subdeviceId) {}
    ze_result_t readValue(const std::string key, uint32_t &val) override {
        ze_result_t result = ZE_RESULT_SUCCESS;

        if (mockVfid0Status == true) {
            return mockedReadValueWithVfid0True(key, val);
        }

        if (mockVfid1Status == true) {
            return mockedReadValueWithVfid1True(key, val);
        }

        if (!mockReadValueReturnStatus.empty()) {
            result = mockReadValueReturnStatus.front();
            if (!mockReadArgumentValue.empty()) {
                val = mockReadArgumentValue.front();
            }

            if (isRepeated != true) {
                mockReadValueReturnStatus.erase(mockReadValueReturnStatus.begin());
                if (!mockReadArgumentValue.empty()) {
                    mockReadArgumentValue.erase(mockReadArgumentValue.begin());
                }
            }
        }
        return result;
    }

    ze_result_t mockedReadValueWithVfid0True(const std::string key, uint32_t &val) {
        if (key.compare("VF0_VFID") == 0) {
            val = 1;
        } else if (key.compare("VF1_VFID") == 0) {
            val = 0;
        } else if (key.compare("VF0_HBM0_READ") == 0) {
            val = vF0Hbm0ReadValue;
        } else if (key.compare("VF0_HBM0_WRITE") == 0) {
            val = vF0Hbm0WriteValue;
        } else if (key.compare("VF0_HBM1_READ") == 0) {
            val = vF0Hbm1ReadValue;
        } else if (key.compare("VF0_HBM1_WRITE") == 0) {
            val = vF0Hbm1WriteValue;
        } else if (key.compare("VF0_TIMESTAMP_L") == 0) {
            val = vF0TimestampLValue;
        } else if (key.compare("VF0_TIMESTAMP_H") == 0) {
            val = vF0TimestampHValue;
        } else if (key.compare("VF0_HBM2_READ") == 0) {
            val = vF0Hbm2ReadValue;
        } else if (key.compare("VF0_HBM2_WRITE") == 0) {
            val = vF0Hbm2WriteValue;
        } else if (key.compare("VF0_HBM3_READ") == 0) {
            val = vF0Hbm3ReadValue;
        } else if (key.compare("VF0_HBM3_WRITE") == 0) {
            val = vF0Hbm3WriteValue;
        } else if (key.compare("VF0_HBM_READ_L") == 0) {
            val = VF0HbmLRead;
        } else if (key.compare("VF0_HBM_READ_H") == 0) {
            val = VF0HbmHRead;
        } else if (key.compare("VF0_HBM_WRITE_L") == 0) {
            val = VF0HbmLWrite;
        } else if (key.compare("VF0_HBM_WRITE_H") == 0) {
            val = VF0HbmHWrite;
        } else {
            return ZE_RESULT_ERROR_NOT_AVAILABLE;
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t mockedReadValueWithVfid1True(const std::string key, uint32_t &val) {
        if (key.compare("VF0_VFID") == 0) {
            val = 0;
        } else if (key.compare("VF1_VFID") == 0) {
            val = 1;
        } else if (key.compare("VF1_HBM0_READ") == 0) {
            val = vF1Hbm0ReadValue;
        } else if (key.compare("VF1_HBM0_WRITE") == 0) {
            val = vF1Hbm0WriteValue;
        } else if (key.compare("VF1_HBM1_READ") == 0) {
            val = vF1Hbm1ReadValue;
        } else if (key.compare("VF1_HBM1_WRITE") == 0) {
            val = vF1Hbm1WriteValue;
        } else if (key.compare("VF1_TIMESTAMP_L") == 0) {
            val = vF1TimestampLValue;
        } else if (key.compare("VF1_TIMESTAMP_H") == 0) {
            val = vF1TimestampHValue;
        } else if (key.compare("VF1_HBM2_READ") == 0) {
            val = vF1Hbm2ReadValue;
        } else if (key.compare("VF1_HBM2_WRITE") == 0) {
            val = vF1Hbm2WriteValue;
        } else if (key.compare("VF1_HBM3_READ") == 0) {
            val = vF1Hbm3ReadValue;
        } else if (key.compare("VF1_HBM3_WRITE") == 0) {
            val = vF1Hbm3WriteValue;
        } else if (key.compare("VF1_HBM_READ_L") == 0) {
            val = VF1HbmLRead;
        } else if (key.compare("VF1_HBM_READ_H") == 0) {
            val = VF1HbmHRead;
        } else if (key.compare("VF1_HBM_WRITE_L") == 0) {
            val = VF1HbmLWrite;
        } else if (key.compare("VF1_HBM_WRITE_H") == 0) {
            val = VF1HbmHWrite;
        } else {
            return ZE_RESULT_ERROR_NOT_AVAILABLE;
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t readValue(const std::string key, uint64_t &val) override {
        ze_result_t result = ZE_RESULT_SUCCESS;

        if (mockIdiReadValueFailureReturnStatus != ZE_RESULT_SUCCESS) {
            return mockIdiReadValueFailure(key, val);
        }

        if (mockIdiWriteFailureReturnStatus != ZE_RESULT_SUCCESS) {
            return mockIdiWriteFailure(key, val);
        }

        if (mockDisplayVc1ReadFailureReturnStatus != ZE_RESULT_SUCCESS) {
            return mockDisplayVc1ReadFailure(key, val);
        }

        if (mockReadTimeStampFailureReturnStatus != ZE_RESULT_SUCCESS) {
            return mockReadTimeStampFailure(key, val);
        }

        if (key.compare("IDI_READS[0]") == 0 || key.compare("IDI_READS[1]") == 0 || key.compare("IDI_READS[2]") == 0 || key.compare("IDI_READS[3]") == 0 || key.compare("IDI_READS[4]") == 0 || key.compare("IDI_READS[5]") == 0 || key.compare("IDI_READS[6]") == 0 || key.compare("IDI_READS[7]") == 0 || key.compare("IDI_READS[8]") == 0 || key.compare("IDI_READS[9]") == 0 || key.compare("IDI_READS[10]") == 0 || key.compare("IDI_READS[11]") == 0 || key.compare("IDI_READS[12]") == 0 || key.compare("IDI_READS[13]") == 0 || key.compare("IDI_READS[14]") == 0 || key.compare("IDI_READS[15]") == 0) {
            val = mockIdiReadVal;
        } else if (key.compare("IDI_WRITES[0]") == 0 || key.compare("IDI_WRITES[1]") == 0 || key.compare("IDI_WRITES[2]") == 0 || key.compare("IDI_WRITES[3]") == 0 || key.compare("IDI_WRITES[4]") == 0 || key.compare("IDI_WRITES[5]") == 0 || key.compare("IDI_WRITES[6]") == 0 || key.compare("IDI_WRITES[7]") == 0 || key.compare("IDI_WRITES[8]") == 0 || key.compare("IDI_WRITES[9]") == 0 || key.compare("IDI_WRITES[10]") == 0 || key.compare("IDI_WRITES[11]") == 0 || key.compare("IDI_WRITES[12]") == 0 || key.compare("IDI_WRITES[13]") == 0 || key.compare("IDI_WRITES[14]") == 0 || key.compare("IDI_WRITES[15]") == 0) {
            val = mockIdiWriteVal;
        } else if (key.compare("DISPLAY_VC1_READS[0]") == 0 || key.compare("DISPLAY_VC1_READS[1]") == 0 || key.compare("DISPLAY_VC1_READS[2]") == 0 || key.compare("DISPLAY_VC1_READS[3]") == 0 || key.compare("DISPLAY_VC1_READS[4]") == 0 || key.compare("DISPLAY_VC1_READS[5]") == 0 || key.compare("DISPLAY_VC1_READS[6]") == 0 || key.compare("DISPLAY_VC1_READS[7]") == 0 || key.compare("DISPLAY_VC1_READS[8]") == 0 || key.compare("DISPLAY_VC1_READS[9]") == 0 || key.compare("DISPLAY_VC1_READS[10]") == 0 || key.compare("DISPLAY_VC1_READS[11]") == 0 || key.compare("DISPLAY_VC1_READS[12]") == 0 || key.compare("DISPLAY_VC1_READS[13]") == 0 || key.compare("DISPLAY_VC1_READS[14]") == 0 || key.compare("DISPLAY_VC1_READS[15]") == 0) {
            val = mockDisplayVc1ReadVal;
        } else {
            result = ZE_RESULT_ERROR_NOT_AVAILABLE;
        }
        return result;
    }

    ze_result_t mockIdiReadValueFailure(const std::string key, uint64_t &val) {
        return ZE_RESULT_ERROR_UNKNOWN;
    }

    ze_result_t mockIdiWriteFailure(const std::string key, uint64_t &val) {
        if (key.compare("IDI_READS[0]") == 0 || key.compare("IDI_READS[1]") == 0 || key.compare("IDI_READS[2]") == 0 || key.compare("IDI_READS[3]") == 0 || key.compare("IDI_READS[4]") == 0 || key.compare("IDI_READS[5]") == 0 || key.compare("IDI_READS[6]") == 0 || key.compare("IDI_READS[7]") == 0 || key.compare("IDI_READS[8]") == 0 || key.compare("IDI_READS[9]") == 0 || key.compare("IDI_READS[10]") == 0 || key.compare("IDI_READS[11]") == 0 || key.compare("IDI_READS[12]") == 0 || key.compare("IDI_READS[13]") == 0 || key.compare("IDI_READS[14]") == 0 || key.compare("IDI_READS[15]") == 0) {
            val = mockIdiReadVal;
        } else if (key.compare("IDI_WRITES[0]") == 0 || key.compare("IDI_WRITES[1]") == 0 || key.compare("IDI_WRITES[2]") == 0 || key.compare("IDI_WRITES[3]") == 0 || key.compare("IDI_WRITES[4]") == 0 || key.compare("IDI_WRITES[5]") == 0 || key.compare("IDI_WRITES[6]") == 0 || key.compare("IDI_WRITES[7]") == 0 || key.compare("IDI_WRITES[8]") == 0 || key.compare("IDI_WRITES[9]") == 0 || key.compare("IDI_WRITES[10]") == 0 || key.compare("IDI_WRITES[11]") == 0 || key.compare("IDI_WRITES[12]") == 0 || key.compare("IDI_WRITES[13]") == 0 || key.compare("IDI_WRITES[14]") == 0 || key.compare("IDI_WRITES[15]") == 0) {
            return ZE_RESULT_ERROR_UNKNOWN;
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t mockDisplayVc1ReadFailure(const std::string key, uint64_t &val) {
        if (key.compare("IDI_READS[0]") == 0 || key.compare("IDI_READS[1]") == 0 || key.compare("IDI_READS[2]") == 0 || key.compare("IDI_READS[3]") == 0 || key.compare("IDI_READS[4]") == 0 || key.compare("IDI_READS[5]") == 0 || key.compare("IDI_READS[6]") == 0 || key.compare("IDI_READS[7]") == 0 || key.compare("IDI_READS[8]") == 0 || key.compare("IDI_READS[9]") == 0 || key.compare("IDI_READS[10]") == 0 || key.compare("IDI_READS[11]") == 0 || key.compare("IDI_READS[12]") == 0 || key.compare("IDI_READS[13]") == 0 || key.compare("IDI_READS[14]") == 0 || key.compare("IDI_READS[15]") == 0) {
            val = mockIdiReadVal;
        } else if (key.compare("IDI_WRITES[0]") == 0 || key.compare("IDI_WRITES[1]") == 0 || key.compare("IDI_WRITES[2]") == 0 || key.compare("IDI_WRITES[3]") == 0 || key.compare("IDI_WRITES[4]") == 0 || key.compare("IDI_WRITES[5]") == 0 || key.compare("IDI_WRITES[6]") == 0 || key.compare("IDI_WRITES[7]") == 0 || key.compare("IDI_WRITES[8]") == 0 || key.compare("IDI_WRITES[9]") == 0 || key.compare("IDI_WRITES[10]") == 0 || key.compare("IDI_WRITES[11]") == 0 || key.compare("IDI_WRITES[12]") == 0 || key.compare("IDI_WRITES[13]") == 0 || key.compare("IDI_WRITES[14]") == 0 || key.compare("IDI_WRITES[15]") == 0) {
            val = mockIdiWriteVal;
        } else if (key.compare("DISPLAY_VC1_READS[0]") == 0 || key.compare("DISPLAY_VC1_READS[1]") == 0 || key.compare("DISPLAY_VC1_READS[2]") == 0 || key.compare("DISPLAY_VC1_READS[3]") == 0 || key.compare("DISPLAY_VC1_READS[4]") == 0 || key.compare("DISPLAY_VC1_READS[5]") == 0 || key.compare("DISPLAY_VC1_READS[6]") == 0 || key.compare("DISPLAY_VC1_READS[7]") == 0 || key.compare("DISPLAY_VC1_READS[8]") == 0 || key.compare("DISPLAY_VC1_READS[9]") == 0 || key.compare("DISPLAY_VC1_READS[10]") == 0 || key.compare("DISPLAY_VC1_READS[11]") == 0 || key.compare("DISPLAY_VC1_READS[12]") == 0 || key.compare("DISPLAY_VC1_READS[13]") == 0 || key.compare("DISPLAY_VC1_READS[14]") == 0 || key.compare("DISPLAY_VC1_READS[15]") == 0) {
            return ZE_RESULT_ERROR_UNKNOWN;
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t mockReadTimeStampFailure(const std::string key, uint64_t &val) {
        if (key.compare("IDI_READS[0]") == 0 || key.compare("IDI_READS[1]") == 0 || key.compare("IDI_READS[2]") == 0 || key.compare("IDI_READS[3]") == 0 || key.compare("IDI_READS[4]") == 0 || key.compare("IDI_READS[5]") == 0 || key.compare("IDI_READS[6]") == 0 || key.compare("IDI_READS[7]") == 0 || key.compare("IDI_READS[8]") == 0 || key.compare("IDI_READS[9]") == 0 || key.compare("IDI_READS[10]") == 0 || key.compare("IDI_READS[11]") == 0 || key.compare("IDI_READS[12]") == 0 || key.compare("IDI_READS[13]") == 0 || key.compare("IDI_READS[14]") == 0 || key.compare("IDI_READS[15]") == 0) {
            val = mockIdiReadVal;
        } else if (key.compare("IDI_WRITES[0]") == 0 || key.compare("IDI_WRITES[1]") == 0 || key.compare("IDI_WRITES[2]") == 0 || key.compare("IDI_WRITES[3]") == 0 || key.compare("IDI_WRITES[4]") == 0 || key.compare("IDI_WRITES[5]") == 0 || key.compare("IDI_WRITES[6]") == 0 || key.compare("IDI_WRITES[7]") == 0 || key.compare("IDI_WRITES[8]") == 0 || key.compare("IDI_WRITES[9]") == 0 || key.compare("IDI_WRITES[10]") == 0 || key.compare("IDI_WRITES[11]") == 0 || key.compare("IDI_WRITES[12]") == 0 || key.compare("IDI_WRITES[13]") == 0 || key.compare("IDI_WRITES[14]") == 0 || key.compare("IDI_WRITES[15]") == 0) {
            val = mockIdiWriteVal;
        } else if (key.compare("DISPLAY_VC1_READS[0]") == 0 || key.compare("DISPLAY_VC1_READS[1]") == 0 || key.compare("DISPLAY_VC1_READS[2]") == 0 || key.compare("DISPLAY_VC1_READS[3]") == 0 || key.compare("DISPLAY_VC1_READS[4]") == 0 || key.compare("DISPLAY_VC1_READS[5]") == 0 || key.compare("DISPLAY_VC1_READS[6]") == 0 || key.compare("DISPLAY_VC1_READS[7]") == 0 || key.compare("DISPLAY_VC1_READS[8]") == 0 || key.compare("DISPLAY_VC1_READS[9]") == 0 || key.compare("DISPLAY_VC1_READS[10]") == 0 || key.compare("DISPLAY_VC1_READS[11]") == 0 || key.compare("DISPLAY_VC1_READS[12]") == 0 || key.compare("DISPLAY_VC1_READS[13]") == 0 || key.compare("DISPLAY_VC1_READS[14]") == 0 || key.compare("DISPLAY_VC1_READS[15]") == 0) {
            val = mockDisplayVc1ReadVal;
        } else {
            return ZE_RESULT_ERROR_NOT_AVAILABLE;
        }
        return ZE_RESULT_SUCCESS;
    }
};

struct MockMemoryFsAccess : public L0::Sysman::FsAccess {
    ze_result_t listDirectory(const std::string directory, std::vector<std::string> &listOfTelemNodes) override {
        if (directory.compare(baseTelemSysFS) == 0) {
            listOfTelemNodes.push_back("telem1");
            listOfTelemNodes.push_back("telem2");
            listOfTelemNodes.push_back("telem3");
            listOfTelemNodes.push_back("telem4");
            listOfTelemNodes.push_back("telem5");
            return ZE_RESULT_SUCCESS;
        }
        return ZE_RESULT_ERROR_NOT_AVAILABLE;
    }

    ze_result_t listDirectoryFailure(const std::string directory, std::vector<std::string> &events) {
        return ZE_RESULT_ERROR_NOT_AVAILABLE;
    }

    ze_result_t getRealPath(const std::string path, std::string &buf) override {
        if (path.compare(sysfsPahTelem1) == 0) {
            buf = realPathTelem1;
        } else if (path.compare(sysfsPahTelem2) == 0) {
            buf = realPathTelem2;
        } else if (path.compare(sysfsPahTelem3) == 0) {
            buf = realPathTelem3;
        } else if (path.compare(sysfsPahTelem4) == 0) {
            buf = realPathTelem4;
        } else if (path.compare(sysfsPahTelem5) == 0) {
            buf = realPathTelem5;
        } else {
            return ZE_RESULT_ERROR_NOT_AVAILABLE;
        }
        return ZE_RESULT_SUCCESS;
    }

    ze_result_t getRealPathFailure(const std::string path, std::string &buf) {
        return ZE_RESULT_ERROR_NOT_AVAILABLE;
    }

    MockMemoryFsAccess() = default;
};

class PublicLinuxMemoryImp : public L0::Sysman::LinuxMemoryImp {
  public:
    PublicLinuxMemoryImp(L0::Sysman::OsSysman *pOsSysman, ze_bool_t onSubdevice, uint32_t subdeviceId) : LinuxMemoryImp(pOsSysman, onSubdevice, subdeviceId) {}
    PublicLinuxMemoryImp() = default;
    using LinuxMemoryImp::getHbmFrequency;
};

} // namespace ult
} // namespace Sysman
} // namespace L0
