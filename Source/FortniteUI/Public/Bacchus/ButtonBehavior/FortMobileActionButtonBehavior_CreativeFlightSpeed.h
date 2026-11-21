// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehavior.h"
#include "FortMobileActionButtonBehavior_CreativeFlightSpeed.generated.h"

UCLASS()
class UFortMobileActionButtonBehavior_CreativeFlightSpeed : public UFortMobileActionButtonBehavior
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCreativeFlightSpeedIndexChanged(int32 Index, bool bPlayFx);

	UPROPERTY(EditAnywhere, Category="FortMobileActionButtonBehavior_CreativeFlightSpeed")
	FGameplayTag TrackedSpeedTag;

};

