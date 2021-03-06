#pragma once

#include <graphics/ModelEnvView.h>

#include <common/aglTextureSampler.h>
#include <container/seadBuffer.h>
#include <container/seadListImpl.h>
#include <container/seadPtrArray.h>
#include <heap/seadDisposer.h>
#include <math/seadMatrix.h>
#include <prim/seadNamable.h>

class CullViewFrustum;
class RenderObj;
class RenderObjBaseLayer;

class RenderMgr : public sead::IDisposer, public sead::INamable
{
public:
    struct ViewInfo
    {
        RenderObjBaseLayer* layer;
        sead::Matrix34f view_mtx;
        sead::Matrix44f proj_mtx;
        sead::Matrix44f* _74;
        CullViewFrustum* p_cull;
        void* _7c; // pointer to struct of two f32 and one sead::Color4f for fog color
    };
    static_assert(sizeof(ViewInfo) == 0x80, "RenderMgr::ViewInfo size mismatch");

public:
    const ModelEnvView& getModelEnvView() const { return mModelEnvView; }

    agl::TextureSampler* getShadowMap() const { return mShadowMap; }
    agl::TextureSampler* getReflectionMap() const { return mReflectionMap; }

    ViewInfo& getViewInfo(s32 view_index) { return mViewInfo[view_index]; }
    const ViewInfo& getViewInfo(s32 view_index) const { return mViewInfo[view_index]; }

private:
    u8 _18;
    sead::PtrArray<RenderObj> mRenderObj;
    sead::Buffer< sead::PtrArray<RenderObj> > mRenderObjOpa;
    sead::Buffer< sead::PtrArray<RenderObj> > mRenderObjXlu;
    sead::PtrArray<RenderObj> mRenderObjShadow;
    u32 mEnvObjMgr[0x464 / sizeof(u32)]; // agl::env::EnvObjMgr
    ModelEnvView mModelEnvView;
    void* _4b4;
    bool mDrawShadow; // I think
    agl::TextureSampler* mShadowMap;
    agl::TextureSampler* mReflectionMap;
    sead::Buffer<ViewInfo> mViewInfo;
    sead::ListNode mNode; // For sead::OffsetList in LayerMgr
};
static_assert(sizeof(RenderMgr) == 0x4D4, "RenderMgr size mismatch");
