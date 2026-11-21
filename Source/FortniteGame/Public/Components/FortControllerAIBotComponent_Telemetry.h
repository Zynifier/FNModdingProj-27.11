// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent_Telemetry.h"
#include "Components/FortPawnComponent_Disguise.h"
#include "FortControllerAIBotComponent_Telemetry.generated.h"

USTRUCT()
struct FFortControllerAIBotComponentTelemetryData_Damage
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<float> IdleDetectionBucketsCutoffs;

	UPROPERTY(Transient)
	TArray<float> DamageDistanceBuckets;

	UPROPERTY(Transient)
	TArray<int32> NumberOfHitsIdleDetection;

};

USTRUCT()
struct FFortControllerAIBotComponentTelemetryData_Disguise
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	bool bWasDisguised;

	UPROPERTY(Transient)
	bool bWasRevealed;

	UPROPERTY(Transient)
	EFortPawnComponent_DisguiseRevealReason RevealReason;

};

USTRUCT()
struct FFortControllerAIBotComponentTelemetryData_PassiveHealer
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	bool bIsPassiveHealer;

	UPROPERTY(Transient)
	int32 InteractionCount;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerAIBotComponent_Telemetry : public UFortControllerComponent_Telemetry
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FFortControllerAIBotComponentTelemetryData_Disguise TelemetryDataDisguise;

	UPROPERTY(Transient)
	FFortControllerAIBotComponentTelemetryData_PassiveHealer TelemetryDataPassiveHealer;

	UPROPERTY(Transient)
	FFortControllerAIBotComponentTelemetryData_Damage TelemetryDataDamage;

};

