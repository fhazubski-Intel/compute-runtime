/*
 * Copyright (C) 2020-2023 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "level_zero/core/source/builtin/builtin_functions_lib_impl.h"

#include "shared/source/built_ins/built_ins.h"
#include "shared/source/debug_settings/debug_settings_manager.h"
#include "shared/source/os_interface/os_interface.h"

#include "level_zero/core/source/device/device.h"
#include "level_zero/core/source/kernel/kernel.h"

namespace NEO {
const char *getAdditionalBuiltinAsString(EBuiltInOps::Type builtin) {
    return nullptr;
}
} // namespace NEO

namespace L0 {

BuiltinFunctionsLibImpl::BuiltinData::~BuiltinData() {
    func.reset();
}
BuiltinFunctionsLibImpl::BuiltinData::BuiltinData() = default;
BuiltinFunctionsLibImpl::BuiltinData::BuiltinData(Module *module, std::unique_ptr<L0::Kernel> &&ker) : module(module), func(std::move(ker)) {}
std::unique_lock<BuiltinFunctionsLib::MutexType> BuiltinFunctionsLib::obtainUniqueOwnership() {
    return std::unique_lock<BuiltinFunctionsLib::MutexType>(this->ownershipMutex);
}

void BuiltinFunctionsLibImpl::initBuiltinKernel(Builtin func) {
    const char *builtinName = nullptr;
    NEO::EBuiltInOps::Type builtin;

    switch (func) {
    case Builtin::copyBufferBytes:
        builtinName = "copyBufferToBufferBytesSingle";
        builtin = NEO::EBuiltInOps::copyBufferToBuffer;
        break;
    case Builtin::copyBufferBytesStateless:
        builtinName = "copyBufferToBufferBytesSingle";
        builtin = NEO::EBuiltInOps::copyBufferToBufferStateless;
        break;
    case Builtin::copyBufferRectBytes2d:
        builtinName = "CopyBufferRectBytes2d";
        builtin = NEO::EBuiltInOps::copyBufferRect;
        break;
    case Builtin::copyBufferRectBytes3d:
        builtinName = "CopyBufferRectBytes3d";
        builtin = NEO::EBuiltInOps::copyBufferRect;
        break;
    case Builtin::copyBufferToBufferMiddle:
        builtinName = "CopyBufferToBufferMiddleRegion";
        builtin = NEO::EBuiltInOps::copyBufferToBuffer;
        break;
    case Builtin::copyBufferToBufferMiddleStateless:
        builtinName = "CopyBufferToBufferMiddleRegion";
        builtin = NEO::EBuiltInOps::copyBufferToBufferStateless;
        break;
    case Builtin::copyBufferToBufferSide:
        builtinName = "CopyBufferToBufferSideRegion";
        builtin = NEO::EBuiltInOps::copyBufferToBuffer;
        break;
    case Builtin::copyBufferToBufferSideStateless:
        builtinName = "CopyBufferToBufferSideRegion";
        builtin = NEO::EBuiltInOps::copyBufferToBufferStateless;
        break;
    case Builtin::fillBufferImmediate:
        builtinName = "FillBufferImmediate";
        builtin = NEO::EBuiltInOps::fillBuffer;
        break;
    case Builtin::fillBufferImmediateStateless:
        builtinName = "FillBufferImmediate";
        builtin = NEO::EBuiltInOps::fillBufferStateless;
        break;
    case Builtin::fillBufferImmediateLeftOver:
        builtinName = "FillBufferImmediateLeftOver";
        builtin = NEO::EBuiltInOps::fillBuffer;
        break;
    case Builtin::fillBufferImmediateLeftOverStateless:
        builtinName = "FillBufferImmediateLeftOver";
        builtin = NEO::EBuiltInOps::fillBufferStateless;
        break;
    case Builtin::fillBufferSSHOffset:
        builtinName = "FillBufferSSHOffset";
        builtin = NEO::EBuiltInOps::fillBuffer;
        break;
    case Builtin::fillBufferSSHOffsetStateless:
        builtinName = "FillBufferSSHOffset";
        builtin = NEO::EBuiltInOps::fillBufferStateless;
        break;
    case Builtin::fillBufferMiddle:
        builtinName = "FillBufferMiddle";
        builtin = NEO::EBuiltInOps::fillBuffer;
        break;
    case Builtin::fillBufferMiddleStateless:
        builtinName = "FillBufferMiddle";
        builtin = NEO::EBuiltInOps::fillBufferStateless;
        break;
    case Builtin::fillBufferRightLeftover:
        builtinName = "FillBufferRightLeftover";
        builtin = NEO::EBuiltInOps::fillBuffer;
        break;
    case Builtin::fillBufferRightLeftoverStateless:
        builtinName = "FillBufferRightLeftover";
        builtin = NEO::EBuiltInOps::fillBufferStateless;
        break;
    case Builtin::queryKernelTimestamps:
        builtinName = "QueryKernelTimestamps";
        builtin = NEO::EBuiltInOps::queryKernelTimestamps;
        break;
    case Builtin::queryKernelTimestampsWithOffsets:
        builtinName = "QueryKernelTimestampsWithOffsets";
        builtin = NEO::EBuiltInOps::queryKernelTimestamps;
        break;
    default:
        UNRECOVERABLE_IF(true);
    };

    auto builtId = static_cast<uint32_t>(func);
    builtins[builtId] = loadBuiltIn(builtin, builtinName);
}

void BuiltinFunctionsLibImpl::initBuiltinImageKernel(ImageBuiltin func) {
    const char *builtinName = nullptr;
    NEO::EBuiltInOps::Type builtin;

    switch (func) {
    case ImageBuiltin::copyBufferToImage3d16Bytes:
        builtinName = "CopyBufferToImage3d16Bytes";
        builtin = NEO::EBuiltInOps::copyBufferToImage3d;
        break;
    case ImageBuiltin::copyBufferToImage3d2Bytes:
        builtinName = "CopyBufferToImage3d2Bytes";
        builtin = NEO::EBuiltInOps::copyBufferToImage3d;
        break;
    case ImageBuiltin::copyBufferToImage3d4Bytes:
        builtinName = "CopyBufferToImage3d4Bytes";
        builtin = NEO::EBuiltInOps::copyBufferToImage3d;
        break;
    case ImageBuiltin::copyBufferToImage3d8Bytes:
        builtinName = "CopyBufferToImage3d8Bytes";
        builtin = NEO::EBuiltInOps::copyBufferToImage3d;
        break;
    case ImageBuiltin::copyBufferToImage3dBytes:
        builtinName = "CopyBufferToImage3dBytes";
        builtin = NEO::EBuiltInOps::copyBufferToImage3d;
        break;
    case ImageBuiltin::copyImage3dToBuffer16Bytes:
        builtinName = "CopyImage3dToBuffer16Bytes";
        builtin = NEO::EBuiltInOps::copyImage3dToBuffer;
        break;
    case ImageBuiltin::copyImage3dToBuffer2Bytes:
        builtinName = "CopyImage3dToBuffer2Bytes";
        builtin = NEO::EBuiltInOps::copyImage3dToBuffer;
        break;
    case ImageBuiltin::copyImage3dToBuffer4Bytes:
        builtinName = "CopyImage3dToBuffer4Bytes";
        builtin = NEO::EBuiltInOps::copyImage3dToBuffer;
        break;
    case ImageBuiltin::copyImage3dToBuffer8Bytes:
        builtinName = "CopyImage3dToBuffer8Bytes";
        builtin = NEO::EBuiltInOps::copyImage3dToBuffer;
        break;
    case ImageBuiltin::copyImage3dToBufferBytes:
        builtinName = "CopyImage3dToBufferBytes";
        builtin = NEO::EBuiltInOps::copyImage3dToBuffer;
        break;
    case ImageBuiltin::copyImageRegion:
        builtinName = "CopyImageToImage3d";
        builtin = NEO::EBuiltInOps::copyImageToImage3d;
        break;
    default:
        UNRECOVERABLE_IF(true);
    };

    auto builtId = static_cast<uint32_t>(func);
    imageBuiltins[builtId] = loadBuiltIn(builtin, builtinName);
}

BuiltinFunctionsLibImpl::BuiltinFunctionsLibImpl(Device *device, NEO::BuiltIns *builtInsLib) : device(device), builtInsLib(builtInsLib) {
    if (initBuiltinsAsyncEnabled(device)) {
        this->initAsyncComplete = false;
        this->initAsync = std::async(std::launch::async, &BuiltinFunctionsLibImpl::initBuiltinKernel, this, Builtin::fillBufferImmediate);
    }
}

Kernel *BuiltinFunctionsLibImpl::getFunction(Builtin func) {
    auto builtId = static_cast<uint32_t>(func);

    this->ensureInitCompletion();
    if (builtins[builtId].get() == nullptr) {
        initBuiltinKernel(func);
    }

    return builtins[builtId]->func.get();
}

Kernel *BuiltinFunctionsLibImpl::getImageFunction(ImageBuiltin func) {
    auto builtId = static_cast<uint32_t>(func);

    this->ensureInitCompletion();
    if (imageBuiltins[builtId].get() == nullptr) {
        initBuiltinImageKernel(func);
    }

    return imageBuiltins[builtId]->func.get();
}

std::unique_ptr<BuiltinFunctionsLibImpl::BuiltinData> BuiltinFunctionsLibImpl::loadBuiltIn(NEO::EBuiltInOps::Type builtin, const char *builtInName) {
    using BuiltInCodeType = NEO::BuiltinCode::ECodeType;

    if (!NEO::EmbeddedStorageRegistry::exists) {
        return nullptr;
    }

    StackVec<BuiltInCodeType, 2> supportedTypes{};
    if (!NEO::debugManager.flags.RebuildPrecompiledKernels.get()) {
        supportedTypes.push_back(BuiltInCodeType::binary);
    }
    supportedTypes.push_back(BuiltInCodeType::intermediate);

    NEO::BuiltinCode builtinCode{};

    for (auto &builtinCodeType : supportedTypes) {
        builtinCode = builtInsLib->getBuiltinsLib().getBuiltinCode(builtin, builtinCodeType, *device->getNEODevice());
        if (!builtinCode.resource.empty()) {
            break;
        }
    }

    if (builtinCode.resource.empty()) {
        return nullptr;
    }

    [[maybe_unused]] ze_result_t res;

    if (this->modules.size() <= builtin) {
        this->modules.resize(builtin + 1u);
    }

    if (this->modules[builtin].get() == nullptr) {
        std::unique_ptr<Module> module;
        ze_module_handle_t moduleHandle;
        ze_module_desc_t moduleDesc = {};
        moduleDesc.format = builtinCode.type == BuiltInCodeType::binary ? ZE_MODULE_FORMAT_NATIVE : ZE_MODULE_FORMAT_IL_SPIRV;
        moduleDesc.pInputModule = reinterpret_cast<uint8_t *>(&builtinCode.resource[0]);
        moduleDesc.inputSize = builtinCode.resource.size();
        res = device->createModule(&moduleDesc, &moduleHandle, nullptr, ModuleType::builtin);
        UNRECOVERABLE_IF(res != ZE_RESULT_SUCCESS);

        module.reset(Module::fromHandle(moduleHandle));
        this->modules[builtin] = std::move(module);
    }

    std::unique_ptr<Kernel> kernel;
    ze_kernel_handle_t kernelHandle;
    ze_kernel_desc_t kernelDesc = {};
    kernelDesc.pKernelName = builtInName;
    res = this->modules[builtin]->createKernel(&kernelDesc, &kernelHandle);
    DEBUG_BREAK_IF(res != ZE_RESULT_SUCCESS);

    kernel.reset(Kernel::fromHandle(kernelHandle));
    return std::unique_ptr<BuiltinData>(new BuiltinData{modules[builtin].get(), std::move(kernel)});
}

void BuiltinFunctionsLibImpl::ensureInitCompletion() {
    if (!this->initAsyncComplete) {
        this->initAsync.wait();
        this->initAsyncComplete = true;
    }
}

} // namespace L0
