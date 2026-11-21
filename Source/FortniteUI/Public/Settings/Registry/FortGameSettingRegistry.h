// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureStateChangeObserver.h"
#include "UObject/NoExportTypes.h"
#include "Settings/Registry/FortSettingRegistry.h"
#include "FortGameSettingRegistry.generated.h"

class UFortGameFeature_FortGameRegistryObserver;
class UFortSetting;
class UFortSettingCollection;
class UInputMappingContext;

UCLASS()
class UFortGameFeature_FortGameRegistryObserver : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS(Config=Game)
class UFortGameSettingRegistry : public UFortSettingRegistry
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleMappingContextRegistrationChanged(const UInputMappingContext* IMC);

protected:
	UPROPERTY()
	TObjectPtr<UFortSettingCollection> VideoSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> AudioSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> GameplaySettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> MouseAndKeyboardSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> MouseAndKeyboardBindings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> ControllerBindings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> ControllerSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> ControllerButtonMappingSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> TouchAndMotionSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> MobileWeaponSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> HUDSettings;

	UPROPERTY()
	TObjectPtr<UFortSettingCollection> AccountSettings;

	UPROPERTY()
	TObjectPtr<UFortSetting> FlickStickEnabledSetting;

	UPROPERTY(Config)
	bool bEnableColorCalibration;

	UPROPERTY(Transient)
	TObjectPtr<UFortGameFeature_FortGameRegistryObserver> GameRegistryObserver;

};

