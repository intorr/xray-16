#pragma once

#define ENGINE_API
#define ECORE_API
#define XR_EPROPS_API

#include "Common/Common.hpp"
#include "xrCore/xrCore.h"

#include <d3dx9.h>
#include "Common/_d3d_extensions.h"

#include "utils/xrLCUtil/LevelCompilerLoggerWindow.hpp"
#include "utils/xrLCUtil/xrThread.hpp"

extern LevelCompilerLoggerWindow& Logger;
extern CThread::LogFunc ProxyMsg;
extern CThreadManager::ReportStatusFunc ProxyStatus;
extern CThreadManager::ReportProgressFunc ProxyProgress;

#ifdef AI_COMPILER
#include "xrServerEntities/smart_cast.h"
#endif

// Used in:
// src\xrServerEntities\xrServer_Objects_ALife_Items.cpp
// src\xrServerEntities\xrServer_Objects_ALife_Monsters.cpp
#define READ_IF_EXISTS(ltx, method, section, name, default_value)\
    (ltx->line_exist(section, name)) ? ltx->method(section, name) : default_value
