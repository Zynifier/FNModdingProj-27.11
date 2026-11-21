// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_CustomCamera.generated.h"

class AFortCustomCameraController;
class AFortPlayerPawnAthena;
class UObject;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class FORTNITEGAME_API UFortPawnComponent_CustomCamera : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ActivateCameraController();

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="ContextObject", HidePin="ContextObject"))
	void DisableCameraController(UObject* ContextObject, const bool bRefreshActiveCameraController = true);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="ContextObject", HidePin="ContextObject"))
	void EnableCameraController(UObject* ContextObject, const bool bRefreshActiveCameraController = true);

	UFUNCTION(BlueprintPure)
	AFortCustomCameraController* GetCurrentCameraController() const;

	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="ContextObject", HidePin="ContextObject"))
	AFortCustomCameraController* GetCustomCameraController(UObject* ContextObject) const;

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="ContextObject", HidePin="ContextObject"))
	void PopCameraController(UObject* ContextObject, const bool bRefreshActiveCameraController = true);

	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="ContextObject", HidePin="ContextObject"))
	AFortCustomCameraController* PushCameraController(UObject* ContextObject, const TSubclassOf<AFortCustomCameraController> CameraControllerClass, const float Priority, const bool bEnabled = true, const bool bRefreshActiveCameraController = true);

protected:
	UFUNCTION()
	virtual void OnRep_CurrentCameraController();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentCameraController)
	TObjectPtr<AFortCustomCameraController> CurrentCameraController;

private:
	UFUNCTION()
	void OnFortPlayerDied(AFortPlayerPawnAthena* PlayerPawnAthena);

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortCustomCameraController> LastCameraController;

};

