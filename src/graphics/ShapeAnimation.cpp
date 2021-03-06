#define override
#include <graphics/ModelNW.h>
#include <graphics/ShapeAnimation.h>

void ShapeAnimation::bindModel(const ModelNW* p_model, s32 index)
{
    if (mpModel)
        unbindModel();

    mpModel = p_model;
    mIndex = index;

    if (mpRes)
        bindAnimObj_();
}

void ShapeAnimation::unbindModel()
{
    mpModel = NULL;
    mIndex = -1;
}

void ShapeAnimation::bindAnimObj_()
{
    if (mpRes)
    {
        mAnimObj.Bind(mpModel->getModelEx().GetResource());
        mAnimObj.ClearResult();
    }
}
