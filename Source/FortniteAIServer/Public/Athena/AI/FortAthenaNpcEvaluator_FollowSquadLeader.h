// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaNpcEvaluator_FollowSquadLeader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaNpcEvaluator_FollowSquadLeader : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Squad Formation")
	FScalableFloat FormationOffsetRadiusMin;

	UPROPERTY(EditDefaultsOnly, Category="Squad Formation")
	FScalableFloat FormationOffsetRadiusMax;

	UPROPERTY(EditDefaultsOnly, Category="Squad Formation")
	FScalableFloat TooFarFromSquadLeaderDistance;

	UPROPERTY(EditDefaultsOnly, Category="Noise Offset")
	FScalableFloat MaxNoiseRadius;

	UPROPERTY(EditDefaultsOnly, Category="Noise Offset")
	FScalableFloat MinDurationNoiseEvaluate;

	UPROPERTY(EditDefaultsOnly, Category="Noise Offset")
	FScalableFloat MaxDurationNoiseEvaluate;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowSquadLeaderStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowSquadLeaderMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowSquadLeaderDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TooFarFromLeaderKeyName;

	UPROPERTY(Transient)
	FVector CachedSquadFormationOffset;

	UPROPERTY(Transient)
	FVector CachedNoiseOffset;

	UPROPERTY(Transient)
	float CachedTooFarFromSquadLeaderDistanceSqr;

	UPROPERTY(Transient)
	float LastNoiseOffsetUpdateTime;

	UPROPERTY(Transient)
	float DurationNoiseEvaluate;

};

