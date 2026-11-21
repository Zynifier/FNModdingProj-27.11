// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaNpcEvaluator_Encampment.generated.h"

UENUM()
enum class EEncampmentRole : uint8
{
	Guard = 0,
	Build = 1,
	Count = 2,
};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaNpcEvaluator_Encampment : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat EncampmentEnable;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat EncampmentTentativeDelayMin;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat EncampmentTentativeDelayMax;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat EncampmentDurationMin;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat EncampmentDurationMax;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat BuilderPercentage;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat BuilderMinDistance;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat BuilderMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat GuardMinDistance;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat GuardMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat AllowInSwimming;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat AllowInFalling;

	UPROPERTY(EditDefaultsOnly, Category="Encampment")
	FScalableFloat MinSquadMembersCountToBuild;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EncampmentStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EncampmentMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EncampmentCenterLocationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EncampmentDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EncampmentAroundCampFireLocationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EncampmentRoleKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DefensiveBuildName;

};

