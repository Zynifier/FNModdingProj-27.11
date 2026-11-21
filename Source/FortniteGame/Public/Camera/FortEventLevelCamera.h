// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraBase.h"
#include "FortEventLevelCamera.generated.h"

class AActor;
class AFortEventLevelNavigationActor;
class ALevelSequenceActor;
class UFortGameStateComponent_EventLevel;
class UUserWidget;

USTRUCT()
struct FCameraSequence
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CameraSequence")
	TSoftObjectPtr<ALevelSequenceActor> CameraSequencer;

	UPROPERTY(EditAnywhere, Category="CameraSequence")
	bool PlayFromStart;

	UPROPERTY(EditAnywhere, Category="CameraSequence")
	bool UseCinematiceMode;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortEventLevelCamera : public AFortCameraBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void StartLevelTransition(bool bStreamIn);

	UFUNCTION(BlueprintCallable)
	void UpdateLevelLightSwitch(bool bTurnOn);

protected:
	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera", meta=(Categories="ERG.Camera"))
	FGameplayTag CameraTag;

	UPROPERTY(Transient, meta=(Categories="ERG.Camera"))
	FGameplayTag PreviousCamera;

	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera", meta=(Categories="ERG.Camera"))
	FGameplayTag BackOutCamera;

	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera")
	TSoftObjectPtr<AFortEventLevelNavigationActor> DefaultSelectedObject;

	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera")
	bool bRestorLastSelected;

	UPROPERTY(Transient)
	TSoftObjectPtr<AFortEventLevelNavigationActor> LastSelectedObject;

	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera")
	FViewTargetTransitionParams FallbackTransitionParams;

	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera")
	TMap<FGameplayTag, FCameraSequence> CameraTransitionParams;

	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera")
	TSoftObjectPtr<AActor> LightswitchToActivate;

	UPROPERTY(EditInstanceOnly, Category="FortEventLevelCamera")
	TSoftClassPtr<UUserWidget> SpatialScreenClass;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortEventLevelNavigationActor>> NavigationActorsToTurnOn;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortGameStateComponent_EventLevel> WeakDynamicLevelComp;

	UPROPERTY(Transient)
	FVector DefaultCameraLocation;

	UPROPERTY(Transient)
	FRotator DefaultCameraRotation;

};

