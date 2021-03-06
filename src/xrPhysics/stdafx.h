#pragma once

#include "Common/Common.hpp"

#define MTL_EXPORT_API
#define ECORE_API

#include "xrCore/xrCore.h"

#include "xrServerEntities/smart_cast.h"

#include "xrCDB/xrCDB.h"
#include "xrSound/sound.h"

#include "xrPhysics.h"

#ifdef DEBUG
#include "d3d9types.h"
#endif
// IC IGame_Level &GLevel()
//{
//	VERIFY( g_pGameLevel );
//	return *g_pGameLevel;
//}
class CGameMtlLibrary;
IC CGameMtlLibrary& GMLibrary()
{
    VERIFY(GEnv.PGMLib);
    return *GEnv.PGMLib;
}
