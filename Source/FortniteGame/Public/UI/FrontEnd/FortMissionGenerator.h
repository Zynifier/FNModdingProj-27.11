// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "FortMultiSize.h"
#include "UI/FrontEnd/FortPlayerSpawnPadPlacementData.h"
#include "UI/FrontEnd/FortZoneLoadingScreenConfig.h"
#include "FortMissionGenerator.generated.h"

class UFortMissionGenerationList;
class UFortMissionInfo;
class UTexture2D;

USTRUCT(BlueprintType)
struct FFortAthenaLTMConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen")
	TSoftObjectPtr<UTexture2D> SplashImage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen")
	FText FrontEndDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen")
	FText DisabledMessage;

};

USTRUCT(BlueprintType)
struct FFortMissionInfoOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionInfoOption")
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionInfoOption")
	float MinDifficultyLevel;

};

USTRUCT(BlueprintType)
struct FFortPossibleMission
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPossibleMission")
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortPossibleMission")
	float Weight;

	UPROPERTY(EditDefaultsOnly, Category="FortPossibleMission", meta=(ClampMin="0.000000", UIMin="0.000000"))
	int32 MinAlwaysGenerated;

	UPROPERTY(EditDefaultsOnly, Category="FortPossibleMission")
	bool bIsPrototype;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortMissionGenerator : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Description")
	FText MissionName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Description")
	FText MissionDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Description")
	FSlateBrush MissionIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Description")
	FFortMultiSizeBrush MissionIcons;

	UPROPERTY(EditDefaultsOnly, Category="LoadingScreen", meta=(ShowOnlyInnerProperties))
	FZoneLoadingScreenConfig LoadingScreenConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MatchmakingFrontend", meta=(ShowOnlyInnerProperties))
	FFortAthenaLTMConfig AthenaLTMConfig;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="NamedWeights")
	FName PrimaryMissionNamedWeightsRowName;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MissionGeneration", meta=(AssetBundles="MenuCampaign"))
	TSoftObjectPtr<UFortMissionInfo> PrimaryMissionInfo;

	UPROPERTY(EditAnywhere, Category="MissionGeneration")
	bool bUseNewMissionGeneration;

	UPROPERTY(EditAnywhere, Category="MissionGeneration")
	FGameplayTagQuery OptionalRequirementsForAllOtherMissions;

	UPROPERTY(EditAnywhere, Category="MissionGeneration")
	TSoftObjectPtr<UFortMissionGenerationList> MissionGenerationList;

	UPROPERTY(EditAnywhere, Category="Deprecated|FortMissionGenerator", meta=(ArraySizeEnum="/Script/FortniteGame.EMissionGenerationCategory"))
	float MissionGenerationChance[4];

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Deprecated|SecondaryMissions")
	TArray<FFortPossibleMission> SecondaryMissionList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Deprecated|TertiaryMissions")
	TArray<FFortPossibleMission> TertiaryMissionList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Deprecated|SurvivorMissions")
	TArray<FFortPossibleMission> SurvivorMissionList;

	UPROPERTY(EditAnywhere, Category="PlayerSpawnPad")
	bool bUseOverridePlayerSpawnPadPlacementData;

	UPROPERTY(EditAnywhere, Category="PlayerSpawnPad", meta=(EditCondition="bUseOverridePlayerSpawnPadPlacementData"))
	FFortPlayerSpawnPadPlacementData OverridePlayerSpawnPadPlacementData;

};

