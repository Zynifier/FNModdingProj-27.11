// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortAthenaMutator_Omaha.generated.h"

UENUM(BlueprintType)
enum class EOmahaTeam : uint8
{
	Home = 0,
	Away = 1,
	MAX = 2,
};

USTRUCT()
struct FOmahaCharacterVariantInfoData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="OmahaCharacterVariantInfoData")
	TArray<FMcpVariantChannelInfo> VariantChannelInfo;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Omaha : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Display Data", meta=(ArraySizeEnum="/Script/FortniteGame.EOmahaTeam"))
	FOmahaCharacterVariantInfoData CharacterVariantInfoData[2];

	UPROPERTY(EditAnywhere, Category="Display Data", meta=(ArraySizeEnum="/Script/FortniteGame.EOmahaTeam"))
	FOmahaCharacterVariantInfoData SpecialCharacterVariantInfoData[2];

	UPROPERTY(EditAnywhere, Category="Display Data", meta=(ArraySizeEnum="/Script/FortniteGame.EOmahaTeam"))
	int32 SpecialTeamMembersCount[2];

	UPROPERTY(EditAnywhere, Category="Hot Fix Data")
	FScalableFloat HomeTeamIndex;

	UPROPERTY(EditAnywhere, Category="Hot Fix Data")
	FScalableFloat AwayTeamIndex;

};

