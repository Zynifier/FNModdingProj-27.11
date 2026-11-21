// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "Camera/FortCameraMode_FocalPoint.h"
#include "FortCameraMode_SpecialEventFocalPoint.generated.h"

class AActor;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortCameraMode_SpecialEventFocalPoint : public UFortCameraMode_FocalPoint
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Camera Mode")
	void SetOverrideTransitionTime(const float InTransitionTime);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Camera Mode", meta=(DisplayName="OnBecomeActive"))
	void OnBecomeActiveBP(AActor* ViewTarget);

	UFUNCTION(BlueprintImplementableEvent, Category="Camera Mode", meta=(DisplayName="OnBecomeInactive"))
	void OnBecomeInactiveBP(AActor* ViewTarget);

	UFUNCTION(BlueprintImplementableEvent, Category="Camera Mode", meta=(DisplayName="UpdateCamera"))
	void UpdateCameraBP(AActor* ViewTarget, float DeltaTime, UPARAM(ref) FTViewTarget& OutVT);

	UPROPERTY(EditDefaultsOnly, Category="Camera Mode")
	float OverrideTransitionTime;

};

