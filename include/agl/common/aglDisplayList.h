#pragma once

#include <heap/seadHeap.h>

namespace agl {

class DisplayList
{
public:
#ifdef cafe
    static const u32 cDisplayListAlignment = 0x20;
#else
    static const u32 cDisplayListAlignment = 4;
#endif

public:
    DisplayList();
    virtual ~DisplayList();

    u8* getBuffer() const
    {
        return mpBuffer;
    }

    void setBuffer(u8* buffer, size_t size);
    void clear();

    bool beginDisplayList();
    size_t endDisplayList();

    bool beginDisplayListBuffer(u8* buffer, size_t size);
    size_t endDisplayListBuffer(sead::Heap* heap);

    bool beginDisplayListTemporary(size_t size);
    size_t endDisplayListTemporary(sead::Heap* heap);

    static size_t suspend(void** p_dl);
    static void resume(void* dl, size_t size);

private:
    u8* mpBuffer;
    size_t mSize;
    size_t mValidSize;
};
static_assert(sizeof(DisplayList) == 0x10, "agl::DisplayList size mismatch");

}