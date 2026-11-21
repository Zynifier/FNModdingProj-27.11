// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Harvest.generated.h"

class AFortPawn;
class UNavigationQueryFilter;
enum class EUnconvertReason : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Harvest : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleConverted(const AFortPawn* InstigatorPawn, const AFortPawn* ConvertedPawn);

	UFUNCTION()
	void HandleUnconverted(const AFortPawn* UnconvertedPawn, EUnconvertReason UnconvertReason);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_Harvest", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UNavigationQueryFilter> ProjectionNavigationQueryFilterClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_Harvest", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UNavigationQueryFilter> ValidNavigationQueryFilterClassOverride;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Harvest", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaximumTimeToHelpFromLastPlayerDamage;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Harvest", meta=(AllowPrivateAccess="true"))
	FScalableFloat KeepTargetTimeOnWeaponTrigger;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Harvest", meta=(AllowPrivateAccess="true"))
	FScalableFloat AmountOfTimesPlayerBuiltStructuresNeedToBeDamaged;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Harvest", meta=(AllowPrivateAccess="true"))
	FScalableFloat TimeToTrackDamagedActors;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Harvest", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxDistanceFromActorForFallbackNoHarvestBehaviour;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName HarvestTargetKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName HarvestTargetHitPointKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName HarvestDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FallbackBehaviorKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CannotDamageKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponTriggerMeleeKeyName;

};

