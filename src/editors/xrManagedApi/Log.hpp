#pragma once

#include "Core/Types.hpp"
using namespace System;

namespace XRay
{
namespace ManagedApi
{
namespace Core
{
namespace Log
{
public ref class Logger abstract sealed
{
public:
    static void Msg(String^ format, ...array<Object^>^ args);
    static void Log(String^ msg);
    static void Log(String^ msg, String^ dop);
    static void Log(String^ msg, UInt32 dop);
    static void Log(String^ msg, int dop);
    static void Log(String^ msg, float dop);
    
    static void Log(String^ msg, Core::Vector3F dop);
    static void Log(String^ msg, Core::MatrixF dop);
    static void LogWinErr(String^ msg, long err_code);
};
}
}
}
}