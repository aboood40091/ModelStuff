#pragma once

#include <heap/seadDisposer.h>
#include <prim/seadSafeString.h>

#include <agl/aglShaderProgramArchive.h>

class ShaderHolder
{
    SEAD_SINGLETON_DISPOSER(ShaderHolder)

public:
    ShaderHolder();

    agl::ShaderProgramArchive* getGlobalShaderArchive(const sead::SafeString& filename);
};