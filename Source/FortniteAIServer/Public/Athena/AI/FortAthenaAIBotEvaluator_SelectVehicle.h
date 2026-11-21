// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_SelectVehicle.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_SelectVehicle : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName VehicleDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SelectVehicleMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SelectVehicleStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SelectedVehicleKeyName;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	FScalableFloat Enabled;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true", UIMin="0.0"))
	float VehicleSearchRadius;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	bool bCanEnterOnlyWithHisConverter;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	bool bCanEnterAsDriver;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	bool bCanEnterVehiclesInWater;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	bool bCanEnterOutOfFuelVehicles;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true", EditCondition="!bCanEnterOnlyWithHisConverter"))
	bool bCanEnterWithPlayerDriver;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true", EditCondition="!bCanEnterOnlyWithHisConverter"))
	bool bCanEnterOnlyMatchingPatrols;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery VehiclesFilterTagQuery;

	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery SeatsFilterTagQuery;

};

