// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "FortCustomCameraController.generated.h"

class AFortCustomCameraController;
class AFortPlayerCameraBase;
class AFortPlayerPawn;
class UCameraModifier;
class UFortCameraMode;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnControllerStateChange, const AFortCustomCameraController*, CameraController);

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class FORTNITEGAME_API AFortCustomCameraController : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortCameraMode* GetCameraModeInstance() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCustomModeChanged(const bool bIsEnabled);

	UFUNCTION(BlueprintCallable)
	void SetCustomCameraEnabled(const bool bEnable);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCustomCameraController")
	TSubclassOf<UFortCameraMode> CustomCameraModeClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCustomCameraController")
	FGameplayTag CameraModeTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortCustomCameraController")
	int32 CameraPriority;

	UPROPERTY(BlueprintReadOnly, Category="FortCustomCameraController")
	AFortPlayerPawn* FortPawn;

	UPROPERTY(BlueprintReadOnly, Category="FortCustomCameraController")
	AFortPlayerCameraBase* FortPlayerCamera;

	UPROPERTY(BlueprintReadWrite, Category="FortCustomCameraController")
	FOnControllerStateChange OnControllerActivated;

	UPROPERTY(BlueprintReadWrite, Category="FortCustomCameraController")
	FOnControllerStateChange OnControllerDeactivated;

	UPROPERTY(BlueprintReadWrite, Category="FortCustomCameraController")
	FOnControllerStateChange OnControllerEnabled;

	UPROPERTY(BlueprintReadWrite, Category="FortCustomCameraController")
	FOnControllerStateChange OnControllerDisabled;

protected:
	UFUNCTION()
	virtual void AllowCustomCameraMode();

	UFUNCTION()
	virtual void OnRep_IsCustomCameraModeEnabled();

	UFUNCTION()
	virtual void RestrictCustomCameraMode();

	UPROPERTY(ReplicatedUsing=OnRep_IsCustomCameraModeEnabled)
	bool bIsCustomCameraModeEnabled;

	UPROPERTY(EditAnywhere, Category="FortCustomCameraController")
	TArray<TSubclassOf<UCameraModifier>> CameraModifiersList;

	UPROPERTY(BlueprintReadOnly, Category="FortCustomCameraController")
	TArray<UCameraModifier*> CameraModifiersInstances;

	UPROPERTY(BlueprintReadOnly, Category="FortCustomCameraController")
	TMap<TSubclassOf<UCameraModifier>, TObjectPtr<UCameraModifier>> CameraModifierInstanceMap;

};

