// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Attack.h"
#include "FortAthenaAIBotEvaluator_RangeAttack.generated.h"

class AActor;
class UAthenaAIServiceCover;
class UAthenaAIServiceZoneManager;
class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotAttackingDigestedSkillSet;
class UFortAthenaAIBotPerceptionDigestedSkillSet;
class UFortAthenaAIBotRangeAttackDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_RangeAttack : public UFortAthenaAIBotEvaluator_Attack
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void FindShootingPosition_Async(const int32 RequestID, const float DistanceFromTarget, const float WeaponIdealAttackRange, const FVector& TargetPosition);

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponReloadName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponFireName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName RangeAttackIsReadyToFireName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTargetingName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AggressivenessName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName HasLoSOnThreatName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName UrgentMovementKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="RangeAttack", meta=(AllowPrivateAccess="true"))
	bool bAlwaysAllowTargetingEvaluation;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="RangeAttack", meta=(AllowPrivateAccess="true"))
	bool bSkipADSEvaluation;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="RangeAttack", meta=(AllowPrivateAccess="true"))
	bool bConsiderLoF;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="RangeAttack", meta=(AllowPrivateAccess="true", ClampMin="1.0"))
	float RangeReachHysteresisRatio;

	UPROPERTY(Transient)
	UFortAthenaAIBotRangeAttackDigestedSkillSet* CacheRangeAttackDigestedSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotAimingDigestedSkillSet* CacheAimingDigestedSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotPerceptionDigestedSkillSet* CachePerceptionDigestedSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotAttackingDigestedSkillSet* CacheAttackingDigestedSkillSet;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAthenaAIServiceZoneManager> CacheZoneManager;

	UPROPERTY(Transient)
	TWeakObjectPtr<UAthenaAIServiceCover> CachedAIServiceCover;

	UPROPERTY(Transient)
	AActor* ExcludeReachingTarget;

};

