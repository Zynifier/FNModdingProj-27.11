// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tweening/TweenFactory/MaterialTweening.h"

void UMaterialTweening::BP_ColorParamTo(int32& OutTweenId, UObject* ContextObject, UMaterialInstanceDynamic*& Target, FName ParameterName, FTweenOptionalLinearColor FromOptions, FLinearColor ToValue, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay, bool bAutoKill)
{
}

void UMaterialTweening::BP_ScalarParamTo(int32& OutTweenId, UObject* ContextObject, UMaterialInstanceDynamic*& Target, FName ParameterName, FTweenOptionalFloat FromOptions, float ToValue, bool bIsRelative, float Duration, FTweenDelayOptions DelayOptions, ETweenBuiltInEasing EasingFunction, UCurveFloat* EasingCurve, FTweenLoopOptions LoopOptions, bool bAutoPlay, bool bAutoKill)
{
}
