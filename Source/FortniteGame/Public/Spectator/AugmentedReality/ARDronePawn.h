// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/HoverDronePawn.h"
#include "ARDronePawn.generated.h"

class UARScreenCaptureComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMediaPlayer;
class UMotionControllerComponent;
class USceneCaptureComponent2D;
class USceneComponent;

UCLASS(HideCategories=("Navigation"))
class AARDronePawn : public AHoverDronePawn
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void ScaleIn();

	UFUNCTION()
	void ScaleOut();

	UFUNCTION()
	void StopScaling();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> ARRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> WebcamRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> WebcamRotRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> ScreenRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> MotionBase;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<UMotionControllerComponent> MotionController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<USceneCaptureComponent2D> POVCaptureComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<UARScreenCaptureComponent> ScreenCaptureComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ARDronePawn", meta=(EditInline="true"))
	TObjectPtr<USceneCaptureComponent2D> ARCapture;

	UPROPERTY(EditDefaultsOnly, Category="ARDronePawn")
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY(EditDefaultsOnly, Category="ARDronePawn")
	int32 MediaPlayerVideoFormatIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ARDronePawn")
	float WorldToMetersMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ARDronePawn")
	TObjectPtr<UMaterialInterface> ARPostProcessMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> ARPostProcessMID;

};

