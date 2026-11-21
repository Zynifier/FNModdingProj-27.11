// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FortReplayMovableSpotLightPilotController.generated.h"

class AFortPlayerController;
class AFortReplayMovableSpotLight;
class UInputComponent;
class ULocalPlayer;

UCLASS(HideCategories=("Collision", "Rendering", "Transformation"))
class AFortReplayMovableSpotLightPilotController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void DestroyAllReplaySpotLights();

	UFUNCTION(Exec)
	void DestroyReplaySpotLight();

	UFUNCTION(Exec)
	void DuplicateReplaySpotLight();

	UFUNCTION()
	void GamepadLightColorSelectX(float Amt);

	UFUNCTION()
	void GamepadLightColorSelectY(float Amt);

	UFUNCTION(Exec)
	void LockAllReplaySpotLights();

	UFUNCTION(Exec)
	void PilotReplaySpotLight();

	UFUNCTION(Exec)
	void ReAimReplaySpotLight();

	UFUNCTION(Exec)
	void SelectNextSpotLight();

	UFUNCTION(Exec)
	void SelectPrevSpotLight();

	UFUNCTION(Exec)
	void SelectSpotLightByNumber(uint32 Number);

	UFUNCTION(Exec)
	void SetSpotLightGroupMoveLockByNumber(uint32 Number, bool bLocked);

	UFUNCTION(Exec)
	void SpawnReplaySpotLight();

	UFUNCTION(Exec)
	void SpawnReplaySpotLightEx(float X, float Y, float Z, float Yaw, float Pitch, int32 R, int32 G, int32 B, float InnerAngle, float OuterAngle, float Intensity, float Radius, float Temp);

	UFUNCTION(Exec)
	void ToggleLockReplaySpotLight();

	UPROPERTY()
	bool bMovingAllLights;

	UPROPERTY()
	bool bColorSelectMode;

	UPROPERTY()
	float Hue;

	UPROPERTY()
	float Saturation;

	UPROPERTY()
	float Value;

	UPROPERTY()
	float ColorInputX;

	UPROPERTY()
	float ColorInputY;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> LightColorSelectComponent;

	UPROPERTY()
	TObjectPtr<AFortReplayMovableSpotLight> PendingCurrentSpotLight;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> OriginalControllerRef;

	UPROPERTY()
	TObjectPtr<ULocalPlayer> OriginalPlayer;

	UPROPERTY(Transient)
	float TimeAccumulator;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debug Camera")
	float InitialMaxSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debug Camera")
	float InitialAccel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debug Camera")
	float InitialDecel;

};

