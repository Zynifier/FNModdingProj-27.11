// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoverTypes.h"

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

DEFINE_FUNCTION(UMoverDataCollectionLibrary::execK2_AddDataToCollection)
{
	FortStub_SkipThunkParams(Stack, UMoverDataCollectionLibrary::StaticClass()->FindFunctionByName(TEXT("K2_AddDataToCollection")));
}
void UMoverDataCollectionLibrary::K2_AddDataToCollection(FMoverDataCollection& Collection, const int32& SourceAsRawBytes)
{
}

DEFINE_FUNCTION(UMoverDataCollectionLibrary::execK2_GetDataFromCollection)
{
	FortStub_SkipThunkParams(Stack, UMoverDataCollectionLibrary::StaticClass()->FindFunctionByName(TEXT("K2_GetDataFromCollection")));
}
void UMoverDataCollectionLibrary::K2_GetDataFromCollection(bool& DidSucceed, const FMoverDataCollection& Collection, int32& TargetAsRawBytes)
{
}
