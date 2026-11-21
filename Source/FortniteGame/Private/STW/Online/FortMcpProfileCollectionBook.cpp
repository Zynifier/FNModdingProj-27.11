// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Online/FortMcpProfileCollectionBook.h"

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

DEFINE_FUNCTION(UFortMcpProfileCollectionBook::execClaimCollectionBookPageRewards)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCollectionBook::StaticClass()->FindFunctionByName(TEXT("ClaimCollectionBookPageRewards")));
}

DEFINE_FUNCTION(UFortMcpProfileCollectionBook::execConvertSlottedItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCollectionBook::StaticClass()->FindFunctionByName(TEXT("ConvertSlottedItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCollectionBook::execPromoteItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCollectionBook::StaticClass()->FindFunctionByName(TEXT("PromoteItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCollectionBook::execUpgradeSlottedItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCollectionBook::StaticClass()->FindFunctionByName(TEXT("UpgradeSlottedItem")));
}
