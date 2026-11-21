// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotSkillSet.h"
#include "FortAthenaAIBotVehicleSkillSet.generated.h"

USTRUCT()
struct FVehicleDigestedAppendToPath
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float MinimumPathLengthToEndOfPath;

	UPROPERTY(Transient)
	float MinTimeSinceLastAppend;

};

USTRUCT()
struct FVehicleDigestedPIDController
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float KP;

	UPROPERTY(Transient)
	float KI;

	UPROPERTY(Transient)
	float KD;

};

USTRUCT()
struct FVehicleDigestedTurnInPlace
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float MovingAngleBegin;

	UPROPERTY(Transient)
	float MovingAngleEnd;

	UPROPERTY(Transient)
	float IdleAngleBegin;

	UPROPERTY(Transient)
	float IdleAngleEnd;

	UPROPERTY(Transient)
	float MinMovingSpeed;

	UPROPERTY(Transient)
	bool bMissedPathPointReverse;

};

USTRUCT()
struct FDigestedVehicleDriving
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	bool bCanTurnInPlace;

	UPROPERTY(Transient)
	bool bAvoidanceEnabled;

	UPROPERTY(Transient)
	bool bPreventTurningWhenStopping;

	UPROPERTY(Transient)
	FGameplayTagQuery AvoidanceTagQuery;

	UPROPERTY(Transient)
	bool bReverseSwapLeftAndRight;

	UPROPERTY(Transient)
	float MinimumForwardPIDValueForStopping;

	UPROPERTY(Transient)
	float MinimumDistanceLeftForBoosting;

	UPROPERTY(Transient)
	FVehicleDigestedPIDController ForwardPIDController;

	UPROPERTY(Transient)
	FVehicleDigestedPIDController SteeringPIDController;

	UPROPERTY(Transient)
	FVehicleDigestedAppendToPath AppendToPath;

	UPROPERTY(Transient)
	FVehicleDigestedTurnInPlace TurnInPlace;

	UPROPERTY(Transient)
	FGameplayTagContainer ModsTags;

};

USTRUCT()
struct FDigestedVehicleDrivingCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer Tags;

	UPROPERTY(Transient)
	FDigestedVehicleDriving VehicleDriving;

};

USTRUCT()
struct FVehicleAppendToPath
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Append To Path", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinimumPathLengthToEndOfPath;

	UPROPERTY(EditDefaultsOnly, Category="Append To Path", meta=(AllowPrivateAccess="true"))
	FScalableFloat MinTimeSinceLastAppend;

};

USTRUCT()
struct FVehiclePIDController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PID Controller", meta=(AllowPrivateAccess="true"))
	FScalableFloat KP;

	UPROPERTY(EditDefaultsOnly, Category="PID Controller", meta=(AllowPrivateAccess="true"))
	FScalableFloat KI;

	UPROPERTY(EditDefaultsOnly, Category="PID Controller", meta=(AllowPrivateAccess="true"))
	FScalableFloat KD;

};

USTRUCT()
struct FVehicleTurnInPlace
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true", DisplayName="Moving angle begin (degrees)"))
	FScalableFloat MovingAngleBegin;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true", DisplayName="Moving angle end (degrees)"))
	FScalableFloat MovingAngleEnd;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true", DisplayName="Idle angle begin"))
	FScalableFloat IdleAngleBegin;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true", DisplayName="Idle angle end"))
	FScalableFloat IdleAngleEnd;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true", DisplayName="Min moving speed km/h"))
	FScalableFloat MinMovingSpeed;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true", DisplayName="Reverse on missed point"))
	bool bMissedPathPointReverse;

};

USTRUCT()
struct FVehicleDriving
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true"))
	bool bCanTurnInPlace;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace", meta=(AllowPrivateAccess="true", EditCondition="bCanTurnInPlace"))
	FVehicleTurnInPlace TurnInPlace;

	UPROPERTY(EditDefaultsOnly, Category="Turn", meta=(AllowPrivateAccess="true"))
	FScalableFloat ReverseSwapLeftAndRight;

	UPROPERTY(EditDefaultsOnly, Category="PathFollow", meta=(AllowPrivateAccess="true", DisplayName="Minimum forward PID value when stopping"))
	FScalableFloat MinimumForwardPIDValueForStopping;

	UPROPERTY(EditDefaultsOnly, Category="Boost", meta=(AllowPrivateAccess="true", DisplayName="Minimum distance before stopping to allow boosting"))
	FScalableFloat MinimumDistanceLeftForBoosting;

	UPROPERTY(EditDefaultsOnly, Category="PID Controller", meta=(AllowPrivateAccess="true"))
	FVehiclePIDController ForwardPIDController;

	UPROPERTY(EditDefaultsOnly, Category="PID Controller", meta=(AllowPrivateAccess="true"))
	FVehiclePIDController SteeringPIDController;

	UPROPERTY(EditDefaultsOnly, Category="Avoidance", meta=(AllowPrivateAccess="true"))
	bool bAvoidanceEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Avoidance", meta=(AllowPrivateAccess="true"))
	bool bPreventTurningWhenStopping;

	UPROPERTY(EditDefaultsOnly, Category="Avoidance", meta=(AllowPrivateAccess="true", EditCondition="bAvoidanceEnabled"))
	FGameplayTagQuery AvoidanceTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Patrol Path", meta=(AllowPrivateAccess="true"))
	FVehicleAppendToPath AppendToPath;

	UPROPERTY(EditDefaultsOnly, Category="Mods", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer ModsTags;

};

USTRUCT()
struct FVehicleDrivingCategory
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="VehicleDrivingCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Tags"))
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="VehicleDrivingCategory", meta=(AllowPrivateAccess="true", DisplayName="Category Vehicle"))
	FVehicleDriving VehicleDriving;

};

UCLASS()
class UFortAthenaAIBotVehicleDigestedSkillSet : public UFortAthenaAIBotDigestedSkillSet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FDigestedVehicleDriving NoMatchingVehicleDriving;

	UPROPERTY(Transient)
	TArray<FDigestedVehicleDrivingCategory> VehicleDrivingArray;

};

UCLASS(MinimalAPI)
class UFortAthenaAIBotVehicleSkillSet : public UFortAthenaAIBotSkillSet
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	FVehicleDriving NoMatchingVehicleDriving;

	UPROPERTY(EditDefaultsOnly, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	TArray<FVehicleDrivingCategory> VehicleDrivingArray;

};

