// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Creative/FortCreativeTypes.h"
#include "FortMinigameVolumeComponent.generated.h"

class AFortMinigame;
class AFortMinigameSettingsBuilding;
class AFortVolume;
class APlayerState;
class UFortMinigameVolumeComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMinigameSettingsMachineChanged, UFortMinigameVolumeComponent*, MinigameVolumeComponent, AFortMinigameSettingsBuilding*, NewMinigameSettingsMachine);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigameSetup, AFortMinigame*, Minigame);

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameVolumeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasReplicatedSettingsMachine() const;

	UFUNCTION()
	void OnClientEnterVolume(APlayerState* InPlayerState, AFortVolume* InVolume);

	UFUNCTION()
	void OnClientExitVolume(APlayerState* InPlayerState, AFortVolume* InVolume);

	UFUNCTION(BlueprintCallable)
	void SetMinigameSettingsMachine(AFortMinigameSettingsBuilding* NewMinigameSettingsMachine);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortMinigameVolumeComponent")
	TObjectPtr<AFortMinigameSettingsBuilding> CurrentMinigameSettingsMachine;

	UPROPERTY(BlueprintAssignable)
	FOnMinigameSettingsMachineChanged OnMinigameSettingsMachineChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMinigameSetup OnMinigameSetup;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Replicated, Category="FortMinigameVolumeComponent")
	TSubclassOf<AFortMinigame> MinigameClass;

private:
	UFUNCTION()
	void OnRep_CurrentMinigame();

	UFUNCTION()
	void OnRep_PublishedIslandCodeDisplay();

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_CurrentMinigame, Category="FortMinigameVolumeComponent")
	TWeakObjectPtr<AFortMinigame> CurrentMinigame;

	UPROPERTY(ReplicatedUsing=OnRep_PublishedIslandCodeDisplay)
	ECreativePublishedIslandCodeDisplay PublishedIslandCodeDisplay;

};

