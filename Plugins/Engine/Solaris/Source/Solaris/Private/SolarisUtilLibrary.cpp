// Copyright Epic Games, Inc. All Rights Reserved.

#include "SolarisUtilLibrary.h"

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

DEFINE_FUNCTION(USolarisUtilLibrary::execAddPropertyToSubobjectExclusionList)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("AddPropertyToSubobjectExclusionList")));
}
void USolarisUtilLibrary::AddPropertyToSubobjectExclusionList(int64 InstancingGraph, int64 Property)
{
}

DEFINE_FUNCTION(USolarisUtilLibrary::execAddressof)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("Addressof")));
}
int64 USolarisUtilLibrary::Addressof(int64 value)
{
	return int64();
}

DEFINE_FUNCTION(USolarisUtilLibrary::execCallFinalFunctionWithContext)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("CallFinalFunctionWithContext")));
}
void USolarisUtilLibrary::CallFinalFunctionWithContext()
{
}

DEFINE_FUNCTION(USolarisUtilLibrary::execCallFunction)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("CallFunction")));
}
void USolarisUtilLibrary::CallFunction()
{
}

DEFINE_FUNCTION(USolarisUtilLibrary::execDereference)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("Dereference")));
}
int64 USolarisUtilLibrary::Dereference(int64 reference)
{
	return int64();
}

UObject* USolarisUtilLibrary::GetCurrentlyInstantiatedObject()
{
	return nullptr;
}

DEFINE_FUNCTION(USolarisUtilLibrary::execGetFunctionForInterfaceMethod)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("GetFunctionForInterfaceMethod")));
}
void USolarisUtilLibrary::GetFunctionForInterfaceMethod(UObject* Object, FName MethodName)
{
}

DEFINE_FUNCTION(USolarisUtilLibrary::execGetOptionValue)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("GetOptionValue")));
}
int64 USolarisUtilLibrary::GetOptionValue(int64 option)
{
	return int64();
}

DEFINE_FUNCTION(USolarisUtilLibrary::execHasInterface)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("HasInterface")));
}
bool USolarisUtilLibrary::HasInterface(UObject* Object, UClass* InterfaceClass)
{
	return false;
}

DEFINE_FUNCTION(USolarisUtilLibrary::execInstanceFunction)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("InstanceFunction")));
}
void USolarisUtilLibrary::InstanceFunction(UObject* Object, FName MethodName)
{
}

DEFINE_FUNCTION(USolarisUtilLibrary::execInstantiateObject)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("InstantiateObject")));
}
void USolarisUtilLibrary::InstantiateObject(UClass* Class, int64 InstancingGraph)
{
}

DEFINE_FUNCTION(USolarisUtilLibrary::execIsNonNullObject)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("IsNonNullObject")));
}
bool USolarisUtilLibrary::IsNonNullObject(UObject* Object)
{
	return false;
}

DEFINE_FUNCTION(USolarisUtilLibrary::execIsOptionSet)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("IsOptionSet")));
}
bool USolarisUtilLibrary::IsOptionSet(int64 option)
{
	return false;
}

DEFINE_FUNCTION(USolarisUtilLibrary::execMakeOptionFromValue)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("MakeOptionFromValue")));
}
bool USolarisUtilLibrary::MakeOptionFromValue(UObject* property, int64 value)
{
	return false;
}

DEFINE_FUNCTION(USolarisUtilLibrary::execMakeUnsetOption)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("MakeUnsetOption")));
}
int64 USolarisUtilLibrary::MakeUnsetOption()
{
	return int64();
}

DEFINE_FUNCTION(USolarisUtilLibrary::execObjectHasNoFlags)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("ObjectHasNoFlags")));
}
bool USolarisUtilLibrary::ObjectHasNoFlags(UObject* Object, int32 Flags)
{
	return false;
}

DEFINE_FUNCTION(USolarisUtilLibrary::execReferenceIsValid)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("ReferenceIsValid")));
}
bool USolarisUtilLibrary::ReferenceIsValid(int64 reference)
{
	return false;
}

DEFINE_FUNCTION(USolarisUtilLibrary::execReplaceOptionValue)
{
	FortStub_SkipThunkParams(Stack, USolarisUtilLibrary::StaticClass()->FindFunctionByName(TEXT("ReplaceOptionValue")));
}
int64 USolarisUtilLibrary::ReplaceOptionValue(int64 ResultProperty, int64 Option, int64 Value)
{
	return int64();
}
