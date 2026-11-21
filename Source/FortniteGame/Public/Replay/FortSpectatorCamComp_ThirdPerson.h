// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Replay/FortReplayTypes.h"
#include "Replay/FortSpectatorCameraComponent.h"
#include "FortSpectatorCamComp_ThirdPerson.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFortChaseCameraHelper
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	FTransform PivotToViewTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	FTransform PivotToViewTarget_Crouching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	FTransform MinCameraToPivot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	FTransform MaxCameraToPivot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float CameraToPivotAlphaInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float CameraCollisionSphereRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float PivotLocationInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float PivotRotationInterpSpeed;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> IgnoreActors;

	UPROPERTY(BlueprintReadOnly, Category="ChaseCamera")
	EThirdPersonAutoFollowMode AutoFollowMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float CameraTruckRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float AutoFollowPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float LazyAutoFollowPitchMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChaseCamera")
	float LazyAutoFollowPitchMax;

};

UCLASS(HideCategories=("CameraSettings", "Mobility", "Rendering", "LOD", "Trigger", "PhysicsVolume"), HideFunctions=("SetFieldOfView", "SetAspectRatio"))
class UFortSpectatorCamComp_ThirdPerson : public UFortSpectatorCameraComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnNormalizedDistanceChanged(float NewDistance);

};

