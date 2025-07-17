#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

RECOMP_IMPORT(".", int native_lib_test(const char* str));

// Disable enemy bgm
ActorContext* gActorCtx;
RECOMP_HOOK ("Attention_FindActorInCategory") void on_Attention_FindActorInCategory(PlayState* play, ActorContext* actorCtx, Player* player, ActorType actorCategory) {
    gActorCtx = actorCtx;	// Grab actorCtx from Attention_FindActorInCategory()
}

RECOMP_HOOK_RETURN ("Attention_FindActorInCategory") void return_Attention_FindActorInCategory(void) {
    gActorCtx->attention.bgmEnemy = NULL;	// Set bgmEnemy from "actor" to "NULL"
}