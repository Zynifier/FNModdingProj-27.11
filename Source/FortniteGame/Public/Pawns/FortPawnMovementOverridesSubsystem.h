// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortPawnMovementOverridesSubsystem.generated.h"

class UCurveFloat;

USTRUCT()
struct FBaseMovementOverrideEntry
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FDirectionalSpeedMultiplierOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	TObjectPtr<UCurveFloat> Walking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	TObjectPtr<UCurveFloat> Running;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	TObjectPtr<UCurveFloat> Crouching;

};

USTRUCT()
struct FDirectionalSpeedMultiplierOverrideEntry : public FBaseMovementOverrideEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FDirectionalSpeedMultiplierOverrideData Override;

};

USTRUCT()
struct FFortPawnStatsOverrideEntry : public FBaseMovementOverrideEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FDataTableRowHandle Override;

};

USTRUCT()
struct FOverrideMeleeCombatSlowSpeedMultiplierEntry : public FBaseMovementOverrideEntry
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FOverrideMovementCurveData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="OverrideMovementCurveData", meta=(InlineEditConditionToggle))
	bool bUseBrakingDecelerationWalking;

	UPROPERTY(EditDefaultsOnly, Category="Curve | Braking", meta=(EditCondition="bUseBrakingDecelerationWalking"))
	FRuntimeFloatCurve BrakingDecelerationWalkingCurve;

	UPROPERTY(EditDefaultsOnly, Category="OverrideMovementCurveData", meta=(InlineEditConditionToggle))
	bool bUseBrakingDecelerationRunning;

	UPROPERTY(EditDefaultsOnly, Category="Curve | Braking", meta=(EditCondition="bUseBrakingDecelerationRunning"))
	FRuntimeFloatCurve BrakingDecelerationRunningCurve;

	UPROPERTY(EditDefaultsOnly, Category="OverrideMovementCurveData", meta=(InlineEditConditionToggle))
	bool bUseBrakingDecelerationSprinting;

	UPROPERTY(EditDefaultsOnly, Category="Curve | Braking", meta=(EditCondition="bUseBrakingDecelerationSprinting"))
	FRuntimeFloatCurve BrakingDecelerationSprintingCurve;

	UPROPERTY(EditDefaultsOnly, Category="OverrideMovementCurveData", meta=(InlineEditConditionToggle))
	bool bUseBrakingDecelerationTacticalSprinting;

	UPROPERTY(EditDefaultsOnly, Category="Curve | Braking", meta=(EditCondition="bUseBrakingDecelerationTacticalSprinting"))
	FRuntimeFloatCurve BrakingDecelerationTacticalSprintingCurve;

	UPROPERTY(EditDefaultsOnly, Category="OverrideMovementCurveData", meta=(InlineEditConditionToggle))
	bool bUseSpeedCurve;

	UPROPERTY(EditDefaultsOnly, Category="Curve", meta=(EditCondition="bUseSpeedCurve"))
	FRuntimeFloatCurve SpeedCurve;

	UPROPERTY(EditDefaultsOnly, Category="OverrideMovementCurveData", meta=(InlineEditConditionToggle))
	bool bUseWalkAccelerationCurve;

	UPROPERTY(EditDefaultsOnly, Category="Curve", meta=(EditCondition="bUseWalkAccelerationCurve"))
	FRuntimeFloatCurve WalkAccelerationCurve;

	UPROPERTY(EditDefaultsOnly, Category="OverrideMovementCurveData", meta=(InlineEditConditionToggle))
	bool bUseRunAccelerationCurve;

	UPROPERTY(EditDefaultsOnly, Category="Curve", meta=(EditCondition="bUseRunAccelerationCurve"))
	FRuntimeFloatCurve RunAccelerationCurve;

};

USTRUCT()
struct FOverrideMovementCurvesEntry : public FBaseMovementOverrideEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FOverrideMovementCurveData Override;

};

USTRUCT(BlueprintType)
struct FOverrideMovementInputData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	float MinDeflectionForRunning;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	float MinForwardForSprint;

};

USTRUCT()
struct FOverrideMovementInputEntry : public FBaseMovementOverrideEntry
{
	GENERATED_BODY()

};

USTRUCT()
struct FOverrideStepUpHeightEntry : public FBaseMovementOverrideEntry
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortPawnMovementOverridesSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Movement")
	void RegisterDirectionalSpeedMultiplierOverride(FGameplayTag Tag, const FDirectionalSpeedMultiplierOverrideData& Entry, int32 Priority);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void RegisterMeleeCombatSlowSpeedMultiplierOverride(FGameplayTag Tag, float MeleeCombatSlowSpeedMultiplier, int32 Priority);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void RegisterMovementCurvesOverride(FGameplayTag Tag, const FOverrideMovementCurveData& Data, int32 Priority);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void RegisterMovementInputOverride(FGameplayTag Tag, const FOverrideMovementInputData& Data, int32 Priority);

	UFUNCTION(BlueprintCallable, Category="PawnStats")
	void RegisterPawnStatsOverride(FGameplayTag Tag, FDataTableRowHandle Handle, int32 Priority);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void RegisterStepUpHeightOverride(FGameplayTag Tag, float StepUpHeight, int32 Priority);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void UnregisterDirectionalSpeedMultiplierOverride(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void UnregisterMeleeCombatSlowSpeedMultiplierOverride(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void UnregisterMovementCurvesOverride(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void UnregisterMovementInputOverride(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, Category="PawnStats")
	void UnregisterPawnStatsOverride(FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void UnregisterStepUpHeightOverride(FGameplayTag Tag);

private:
	UPROPERTY(Transient)
	TArray<FFortPawnStatsOverrideEntry> PawnStatsOverrides;

	UPROPERTY(Transient)
	TArray<FDirectionalSpeedMultiplierOverrideEntry> DirectionalSpeedMultiplierOverrides;

	UPROPERTY(Transient)
	TArray<FOverrideMovementCurvesEntry> MovementCurvesOverrides;

	UPROPERTY(Transient)
	TArray<FOverrideStepUpHeightEntry> StepUpHeightOverrides;

	UPROPERTY(Transient)
	TArray<FOverrideMeleeCombatSlowSpeedMultiplierEntry> MeleeCombatSlowSpeedMultiplierOverrides;

};

