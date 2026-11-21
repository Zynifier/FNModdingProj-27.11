// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FortMinigameInfoViewModel.generated.h"

class AFortMinigame;
class AFortMinigameSettingsBuilding;
class UFortMinigameVolumeComponent;
enum class EFortMinigameState : uint8;

UCLASS(BlueprintType, meta=(MVVMAllowedContextCreationType="Manual"))
class UFortMinigameInfoViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AFortMinigame* GetMinigame() const;

	UFUNCTION(BlueprintPure)
	AFortMinigameSettingsBuilding* GetMinigameSettings() const;

	UFUNCTION(BlueprintPure)
	EFortMinigameState GetMinigameState() const;

	UFUNCTION(BlueprintPure)
	UFortMinigameVolumeComponent* GetMinigameVolumeComponent() const;

	UFUNCTION(BlueprintCallable)
	void InitializeViewModel();

	UFUNCTION(BlueprintCallable)
	void UnbindViewModel();

private:
	UFUNCTION()
	void HandleMinigameSettingsMachineChanged(UFortMinigameVolumeComponent* MinigameVolumeComponent, AFortMinigameSettingsBuilding* MinigameSettings);

	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

};

