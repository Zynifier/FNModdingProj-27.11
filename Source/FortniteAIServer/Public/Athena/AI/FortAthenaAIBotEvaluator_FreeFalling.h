// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_FreeFalling.generated.h"

class AFortPlayerStateAthena;
class AFortSkyTube;
class UFortAthenaAIBotMovementDigestedSkillSet;

UENUM()
enum class EFreeFallingMode : uint8
{
	/** Bot just drops without moving */
	Idle = 0,
	/** Random location inside safezone */
	Random = 1,
	/** Bot tries to go toward an ally */
	TowardNearestAlly = 2,
	/** Bot tries to go back to its current patrol path destination (use random destination inside leash as a fallback) */
	PatrolPath = 3,
};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_FreeFalling : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DiveExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DiveDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName GlideExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName GlideDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName JumpOffBusDestinationName;

	UPROPERTY(EditDefaultsOnly, Category="Free Falling")
	bool bRandomlySelectFreeFallingMode;

	UPROPERTY(EditDefaultsOnly, Category="Free Falling|Mode Weights", meta=(EditCondition="bRandomlySelectFreeFallingMode"))
	FScalableFloat IdleWeight;

	UPROPERTY(EditDefaultsOnly, Category="Free Falling|Mode Weights", meta=(EditCondition="bRandomlySelectFreeFallingMode"))
	FScalableFloat RandomWeight;

	UPROPERTY(EditDefaultsOnly, Category="Free Falling|Mode Weights", meta=(EditCondition="bRandomlySelectFreeFallingMode"))
	FScalableFloat TowardNearestAllyWeight;

	UPROPERTY(EditAnywhere, Category="Free Falling", meta=(AllowPrivateAccess="true", EditCondition="!bRandomlySelectFreeFallingMode"))
	EFreeFallingMode FreeFallingMode;

	UPROPERTY(EditAnywhere, Category="Free Falling", meta=(AllowPrivateAccess="true", EditCondition="FreeFallingMode == EFreeFallingMode::TowardNearestAlly || bRandomlySelectFreeFallingMode"))
	float MaxOffsetRangeFromNearestAlly;

	UPROPERTY(EditAnywhere, Category="Free Falling", meta=(AllowPrivateAccess="true", EditCondition="FreeFallingMode == EFreeFallingMode::TowardNearestAlly || bRandomlySelectFreeFallingMode"))
	uint8 bShouldRecomputeDestinationWhenTowardNearestAlly : 1;

	UPROPERTY(EditAnywhere, Category="Free Falling", meta=(AllowPrivateAccess="true", EditCondition="FreeFallingMode == EFreeFallingMode::TowardNearestAlly || bRandomlySelectFreeFallingMode"))
	uint8 bShouldSearchAllyInSquad : 1;

	UPROPERTY(EditAnywhere, Category="Free Falling", meta=(AllowPrivateAccess="true", EditCondition="FreeFallingMode == EFreeFallingMode::TowardNearestAlly || bRandomlySelectFreeFallingMode"))
	uint8 bShouldSearchAllyInTeam : 1;

	UPROPERTY(EditAnywhere, Category="Free Falling", meta=(AllowPrivateAccess="true"))
	uint8 bGlideAllowed : 1;

	UPROPERTY(EditAnywhere, Category="Sky Tube")
	float SkyTubeDivingStuckTimeThreshold;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> NearestAlly;

	UPROPERTY(Transient)
	FVector CachedLatestDestination;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotMovementDigestedSkillSet> CacheMovementDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<AFortSkyTube> CachedSkyTube;

};

