// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortRebootCardsCollectedWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortRebootCardsCollectedWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Resurrection")
	void OnRebootCardsCollectedChanged();

	UPROPERTY(BlueprintReadOnly, Category="Resurrection")
	int32 NumCardsCollected;

};

