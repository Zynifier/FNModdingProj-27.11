// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraComponent.h"
#include "FortSpectatorCameraComponent.generated.h"

class AActor;
class AFortPlayerControllerSpectating;
class UCurveVector;
class UFortSpectateBlend;

UENUM(BlueprintType)
enum class EFortSpectatorBlendType : uint8
{
	None = 0,
	Orbit = 1,
	Default = 2,
};

UCLASS(Config=Game, HideCategories=("CameraSettings", "Mobility", "Rendering", "LOD", "Trigger", "PhysicsVolume"), HideFunctions=("SetFieldOfView", "SetAspectRatio"))
class UFortSpectatorCameraComponent : public UCineCameraComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetAutoCameraCutDistanceThreshold() const;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerSpectating> SpectatorController;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> IntendedViewTarget;

	UPROPERTY(Transient)
	TObjectPtr<UFortSpectateBlend> CurrentBlend;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Lens")
	TObjectPtr<UCurveVector> ScreenFringeFOVCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lens")
	float ZoomRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lens")
	float FocalLengthInterpSpeed;

private:
	UFUNCTION()
	void OnApertureSettingChanged(float NewAperture);

	UFUNCTION()
	void OnFocalLengthSettingChanged(float NewFocalLength);

};

