// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Curie/FortCurieFXTypes.h"
#include "CurieDefinitions.h"
#include "FortCurieDefinitions.generated.h"

USTRUCT()
struct FFortCurieElementDefinition : public FCurieElementDefinitionBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieElementDefinition", meta=(UIMin="0"))
	float MaxIntensity;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieElementDefinition", meta=(ClampMin="0", UIMin="0"))
	float IntensityDecayRate;

};

USTRUCT()
struct FFortCurieEntityStateDefinition : public FCurieEntityStateDefinitionBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(Categories="GameplayCue.Curie.State"))
	FGameplayTag GameplayCue;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	EFortCurieNativeFXType NativeVFXType;

	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(Categories="Curie.NativeFX"))
	FGameplayTag NativeFXTag;

};

USTRUCT()
struct FFortCurieMaterialElementIntensityDecayMultiplier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialElementIntensityDecayMultiplier", meta=(Categories="CurieElement"))
	FGameplayTag Element;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialElementIntensityDecayMultiplier")
	float DecayMultiplier;

};

USTRUCT()
struct FFortCurieMaterialDefinition : public FCurieMaterialDefinitionBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition")
	uint8 bTrackGridFireStatus : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition")
	uint8 bShouldIgniteLandscapeGrass : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition")
	uint8 bHandlesOverlapsDirectly : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition")
	uint8 bAddAttachedElementsToElementSpatialGrid : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition", meta=(ClampMin="0", UIMin="0"))
	float DefaultWaterContent;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition", meta=(ClampMin="0", UIMin="0"))
	float MinWaterContent;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition", meta=(ClampMin="0", UIMin="0"))
	float MaxWaterContent;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition", meta=(ClampMin="0", UIMin="0"))
	float WaterContentStabilizationRate;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition", meta=(ClampMin="0", UIMin="0"))
	float FirePropagationCost;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieMaterialDefinition")
	TArray<FFortCurieMaterialElementIntensityDecayMultiplier> ElementDecayMultipliers;

};

