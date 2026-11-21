// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCameraMode_Custom.generated.h"

class AActor;
class AFortPlayerPawn;
class UFortCameraDeadZone;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCameraMode_Custom : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AttemptSetMovementRetention(AFortPlayerPawn* FortPawn, const bool bShouldRetain);

	UFUNCTION(BlueprintCallable)
	void ClearCameraRotationOverride();

	UFUNCTION(BlueprintCallable)
	void ClearControlRotationOverride();

	UFUNCTION(BlueprintCallable)
	void ClearViewRotationOverride();

	UFUNCTION(BlueprintPure)
	FVector GetCameraLookAtLocation() const;

	UFUNCTION(BlueprintPure)
	bool GetCameraRotationOverride(FRotator& OutRotation) const;

	UFUNCTION(BlueprintPure)
	bool GetControlRotationOverride(FRotator& OutRotation) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBecomeActiveBP(AActor* ViewTarget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBecomeInactiveBP(AActor* ViewTarget);

	UFUNCTION(BlueprintCallable)
	void SetCameraRotationOverride(const FRotator& InRotation);

	UFUNCTION(BlueprintCallable)
	void SetControlRotationOverride(const FRotator& InRotation);

	UFUNCTION(BlueprintCallable)
	void SetViewRotationOverride(const FRotator& InRotation);

	UFUNCTION(BlueprintCallable)
	void UpdateDeadZone(UFortCameraDeadZone* InDeadZone);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Instanced, Category="FortCameraMode_Custom")
	UFortCameraDeadZone* DeadZone;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Custom")
	float MovementRetentionToleranceAngleDeg;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Custom")
	float MovementRetentionToleranceLength;

	UPROPERTY(EditDefaultsOnly, Category="FortCameraMode_Custom")
	bool bUseConstantControlRotation;

};

