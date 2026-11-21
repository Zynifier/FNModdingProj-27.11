// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActionHandlerInterface.h"
#include "UObject/NoExportTypes.h"
#include "CommonGlobalInputHandlerLegacy.generated.h"

UCLASS()
class COMMONUILEGACY_API UCommonGlobalInputHandlerLegacy : public UObject, public ICommonActionHandlerInterface
{
	GENERATED_BODY()

public:
	virtual bool HandleHoldInput(int32 ControllerId, FKey KeyPressed, EInputEvent EventType, bool& bPassThrough) override;

	virtual bool HandlePressInput(FKey KeyPressed, EInputEvent EventType, bool& bPassThrough) override;

	virtual bool HandleTouchInput(uint32 TouchId, ETouchType::Type TouchType, const FVector2D& TouchLocation, bool& bPassThrough) override;

	virtual void UpdateCurrentlyHeldAction(float InDeltaTime) override;

	virtual void TriggerFirstMatchingInputAction(int32 ControllerId, const FCommonInputActionDataBase& InInputActionData, bool bHoldAction) override;

};

