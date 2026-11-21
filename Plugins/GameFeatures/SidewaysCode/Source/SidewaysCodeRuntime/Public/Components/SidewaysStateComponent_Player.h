// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SidewaysStateComponent.h"
#include "SidewaysStateComponent_Player.generated.h"

class UMaterialParameterCollection;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class USidewaysStateComponent_Player : public USidewaysStateComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Sideways", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialParameterCollection> SidewaysMaterialParameterCollection;

	UPROPERTY(EditDefaultsOnly, Category="Sideways")
	FName SidewaysBubbleLocationParameterNamesForLocalPlayers[2];

	UPROPERTY(EditDefaultsOnly, Category="Sideways")
	FName SidewaysBubbleRadiusParameterNamesForLocalPlayers[2];

	UPROPERTY(EditDefaultsOnly, Category="Sideways", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float ExtraCorruptionRadius;

	UPROPERTY(EditDefaultsOnly, Category="Sideways", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float MinRadiusToHaveAnyCorruption;

	UPROPERTY(EditDefaultsOnly, Category="Sideways", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float MaxRadiusForScalingExtraCorruptionRadius;

	UPROPERTY(EditDefaultsOnly, Category="Sideways")
	float UpdateFrequency;

};

