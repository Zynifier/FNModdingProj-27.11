// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "LevelSaveSpawnableInterface.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortCreativeStatManagerComponent.generated.h"

class UFortMinigamePlayerDefinedStatFilter;
class UFortMinigameStatsComponent;
class UTexture2D;

UCLASS(MinimalAPI, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeStatManagerComponent : public UActorComponent, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeStatManagerComponent")
	TObjectPtr<UFortMinigamePlayerDefinedStatFilter> StatFilter;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCreativeStatManagerComponent")
	FStatEventFilter StatEventFilter;

protected:
	UFUNCTION(BlueprintCallable)
	void RemovePlayerDefinedStat(UFortMinigameStatsComponent* MinigameStatsComponent);

	UFUNCTION(BlueprintCallable)
	void SetupPlayerDefinedStat(UFortMinigameStatsComponent* MinigameStatsComponent, const FText& StatName, const TSoftObjectPtr<UTexture2D>& HudIcon);

	UFUNCTION(BlueprintCallable)
	void UpdateStatProperties(UFortMinigameStatsComponent* MinigameStatsComponent, const FText& NewName, const TSoftObjectPtr<UTexture2D>& NewHudIcon);

	UPROPERTY(SaveGame)
	FGameplayTag StatTargetTag;

};

