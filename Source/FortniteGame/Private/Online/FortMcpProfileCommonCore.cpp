// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMcpProfileCommonCore.h"

#ifndef FORTSTUB_SKIP_THUNK_PARAMS
#define FORTSTUB_SKIP_THUNK_PARAMS
static void FortStub_SkipThunkParams(FFrame& Stack, UFunction* Function)
{
	if (Function)
	{
		for (TFieldIterator<FProperty> It(Function); It && It->HasAnyPropertyFlags(CPF_Parm); ++It)
		{
			if (It->HasAnyPropertyFlags(CPF_ReturnParm))
			{
				continue;
			}
			void* Temp = FMemory::Malloc(It->GetSize(), It->GetMinAlignment());
			It->InitializeValue(Temp);
			Stack.StepCompiledIn(Temp, It->GetClass());
			It->DestroyValue(Temp);
			FMemory::Free(Temp);
		}
	}
	P_FINISH;
}
#endif

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execCancelOrResumeSubscription)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("CancelOrResumeSubscription")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execClaimImportFriendsReward)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("ClaimImportFriendsReward")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execClaimMfaEnabled)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("ClaimMfaEnabled")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execClearUndoTimeoutForPurchase)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("ClearUndoTimeoutForPurchase")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execCompletePlayerSurvey)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("CompletePlayerSurvey")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execIssueFriendCode)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("IssueFriendCode")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execPurchaseCatalogEntry)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("PurchaseCatalogEntry")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execPurchaseMultipleCatalogEntries)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("PurchaseMultipleCatalogEntries")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execRefundMtxPurchase)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("RefundMtxPurchase")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execSetAffiliateName)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("SetAffiliateName")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execSetForcedIntroPlayed)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("SetForcedIntroPlayed")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execSetMatchmakingBansViewed)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("SetMatchmakingBansViewed")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execSetMtxPlatform)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("SetMtxPlatform")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonCore::execSetReceiveGiftsEnabled)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonCore::StaticClass()->FindFunctionByName(TEXT("SetReceiveGiftsEnabled")));
}
