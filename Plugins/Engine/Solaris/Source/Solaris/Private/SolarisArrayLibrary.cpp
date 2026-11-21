// Copyright Epic Games, Inc. All Rights Reserved.

#include "SolarisArrayLibrary.h"

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

DEFINE_FUNCTION(USolarisArrayLibrary::execAdd)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("Add")));
}
int64 USolarisArrayLibrary::Add(const TArray<FGenericElementType>& array, const FGenericElementType& new_item)
{
	return int64();
}

DEFINE_FUNCTION(USolarisArrayLibrary::execCall)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("Call")));
}
void USolarisArrayLibrary::Call(const TArray<FGenericElementType>& Array, int64 Index)
{
}

DEFINE_FUNCTION(USolarisArrayLibrary::execConcat)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("Concat")));
}
TArray<FGenericElementType> USolarisArrayLibrary::Concat(const TArray<FGenericElementType>& Lhs, const TArray<FGenericElementType>& Rhs)
{
	return TArray<FGenericElementType>();
}

DEFINE_FUNCTION(USolarisArrayLibrary::execConcatEquals)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("ConcatEquals")));
}
TArray<FGenericElementType> USolarisArrayLibrary::ConcatEquals(TArray<FGenericElementType>& Lhs, const TArray<FGenericElementType>& Rhs)
{
	return TArray<FGenericElementType>();
}

DEFINE_FUNCTION(USolarisArrayLibrary::execEmpty)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("Empty")));
}
void USolarisArrayLibrary::Empty(const TArray<FGenericElementType>& array)
{
}

DEFINE_FUNCTION(USolarisArrayLibrary::execLength)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("Length")));
}
int64 USolarisArrayLibrary::Length(const TArray<FGenericElementType>& array)
{
	return int64();
}

DEFINE_FUNCTION(USolarisArrayLibrary::execMove)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("Move")));
}
void USolarisArrayLibrary::Move(const TArray<FGenericElementType>& Target, const TArray<FGenericElementType>& Source)
{
}

DEFINE_FUNCTION(USolarisArrayLibrary::execRefCall)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("RefCall")));
}
void USolarisArrayLibrary::RefCall(const TArray<FGenericElementType>& Array, int64 Index)
{
}

DEFINE_FUNCTION(USolarisArrayLibrary::execUnsafeCall)
{
	FortStub_SkipThunkParams(Stack, USolarisArrayLibrary::StaticClass()->FindFunctionByName(TEXT("UnsafeCall")));
}
void USolarisArrayLibrary::UnsafeCall(const TArray<FGenericElementType>& Array, int64 Index)
{
}
