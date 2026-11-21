// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortCombatTypes.h"
#include "CombatManagerComponentSTW.generated.h"

class UReporterGraph;

USTRUCT()
struct FCombatEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FCombatEventData")
	float Heat;

	UPROPERTY(EditAnywhere, Category="FCombatEventData")
	float MaxHeatContribution;

	UPROPERTY(EditAnywhere, Category="FCombatEventData")
	float CoolDownRate;

	UPROPERTY(EditAnywhere, Category="FCombatEventData")
	FString EventName;

	UPROPERTY(EditAnywhere, Category="FCombatEventData")
	FLinearColor DebugGraphColor;

	UPROPERTY(EditAnywhere, Category="FCombatEventData")
	TEnumAsByte<EFortCombatEventContribution::Type> ContributionType;

};

USTRUCT()
struct FCombatEventMultiplier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CombatEvent")
	TEnumAsByte<EFortCombatEvents::Type> CombatEvent;

	UPROPERTY(EditAnywhere, Category="Multiplier")
	float MaxContribution;

};

USTRUCT()
struct FCombatFactorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FCombatFactorData")
	TArray<FCombatEventMultiplier> ContributingCombatEvents;

	UPROPERTY(EditAnywhere, Category="FCombatFactorData")
	float MaxValue;

	UPROPERTY(EditAnywhere, Category="FCombatFactorData")
	FString DebugFactorName;

	UPROPERTY(EditAnywhere, Category="FCombatFactorData")
	FLinearColor DebugGraphColor;

};

USTRUCT()
struct FCombatThresholdData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FCombatThresholdData")
	FScalableFloat HeatLevel;

	UPROPERTY(EditAnywhere, Category="FCombatThresholdData")
	FScalableFloat ExitHeatLevel;

	UPROPERTY(EditAnywhere, Category="FCombatThresholdData")
	FString ThresholdName;

	UPROPERTY(EditAnywhere, Category="FCombatThresholdData")
	FLinearColor DebugGraphColor;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UCombatManagerComponentSTW : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Combat")
	virtual float GetEventHeatPercent(EFortCombatEvents::Type CombatEvent);

	UFUNCTION(BlueprintPure, Category="Combat")
	virtual float GetEventHeatPercentTotal(EFortCombatEvents::Type CombatEvent);

	UFUNCTION()
	void OnRep_CombatEventHeat();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTriggerCombatEvent(EFortCombatEvents::Type TriggeredEvent, float HeatMultiplier);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTriggerCombatEventBatch(const TArray<FFortCombatManagerEvent>& Payload);

protected:
	UPROPERTY(ReplicatedUsing=OnRep_CombatEventHeat, meta=(ArraySizeEnum="/Script/FortniteGame.EFortCombatEvents"))
	float ReplicatedCombatEventHeat[28];

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortCombatEvents"))
	float CombatEventHeat[28];

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortCombatFactors"))
	float CombatFactors[12];

	UPROPERTY(Replicated)
	float CurrentTotalHeat;

	UPROPERTY(Replicated)
	float MaximumTotalHeat;

	UPROPERTY(Replicated)
	float MaxHeatEver;

	UPROPERTY(Transient)
	TObjectPtr<UReporterGraph> CombatGraph;

	UPROPERTY(Transient)
	TObjectPtr<UReporterGraph> FactorGraph;

	UPROPERTY(EditAnywhere, Category="CombatEvents", meta=(ArraySizeEnum="/Script/FortniteGame.EFortCombatEvents"))
	FCombatEventData Events[28];

	UPROPERTY(EditAnywhere, Category="CombatFactors", meta=(ArraySizeEnum="/Script/FortniteGame.EFortCombatFactors"))
	FCombatFactorData Factors[12];

	UPROPERTY(EditAnywhere, Category="CombatThresholds", meta=(ArraySizeEnum="/Script/FortniteGame.EFortCombatThresholds"))
	FCombatThresholdData Thresholds[4];

};

