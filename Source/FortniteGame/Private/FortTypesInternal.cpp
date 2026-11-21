// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTypesInternal.h"

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

DEFINE_FUNCTION(UFortChangeMonitoringStructHelpers::execCheckIsDirty)
{
	FortStub_SkipThunkParams(Stack, UFortChangeMonitoringStructHelpers::StaticClass()->FindFunctionByName(TEXT("CheckIsDirty")));
}
void UFortChangeMonitoringStructHelpers::CheckIsDirty(const FFortChangeMonitoringStruct& CheckStruct, EChangeInStructDetected& ChangeState)
{
}

DEFINE_FUNCTION(UFortChangeMonitoringStructHelpers::execClearDirty)
{
	FortStub_SkipThunkParams(Stack, UFortChangeMonitoringStructHelpers::StaticClass()->FindFunctionByName(TEXT("ClearDirty")));
}
void UFortChangeMonitoringStructHelpers::ClearDirty(FFortChangeMonitoringStruct& CheckStruct, EChangeInStructDetected& ChangeState)
{
}

FText UFortInventorySortFunctionLibrary::GetCriterionDisplayNameOfSortType(EInventoryContentSortType SortType)
{
	return FText();
}
