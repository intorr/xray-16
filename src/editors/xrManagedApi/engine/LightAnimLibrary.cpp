#include "Pch.hpp"
#include "LightAnimLibrary.hpp"

#pragma unmanaged
#include "Common/FSMacros.hpp"
#include "xrEngine/LightAnimLibrary.h"
#define LANIM_VERSION 0x0001

#define CHUNK_VERSION 0x0000
#define CHUNK_ITEM_LIST 0x0001

#define CHUNK_ITEM_COMMON 0x0001
#define CHUNK_ITEM_KEYS 0x0002
#pragma managed

#include <msclr/marshal_cppstd.h>

namespace XRay
{
namespace ManagedApi
{
namespace Engine
{
namespace LightAnimLibrary
{
LightAnimItem::LightAnimItem()
{
    FPS = 15.f;
    FrameCount = 1;
}

void LightAnimItem::InitDefault()
{
    Keys[0] = 0x00000000;
}

void LightAnimItem::Load(Core::ReaderBase^ reader)
{
    R_ASSERT(reader->FindChunk(CHUNK_ITEM_COMMON, 0));
    reader->ReadStringZ(Name);
    FPS = reader->ReadFloat();
    FrameCount = reader->ReadUInt32();

    int key_cnt, key;
    R_ASSERT(reader->FindChunk(CHUNK_ITEM_KEYS, 0));
    key_cnt = reader->ReadUInt32();
    for (int i = 0; i<key_cnt; i++)
    {
        key = reader->ReadUInt32();
        Keys[key] = reader->ReadUInt32();
    }
}

void LightAnimItem::Save(Core::WriterBase^ writer)
{
    writer->OpenChunk(CHUNK_ITEM_COMMON);
    writer->WriteStringZ(Name);
    writer->WriteFloat(FPS);
    writer->WriteUInt32(FrameCount);
    writer->CloseChunk();

    writer->OpenChunk(CHUNK_ITEM_KEYS);
    writer->WriteUInt32(Keys.size());

    for (auto it = Keys.begin(); it!=Keys.end(); ++it)
    {
        writer->WriteUInt32(it->first);
        writer->WriteUInt32(it->second);
    }

    writer->CloseChunk();
}

float LightAnimItem::Length_sec()
{
    return float(FrameCount)/FPS;
}

UInt32 LightAnimItem::Length_ms()
{
    return iFloor(Length_sec() * 1000.f);
    return 0;
}

UInt32 LightAnimItem::InterpolateRGB(int frame)
{
    R_ASSERT(frame<=FrameCount);

    auto A = Keys.find(frame);
    auto B = Keys.end();
    if (A!=Keys.end()) // ключ - возвращаем цвет ключа
        return A->second;
    else // не ключ
    {
        B = Keys.upper_bound(frame); // ищем следующий ключ
        if (B==Keys.end()) // если его нет вернем цвет последнего ключа
        {
            --B;
            return B->second;
        }
        A = B; // иначе в A занесем предыдущий ключ
        --A;
    }

    R_ASSERT(Keys.size()>1);
    // интерполируем цвет
    Fcolor c, c0, c1;
    float a0 = static_cast<float>(A->first);
    float a1 = static_cast<float>(B->first);
    c0.set(A->second);
    c1.set(B->second);
    float t = float(frame-a0)/float(a1-a0);
    c.lerp(c0, c1, t);
    return c.get();
}

UInt32 LightAnimItem::InterpolateBGR(int frame)
{
    u32 c = InterpolateRGB(frame);
    return color_rgba(color_get_B(c), color_get_G(c), color_get_R(c), color_get_A(c));

}

UInt32 LightAnimItem::CalculateRGB(float T, int& frame)
{
    frame = iFloor(fmodf(T, float(FrameCount)/FPS) * FPS);
    return InterpolateRGB(frame);
}

UInt32 LightAnimItem::CalculateBGR(float T, int& frame)
{
    frame = iFloor(fmodf(T, float(FrameCount)/FPS) * FPS);
    return InterpolateBGR(frame);
}

void LightAnimItem::Resize(int new_len)
{
    VERIFY((new_len>=1));
    if (new_len!=FrameCount)
    {
        if (new_len>FrameCount)
        {
            int old_len = FrameCount;
            FrameCount = new_len;
            MoveKey(old_len, new_len);
        }
        else
        {
            auto I = Keys.upper_bound(new_len-1);
            if (I!=Keys.end())
                Keys.erase(I, Keys.end());
            FrameCount = new_len;
        }
    }
}

void LightAnimItem::InsertKey(int frame, UInt32 color)
{
    R_ASSERT(frame<=FrameCount);
    Keys[frame] = color;
}

void LightAnimItem::DeleteKey(int frame)
{
    R_ASSERT(frame<=FrameCount);
    if (frame==0)
        return;
    auto it = Keys.find(frame);
    if (it!=Keys.end())
        Keys.erase(it);
}

void LightAnimItem::MoveKey(int from, int to)
{
    R_ASSERT(from<=FrameCount);
    R_ASSERT(to<=FrameCount);
    auto it = Keys.find(from);
    if (it!=Keys.end())
    {
        Keys[to] = it->second;
        Keys.erase(it);
    }
}

bool LightAnimItem::IsKey(int frame)
{
    return Keys.end()!=Keys.find(frame);
}

int LightAnimItem::PrevKeyFrame(int frame)
{
    auto A = Keys.lower_bound(frame);
    if (A!=Keys.end())
    {
        auto B = A;
        B--;
        if (B!=Keys.end())
            return B->first;
        return A->first;
    }
    return Keys.rbegin()->first;
}

int LightAnimItem::NextKeyFrame(int frame)
{
    auto A = Keys.upper_bound(frame);
    if (A!=Keys.end())
    {
        return A->first;
    }
    return Keys.rbegin()->first;
}

int LightAnimItem::FirstKeyFrame()
{
    return Keys.rend()->first;
}

int LightAnimItem::LastKeyFrame()
{
    return Keys.rbegin()->first;
}

UInt32 LightAnimItem::GetKey(int frame)
{
    auto it = Keys.find(frame);
    return it!=Keys.end() ? it->second : 0;
}

LightAnimItem^ LightAnimLibrary::FindItem(String^ name)
{
    if (name && name[0])
        for each (auto item in Items)
            if (String::Compare(item->Name, name)==0)
                return item;
    return nullptr;
}

LightAnimLibrary::LightAnimLibrary()
{

}

LightAnimLibrary::~LightAnimLibrary()
{

}

void LightAnimLibrary::RemoveObject(String^ fname, EItemType type, bool& res)
{

}

void LightAnimLibrary::RenameObject(String^ fn0, String^ fn1, EItemType type)
{

}

void LightAnimLibrary::OnCreate()
{
    Load();
}

void LightAnimLibrary::OnDestroy()
{
    Unload();
}

void LightAnimLibrary::Load()
{

    string_path fn;
    FS.update_path(fn, _game_data_, "lanims.xr");
    Core::ReaderBase^ fs = gcnew Core::ReaderBase(FS.r_open(fn));
    if (fs)
    {
        u16 version = 0;
        if (fs->FindChunk(CHUNK_VERSION, 0))
        {
            version = fs->ReadUInt16();
        }
        Core::ReaderBase^ OBJ = fs->OpenChunk(CHUNK_ITEM_LIST);
        if (OBJ)
        {
            Core::ReaderBase^ O = OBJ->OpenChunk(0);
            for (int count = 1; O && O->impl; ++count)
            {
                LightAnimItem^ I = gcnew LightAnimItem();
                I->Load(O);
                if (version==0)
                {
                    for (auto it = I->Keys.begin(); it!=I->Keys.end(); it++)
                        it->second = subst_alpha(bgr2rgb(it->second), color_get_A(it->second));
                }
                Items.Add(I);
                O->Close();
                O = OBJ->OpenChunk(count);
            }
            OBJ->Close();
        }
    }
}

void LightAnimLibrary::Save()
{

}

void LightAnimLibrary::Reload()
{
    Unload();
    Load();
}

void LightAnimLibrary::Unload()
{
    Items.Clear();
}

LightAnimItem^ LightAnimLibrary::AppendItem(String^ name, LightAnimItem^ src)
{
    VERIFY2(FindItem(name) == nullptr, "Duplicate name found.");
    LightAnimItem^ item = gcnew LightAnimItem();
    if (src)
        item = src;
    else
        item->InitDefault();
    item->Name = name;
    Items.Add(item);
    return item;
}

array<LightAnimItem^>^ LightAnimLibrary::Objects()
{
    return Items.ToArray();
}
}
}
}
}