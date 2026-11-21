// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_Tether.generated.h"

class APawn;
class UInputComponent;
class UMaterialInterface;
class USkeletalMesh;
class USkeletalMeshComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPawnComponent_Tether : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void DelayedSetViewTargetToTetherPawn();

	UFUNCTION()
	void GamepadTetheredExitAndReloadReleased();

	UFUNCTION()
	void OnRep_TetheredWithoutWeapon();

	UFUNCTION()
	void OnRep_TetherPawn();

	UFUNCTION(Server, Reliable)
	void ServerReleaseTether();

	UFUNCTION(Server, Reliable)
	void ServerRequestTetherJump();

	UFUNCTION()
	void SetViewTargetToTetherPawn();

	UFUNCTION()
	void TetheredBoostPressed();

	UFUNCTION()
	void TetheredBoostReleased();

	UFUNCTION()
	void TetheredExitPressed();

	UFUNCTION()
	void TetheredExitReleased();

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TetherPawn, Category="Tether")
	TWeakObjectPtr<APawn> TetherPawn;

	UPROPERTY(Transient)
	float TetherPawnSavedCullDistanceSquared;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_TetheredWithoutWeapon, Category="FortPawnComponent_Tether")
	bool bTetheredWithoutWeapon;

	UPROPERTY(Transient)
	bool bPressedTetheredBoost;

	UPROPERTY(Config)
	bool bAllowVehicleTether;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	FVector2D TetherSweetSpotRange;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	FVector2D TetherAccelerationRange;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherSlackLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherCatchupLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherViewPlayerLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherBreakLength;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetheredSpeedToBackOff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetheredMaxSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetheredMovementAccelBackOff;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetheredMovementAccelNudge;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetheredMovementGroundFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetheredMovementWaterFrictionMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetheredMovementMaxAccel;

	UPROPERTY(EditDefaultsOnly, Category="Tether")
	float SetViewTargetToTetherPawnDelayTime;

	UPROPERTY(EditDefaultsOnly, Category="Tether")
	float SetViewTargetToTetherPawnBlendTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherJumpServerCorrectionExpansionTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tether")
	float TetherInitialYankLaunchZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPawnComponent_Tether")
	TObjectPtr<UStaticMesh> TetherRopeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPawnComponent_Tether")
	TObjectPtr<UMaterialInterface> TetherRopeMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Export, Category="FortPawnComponent_Tether", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TetherRopeComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPawnComponent_Tether")
	TObjectPtr<USkeletalMesh> TetherRopeRodMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Export, Category="FortPawnComponent_Tether", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> TetherRopeRodComp;

	UPROPERTY(Transient)
	float TetherRightInput;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> TetheredInputComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPawnComponent_Tether")
	float TetheredExitHoldTime;

};

