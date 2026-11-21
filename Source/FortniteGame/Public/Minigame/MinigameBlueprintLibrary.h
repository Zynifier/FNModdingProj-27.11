// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MinigameBlueprintLibrary.generated.h"

class AActor;
class AFortMinigame;
class AFortMinigameSettingsBuilding;
class AFortPlayerController;
class UActorComponent;
class UFortMinigameStatsComponent;
class UFortMinigameVolumeComponent;

UCLASS(BlueprintType, Blueprintable)
class UMinigameBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Minigame")
	static bool CanOperateOnMinigame(const AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	static UActorComponent* GetComponentFromCurrentMinigameExperience(const AActor* ContextActor, TSubclassOf<UActorComponent> ComponentClass);

	UFUNCTION(BlueprintPure, Category="Minigame")
	static AFortMinigame* GetMinigame(const AActor* ContextActor);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	static AFortMinigame* GetMinigameForActor(const AActor* Actor);

	UFUNCTION(BlueprintPure, Category="Minigame")
	static AFortMinigameSettingsBuilding* GetMinigameSettingsMachine(const AActor* ContextActor);

	UFUNCTION(BlueprintCallable, Category="Minigame", meta=(DisplayName="GetMinigameSettingsMachine_NotPure"))
	static AFortMinigameSettingsBuilding* GetMinigameSettingsMachine_NotPure(const AActor* ContextActor);

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	static UFortMinigameStatsComponent* GetMinigameStatsComponent(const AActor* ContextActor);

	UFUNCTION(BlueprintPure, Category="Minigame")
	static UFortMinigameVolumeComponent* GetMinigameVolumeComponent(const AActor* ContextActor);

	UFUNCTION(BlueprintPure, Category="Minigame")
	static bool IsInPlayMode(const AActor* ContextActor);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	static bool IsMingameExperienceReady(const AActor* ContextActor);

};

