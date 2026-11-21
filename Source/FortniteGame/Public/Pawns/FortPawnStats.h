// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Pawns/FortPawnTypes.h"
#include "FortPawnStats.generated.h"

class UCurveTable;

USTRUCT(BlueprintType)
struct FFortPawnStats : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float MaximumHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedWalk;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedRun;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedSprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedFly;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedRidden;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedCrouchedRun;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedCrouchedSprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedBackwardsMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float SpeedClassicDBNO;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float AccelerationStrafeMultiplierSprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float MinAnalogWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float GroundFriction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float BrakingDecelerationWalking;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float BrakingDecelerationFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float BrakingDecelerationFlying;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float BrakingFrictionFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float MaxAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float MaxAccelerationFlying;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float JumpZVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	TObjectPtr<UCurveTable> FallingDamageTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	FName FallingDamageTableRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	TObjectPtr<UCurveTable> VehicleEjectDamageTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float HealthRegenRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float HealthRegenDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float HealthRegenThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float MaxShield;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float ShieldRegenRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float ShieldRegenDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float ShieldRegenThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float MaxOvershield;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float MaxControlResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float ControlResistanceRegenRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float ControlResistanceRegenDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float ControlResistanceRegenThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float KnockbackMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float KnockbackThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	float PawnDamagedTeamNotificationDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	bool bAllowChainStun;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	EFortControlRecoveryBehavior ControlRecoveryBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats", meta=(Categories="Curie.Material", DataTableImportOptional))
	FGameplayTag CurieMaterialIdentifier;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortPawnStats")
	FString CurieMaterialIdentifierString;
#endif

};

