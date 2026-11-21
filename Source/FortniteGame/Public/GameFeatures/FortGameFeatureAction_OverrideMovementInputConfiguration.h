// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortGameInstanceGameFeatureAction.h"
#include "Pawns/FortPawnMovementOverridesSubsystem.h"
#include "FortGameFeatureAction_OverrideMovementInputConfiguration.generated.h"

UENUM()
enum class EOverrideMovementInputConfigurationPlatforms : int32
{
	Windows = 0,
	Mac = 1,
	Linux = 2,
	Xbox = 3,
	Playstation = 4,
	Switch = 5,
	Android = 6,
	IOS = 7,
};

UCLASS(meta=(DisplayName="Override Movement Input Configuration"))
class UFortGameFeatureAction_OverrideMovementInputConfiguration : public UFortGameInstanceGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="Input", meta=(DisplayName="Default Input Data"))
	FOverrideMovementInputData InputData;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TMap<EOverrideMovementInputConfigurationPlatforms, FOverrideMovementInputData> PlatformSpecificInputData;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	int32 Priority;

};

