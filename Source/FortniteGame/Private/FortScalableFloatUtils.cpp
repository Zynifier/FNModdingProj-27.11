// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortScalableFloatUtils.h"

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

float UFortScalableFloatUtils::GetValue(const FScalableFloat& Input)
{
	return float();
}

bool UFortScalableFloatUtils::GetValueAsBool(const FScalableFloat& Input, float Level)
{
	return false;
}

bool UFortScalableFloatUtils::GetValueAsBoolWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, float Level)
{
	return false;
}

bool UFortScalableFloatUtils::GetValueAsBoolWithContextParam(const UObject* WorldContextObject, const FScalableFloat& Input, float Level)
{
	return false;
}

int32 UFortScalableFloatUtils::GetValueAsInteger(const FScalableFloat& Input, float Level)
{
	return int32();
}

int32 UFortScalableFloatUtils::GetValueAsIntegerWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, float Level)
{
	return int32();
}

float UFortScalableFloatUtils::GetValueAtLevel(const FScalableFloat& Input, float Level)
{
	return float();
}

float UFortScalableFloatUtils::GetValueAtLevelWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, float Level)
{
	return float();
}

bool UFortScalableFloatUtils::IsSettingCurveValid(const FScalableFloat& Input)
{
	return false;
}

bool UFortScalableFloatUtils::IsStatic(const FScalableFloat& Input)
{
	return false;
}

DEFINE_FUNCTION(UFortScalableFloatUtils::execK2_SetValueWithContext)
{
	FortStub_SkipThunkParams(Stack, UFortScalableFloatUtils::StaticClass()->FindFunctionByName(TEXT("K2_SetValueWithContext")));
}
bool UFortScalableFloatUtils::K2_SetValueWithContext(const UObject* WorldContextObject, const FScalableFloat& Input, const int32& OverrideValue, bool bShouldApply)
{
	return false;
}

void UFortScalableFloatUtils::ScaleValue(FScalableFloat& Input, float Multiplier)
{
}

void UFortScalableFloatUtils::SetScalingValue(FScalableFloat& Input, float InCoeffecient, const FName InRowName, UCurveTable* InTable)
{
}

void UFortScalableFloatUtils::SetValue(FScalableFloat& Input, float NewValue)
{
}

FString UFortScalableFloatUtils::ToSimpleString(const FScalableFloat& Input)
{
	return FString();
}
