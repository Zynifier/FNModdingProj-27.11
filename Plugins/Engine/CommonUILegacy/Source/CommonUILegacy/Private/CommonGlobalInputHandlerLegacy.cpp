// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonGlobalInputHandlerLegacy.h"

bool UCommonGlobalInputHandlerLegacy::HandleHoldInput(int32 ControllerId, FKey KeyPressed, EInputEvent EventType, bool& bPassThrough)
{
	return false;
}

bool UCommonGlobalInputHandlerLegacy::HandlePressInput(FKey KeyPressed, EInputEvent EventType, bool& bPassThrough)
{
	return false;
}

bool UCommonGlobalInputHandlerLegacy::HandleTouchInput(uint32 TouchId, ETouchType::Type TouchType, const FVector2D& TouchLocation, bool& bPassThrough)
{
	return false;
}

void UCommonGlobalInputHandlerLegacy::UpdateCurrentlyHeldAction(float InDeltaTime)
{
}

void UCommonGlobalInputHandlerLegacy::TriggerFirstMatchingInputAction(int32 ControllerId, const FCommonInputActionDataBase& InInputActionData, bool bHoldAction)
{
}
