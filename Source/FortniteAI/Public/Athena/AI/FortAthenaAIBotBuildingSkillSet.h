// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "FortAthenaAIBotBuildingSkillSet.generated.h"

UENUM(BlueprintType)
namespace EAIBotBuildingTemplate
{
	enum Type
	{
		SingleWall = 0,
		SingleRamp = 1,
		SingleRoof = 2,
		SingleBrace = 3,
		SingleWallWindow = 4,
		MAX = 5,
	};
}

USTRUCT()
struct FFortAthenaAIBotBuildDescriptor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotBuildDescriptor")
	FIntVector Location;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotBuildDescriptor")
	TEnumAsByte<EOrientedConstructionBuildingType::Type> BuildingType;

};

USTRUCT()
struct FAthenaFortAIBotDigestedWeightedBuildingList
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float Weight;

	UPROPERTY(Transient)
	TArray<FFortAthenaAIBotBuildDescriptor> BuildDescriptors;

};

USTRUCT()
struct FAthenaFortAIBotWeightedBuildingList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaFortAIBotWeightedBuildingList")
	FScalableFloat Weight;

	UPROPERTY(EditDefaultsOnly, Category="AthenaFortAIBotWeightedBuildingList")
	TArray<FFortAthenaAIBotBuildDescriptor> BuildDescriptors;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotBuildingDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float DefensiveBuildingDelayBetweenBuilds;

	UPROPERTY(Transient)
	float DefensiveBuildingDelayDeviationBetweenBuilds;

	UPROPERTY(Transient)
	float DelayBetweenBuildPieces;

	UPROPERTY(Transient)
	float ForceEquipBuildToolDuration;

	UPROPERTY(Transient)
	float StealWallTurboBuildDetectionTime;

	UPROPERTY(Transient)
	int32 StealWallAfterNumberOfTurboBuiltWall;

	UPROPERTY(Transient)
	float StealWallEfficiency;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteAI.EAIBotBuildingTemplate"))
	float StealWallBuildingTemplateWeights[5];

	UPROPERTY(Transient)
	TArray<FAthenaFortAIBotDigestedWeightedBuildingList> WeightedBuildingLists;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotBuildingSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Defensive Building", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefensiveBuildingDelayBetweenBuilds;

	UPROPERTY(EditDefaultsOnly, Category="Defensive Building", meta=(AllowPrivateAccess="true"))
	FScalableFloat DefensiveBuildingDelayDeviationBetweenBuilds;

	UPROPERTY(EditDefaultsOnly, Category="Defensive Building", meta=(AllowPrivateAccess="true"))
	FScalableFloat DelayBetweenBuildPieces;

	UPROPERTY(EditDefaultsOnly, Category="Defensive Building", meta=(AllowPrivateAccess="true"))
	FScalableFloat ForceEquipBuildToolDuration;

	UPROPERTY(EditDefaultsOnly, Category="Defensive Building", meta=(AllowPrivateAccess="true"))
	TArray<FAthenaFortAIBotWeightedBuildingList> WeightedBuildingLists;

	UPROPERTY(EditDefaultsOnly, Category="Steal Wall", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealWallTurboBuildDetectionTime;

	UPROPERTY(EditDefaultsOnly, Category="Steal Wall", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealWallAfterNumberOfTurboBuiltWall;

	UPROPERTY(EditDefaultsOnly, Category="Steal Wall", meta=(AllowPrivateAccess="true"))
	FScalableFloat StealWallEfficiency;

	UPROPERTY(EditDefaultsOnly, Category="Steal Wall", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EAIBotBuildingTemplate"))
	FScalableFloat StealWallBuildingTemplateWeights[5];

};

