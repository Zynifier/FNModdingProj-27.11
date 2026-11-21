// Copyright Epic Games, Inc. All Rights Reserved.

#include "SolarisWeakMapLibrary.h"
#include "UObject/Class.h"

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

bool FGenericKeyType::operator==(const FGenericKeyType& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FGenericKeyType& Value)
{
	return 0;
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execCall)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("Call")));
}
void USolarisWeakMapLibrary::Call(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key)
{
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execCompletelyAssignedPersistentVarRefCall)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("CompletelyAssignedPersistentVarRefCall")));
}
void USolarisWeakMapLibrary::CompletelyAssignedPersistentVarRefCall(const FString& Path, const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key)
{
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execCompletelyAssignedRefCall)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("CompletelyAssignedRefCall")));
}
void USolarisWeakMapLibrary::CompletelyAssignedRefCall(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key)
{
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execFitsInPlayerMap)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("FitsInPlayerMap")));
}
void USolarisWeakMapLibrary::FitsInPlayerMap(FGenericValueType Value)
{
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execPersistentVarCall)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("PersistentVarCall")));
}
void USolarisWeakMapLibrary::PersistentVarCall(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key)
{
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execPersistentVarRefCall)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("PersistentVarRefCall")));
}
void USolarisWeakMapLibrary::PersistentVarRefCall(const FString& Path, const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key)
{
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execRefCall)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("RefCall")));
}
void USolarisWeakMapLibrary::RefCall(const TMap<FGenericKeyType, FGenericValueType>& Map, FGenericKeyType Key)
{
}

DEFINE_FUNCTION(USolarisWeakMapLibrary::execType)
{
	FortStub_SkipThunkParams(Stack, USolarisWeakMapLibrary::StaticClass()->FindFunctionByName(TEXT("Type")));
}
void USolarisWeakMapLibrary::Type(UClass* KeyType, UClass* ValueType)
{
}
