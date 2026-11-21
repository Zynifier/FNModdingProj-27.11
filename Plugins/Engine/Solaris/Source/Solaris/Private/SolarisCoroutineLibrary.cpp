// Copyright Epic Games, Inc. All Rights Reserved.

#include "SolarisCoroutineLibrary.h"

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

void USolarisCoroutineLibrary::TaskCancel(UObject* Task)
{
}

void USolarisCoroutineLibrary::TaskFree(UObject* Task)
{
}

DEFINE_FUNCTION(USolarisCoroutineLibrary::execTaskGetReturnProperty)
{
	FortStub_SkipThunkParams(Stack, USolarisCoroutineLibrary::StaticClass()->FindFunctionByName(TEXT("TaskGetReturnProperty")));
}
void USolarisCoroutineLibrary::TaskGetReturnProperty(UObject* Task)
{
}

int64 USolarisCoroutineLibrary::TaskGetState(UObject* Task)
{
	return int64();
}

UObject* USolarisCoroutineLibrary::TaskMake(UClass* Type, UObject* Caller, int64 CallerResumeState, int64 CallerCancelState, UObject* OwnerInstance)
{
	return nullptr;
}
