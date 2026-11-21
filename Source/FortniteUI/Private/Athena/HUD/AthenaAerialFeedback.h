// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "HUD/FortAerialFeedback.h"
#include "AthenaAerialFeedback.generated.h"

class AFortPlayerState;
class UFortItemDefinition;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaAerialFeedback : public UFortAerialFeedback
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleBalloonMovementChanged(bool bUsingBalloonMovement);

	UFUNCTION()
	void HandleKeybindsChanged();

	UFUNCTION()
	void HandleSkydiveLeaderChanged(bool bEnabled, bool bLocal, AFortPlayerState* LeaderPlayerState);

	UPROPERTY(EditDefaultsOnly, Category="AthenaAerialFeedback")
	FGameplayTagContainer GliderRedeployTags;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAerialFeedback")
	FGameplayTag AirbagDeployTag;

	UPROPERTY(EditDefaultsOnly, Transient, Category="AthenaAerialFeedback")
	TObjectPtr<UFortItemDefinition> AirbagItemDefinition;

};

