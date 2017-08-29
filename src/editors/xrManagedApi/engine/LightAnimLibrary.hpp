#pragma once

#include <cliext/map>

#include "Core/fs/FS.hpp"

using namespace System;
using namespace System::Collections::Generic;

namespace XRay
{
namespace ManagedApi
{
namespace Engine
{
namespace LightAnimLibrary
{
// XXX: move from here
enum EItemType
{
    TYPE_INVALID = -1,
    TYPE_FOLDER = 0,
    TYPE_OBJECT = 1
};

public ref class LightAnimItem
{
public:
    String^ Name;
    float FPS;
    int FrameCount;
    cliext::map<int, UInt32> Keys;

    LightAnimItem();

    void InitDefault();
    void Load(Core::ReaderBase^ reader);
    void Save(Core::WriterBase^ writer);
    float Length_sec();
    UInt32 Length_ms();
    UInt32 InterpolateRGB(int frame);
    UInt32 InterpolateBGR(int frame);
    UInt32 CalculateRGB(float T, int& frame);
    UInt32 CalculateBGR(float T, int& frame);
    void Resize(int new_len);
    void InsertKey(int frame, UInt32 color);
    void DeleteKey(int frame);
    void MoveKey(int from, int to);
    bool IsKey(int frame);
    int PrevKeyFrame(int frame);
    int NextKeyFrame(int frame);
    int FirstKeyFrame();
    int LastKeyFrame();
    UInt32 GetKey(int frame);
};

public ref class LightAnimLibrary
{
    
public:
    
    List<LightAnimItem^> Items;

    LightAnimItem^ FindItem(String^ name);

    LightAnimLibrary();
    ~LightAnimLibrary();

    void RemoveObject(String^ fname, EItemType type, bool& res);
    void RenameObject(String^ fn0, String^ fn1, EItemType type);

    void OnCreate();
    void OnDestroy();
    void Load();
    void Save();
    void Reload();
    void Unload();
    LightAnimItem^ AppendItem(String^ name, LightAnimItem^ src);
    array<LightAnimItem^>^ Objects();
};
}
}
}
}