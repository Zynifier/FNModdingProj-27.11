// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "FortHUDElementWidget.h"
#include "BacchusRadialDisplayBase.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBacchusRadialDisplayBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateRadialCounterEvent_Blueprint(float NewCounterFillPercent);

private:
	UFUNCTION()
	void HandleUIGameplayCue(FName CueName, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters);

	UPROPERTY()
	FGameplayTag TrackedCueTag;

};

