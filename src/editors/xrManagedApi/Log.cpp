#include "Pch.hpp"
#include "Log.hpp"

#pragma unmanaged
#include "xrCore/log.h"
#pragma managed

#include <msclr/marshal_cppstd.h>

namespace XRay
{
namespace ManagedApi
{
namespace Core
{
namespace Log
{
// Usage: Msg(L"{0} {1} {2}.", 40.5, "hello", DateTime::Now);
void Logger::Msg(String^ format, ...array<Object^>^ args)
{
    Log(String::Format(format, args));
}

void Logger::Log(String^ msg)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    ::Log(msgC.c_str());
}

void Logger::Log(String^ msg, String^ dop)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    std::string dopC = msclr::interop::marshal_as<std::string>(dop);
    ::Log(msgC.c_str(), dopC.c_str());
}

void Logger::Log(String^ msg, UInt32 dop)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    ::Log(msgC.c_str(), dop);
}

void Logger::Log(String^ msg, int dop)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    ::Log(msgC.c_str(), dop);
}

void Logger::Log(String^ msg, float dop)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    ::Log(msgC.c_str(), dop);
}

void Logger::Log(String^ msg, Core::Vector3F dop)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    ::Log(msgC.c_str(), dop.ToEngine());
}

void Logger::Log(String^ msg, Core::MatrixF dop)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    ::Log(msgC.c_str(), dop.ToEngine());
}

void Logger::LogWinErr(String^ msg, long err_code)
{
    std::string msgC = msclr::interop::marshal_as<std::string>(msg);
    ::LogWinErr(msgC.c_str(), err_code);
}
}
}
}
}