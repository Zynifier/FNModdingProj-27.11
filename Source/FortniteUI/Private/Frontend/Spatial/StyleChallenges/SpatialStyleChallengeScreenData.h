// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Frontend/Spatial/StyleChallenges/SpatialStyleChallengeTypes.h"
#include "SpatialStyleChallengeScreenData.generated.h"

class UFortChallengeBundleScheduleDefinition;

UCLASS(BlueprintType, Blueprintable)
class UAthenaSpatialStyleChallengeScreenData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialStyleChallengeScreenData")
	TArray<FAthenaSpatialStyleCharacterData> CharacterStyleChallenges;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSpatialStyleChallengeScreenData")
	TObjectPtr<UFortChallengeBundleScheduleDefinition> CharacterStyleChallengesSchedule;

};

