// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "Math/MathFwd.h"
#include "FortCameraModifier_Custom.generated.h"

class AActor;
class APlayerCameraManager;
class UFortCameraMode;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCameraModifier_Custom : public UCameraModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintAddedToCamera(APlayerCameraManager* Camera);

	UFUNCTION(BlueprintImplementableEvent)
	bool BlueprintProcessViewRotation(AActor* ViewTarget, float DeltaTime, FRotator InViewRotation, FRotator InDeltaRot, FRotator& OutViewRotation, FRotator& OutDeltaRot);

	UFUNCTION(BlueprintPure, Category="CameraModifier")
	FVector GetCameraLookAtLocation() const;

	UFUNCTION(BlueprintPure, Category="CameraModifier")
	UFortCameraMode* GetCameraModeInstance() const;

	UFUNCTION(BlueprintPure, Category="CameraModifier")
	FRotator GetCameraRotationInput() const;

	UFUNCTION(BlueprintPure, Category="CameraModifier")
	float GetTotalRotationInputClamped() const;

};

