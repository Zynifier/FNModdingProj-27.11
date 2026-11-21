// Copyright Epic Games, Inc. All Rights Reserved.

#include "SolarisMapLibrary.h"

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

DEFINE_FUNCTION(USolarisMapLibrary::execAdd)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("Add")));
}
void USolarisMapLibrary::Add(const TMap<FGenericKeyType, FGenericValueType>& Map, const FGenericKeyType& Key, const FGenericValueType& Value)
{
}

DEFINE_FUNCTION(USolarisMapLibrary::execConcat)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("Concat")));
}
TMap<FGenericKeyType, FGenericValueType> USolarisMapLibrary::Concat(const TMap<FGenericKeyType, FGenericValueType>& LHS, const TMap<FGenericKeyType, FGenericValueType>& RHS)
{
	return TMap<FGenericKeyType, FGenericValueType>();
}

DEFINE_FUNCTION(USolarisMapLibrary::execGetKeyByIndex)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("GetKeyByIndex")));
}
FGenericKeyType USolarisMapLibrary::GetKeyByIndex(const TMap<FGenericKeyType, FGenericValueType>& Map, int64 Index)
{
	return FGenericKeyType();
}

DEFINE_FUNCTION(USolarisMapLibrary::execGetNextValidIndex)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("GetNextValidIndex")));
}
int64 USolarisMapLibrary::GetNextValidIndex(const TMap<FGenericKeyType, FGenericValueType>& Map, int64 InitialIndex)
{
	return int64();
}

DEFINE_FUNCTION(USolarisMapLibrary::execGetValueByIndex)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("GetValueByIndex")));
}
FGenericValueType USolarisMapLibrary::GetValueByIndex(const TMap<FGenericKeyType, FGenericValueType>& Map, int64 Index)
{
	return FGenericValueType();
}

DEFINE_FUNCTION(USolarisMapLibrary::execInitMap)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("InitMap")));
}
void USolarisMapLibrary::InitMap(TMap<FGenericKeyType, FGenericValueType>& Map)
{
}

DEFINE_FUNCTION(USolarisMapLibrary::execLength)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("Length")));
}
int64 USolarisMapLibrary::Length(const TMap<FGenericKeyType, FGenericValueType>& Map)
{
	return int64();
}

DEFINE_FUNCTION(USolarisMapLibrary::execMove)
{
	FortStub_SkipThunkParams(Stack, USolarisMapLibrary::StaticClass()->FindFunctionByName(TEXT("Move")));
}
void USolarisMapLibrary::Move(TMap<FGenericKeyType, FGenericValueType>& Dest, const TMap<FGenericKeyType, FGenericValueType>& Src)
{
}
