// Copyright Epic Games, Inc. All Rights Reserved.

#include "VerseDynamicallyTypedValueLibrary.h"

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

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execConvertFromDynamicallyTypedValue)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("ConvertFromDynamicallyTypedValue")));
}
void UVerseDynamicallyTypedValueLibrary::ConvertFromDynamicallyTypedValue(int32 RuntimeType, int32 Value)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execConvertToDynamicallyTypedValue)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("ConvertToDynamicallyTypedValue")));
}
void UVerseDynamicallyTypedValueLibrary::ConvertToDynamicallyTypedValue(int32 RuntimeType, int32 Value)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execEqual)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("Equal")));
}
void UVerseDynamicallyTypedValueLibrary::Equal(int32 Left, int32 Right)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeArray)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeArray")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeArray(int32 ElementType)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeChar32)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeChar32")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeChar32()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeChar8)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeChar8")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeChar8()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeClass)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeClass")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeClass()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeDynamic)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeDynamic")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeDynamic()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeEnum)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeEnum")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeEnum(FName Name)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeFloat)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeFloat")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeFloat()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeFunction)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeFunction")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeFunction()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeInt64)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeInt64")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeInt64()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeLogic)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeLogic")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeLogic()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeMap)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeMap")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeMap(int32 KeyType, int32 ValueType)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeObject)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeObject")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeObject()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeOption)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeOption")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeOption(int32 ValueType)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeString)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeString")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeString()
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeStruct)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeStruct")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeStruct(UObject* Struct)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execMakeRuntimeTypeTuple)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("MakeRuntimeTypeTuple")));
}
void UVerseDynamicallyTypedValueLibrary::MakeRuntimeTypeTuple(TArray<int32> ValueType)
{
}

DEFINE_FUNCTION(UVerseDynamicallyTypedValueLibrary::execNotEqual)
{
	FortStub_SkipThunkParams(Stack, UVerseDynamicallyTypedValueLibrary::StaticClass()->FindFunctionByName(TEXT("NotEqual")));
}
void UVerseDynamicallyTypedValueLibrary::NotEqual(int32 Left, int32 Right)
{
}
