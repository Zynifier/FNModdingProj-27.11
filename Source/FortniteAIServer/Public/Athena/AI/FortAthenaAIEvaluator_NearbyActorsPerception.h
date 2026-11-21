// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GenericTeamAgentInterface.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIEvaluator.h"
#include "FortAthenaAIEvaluator_NearbyActorsPerception.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIEvaluator_NearbyActorsPerception : public UFortAthenaAIEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FoundNearbyActorKeyName;

	UPROPERTY(EditAnywhere, Category="Perception", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinimumUpdateInterval;

	UPROPERTY(EditAnywhere, Category="Perception", meta=(AllowPrivateAccess="true", Bitmask, BitmaskEnum="/Script/FortniteGame.EFortNearbyActorsTypes"))
	int32 RequiredTypes;

	UPROPERTY(EditAnywhere, Category="Perception", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinimumDistanceToActors;

	UPROPERTY(EditAnywhere, Category="Perception", meta=(AllowPrivateAccess="true"))
	TArray<TEnumAsByte<ETeamAttitude::Type>> RequiredAttitudes;

	UPROPERTY(EditAnywhere, Category="Perception", meta=(AllowPrivateAccess="true"))
	bool bRequireLoS;

	UPROPERTY(EditAnywhere, Category="Perception", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery RequiredTagsQuery;

};

