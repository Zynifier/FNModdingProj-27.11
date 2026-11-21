// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NavSystemConfigOverride.h"
#include "ScalableFloat.h"
#include "AI/FortAIDirectorCommonTypes.h"
#include "AthenaAISettings.generated.h"

class AAthenaNavSystemConfigOverride;
class UAthenaAIService;
class UAthenaAISettingsAIDIrectorLOD;

UCLASS(MinimalAPI, HideCategories=("Input", "Rendering", "Actor", "LOD", "Cooking", "Input", "Rendering", "Actor", "LOD", "Cooking"))
class AAthenaNavSystemConfigOverride : public ANavSystemConfigOverride
{
	GENERATED_BODY()

};

UCLASS(Config=Engine, DefaultConfig, EditInlineNew, CollapseCategories, MinimalAPI, BlueprintType)
class UAthenaAISettings : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Deimos", meta=(AllowPrivateAccess="true"))
	uint8 bAllowAIDirector : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Deimos", meta=(AllowPrivateAccess="true"))
	uint8 bAllowAIGoalManager : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Deimos", meta=(AllowPrivateAccess="true"))
	uint8 bForceRVOUse : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hearing Detection", meta=(AllowPrivateAccess="true", ClampMin="0.001", UIMin="0.001"))
	float MaxPlayerSpeedScaleFootstepSounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hearing Detection", meta=(AllowPrivateAccess="true", ClampMin="0", UIMin="0"))
	float MinFootstepHearingRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hearing Detection", meta=(AllowPrivateAccess="true", ClampMin="0", UIMin="0"))
	float MaxFootstepHearingRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hearing Detection", meta=(AllowPrivateAccess="true", ClampMin="0.001", UIMin="0.001"))
	float DamagedHearingRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hearing Detection", meta=(AllowPrivateAccess="true", ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float CrouchHearingModifier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hearing Detection", meta=(AllowPrivateAccess="true", ClampMin="0", UIMin="0"))
	float MaxNPCHearingRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Hearing Detection", meta=(AllowPrivateAccess="true", ClampMin="0", UIMin="0"))
	float MaxPerceptualStimuliAge;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Deimos", meta=(AllowPrivateAccess="true"))
	float DeAggroRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Deimos", meta=(AllowPrivateAccess="true"))
	float ReducedDeAggroRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Deimos", meta=(AllowPrivateAccess="true"))
	float DurationReduceAggroLimits;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	TSubclassOf<AAthenaNavSystemConfigOverride> NavigationSystemConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIDirectorLOD", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UAthenaAISettingsAIDIrectorLOD> AIDIrectorLOD;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AI Services", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UAthenaAIService>> AIServices;

};

UCLASS(Config=Engine, DefaultConfig, EditInlineNew, CollapseCategories, BlueprintType)
class UAthenaAISettingsAIDIrectorLOD : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIDirectorLOD", meta=(AllowPrivateAccess="true"))
	TArray<FPlayerLODViewConeConfig> PlayerLODViewConeConfigs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIDirectorLOD", meta=(AllowPrivateAccess="true"))
	FPlayerLODViewConeHysteresisConfig PlayerLODViewConeHysteresisConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIDirectorLOD", meta=(AllowPrivateAccess="true"))
	FScalableFloat CouldBeVisibleViewConeAngleDegrees;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIDirectorLOD", meta=(AllowPrivateAccess="true"))
	FScalableFloat CouldBeVisibleMaxDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIDirectorLOD", meta=(AllowPrivateAccess="true"))
	FScalableFloat LODSortHysteresisDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIDirectorLOD", meta=(AllowPrivateAccess="true"))
	TArray<FFortAIDirectorPerLODConfig> FortAIDirectorLODConfigs;

};

