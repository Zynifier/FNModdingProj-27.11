// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortControllerComponent.h"
#include "FortMinigameManager.generated.h"

class AController;
class AFortMinigame;
class UObject;
enum class EFortQuestObjectiveStatEvent : uint8;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"))
class UFortMinigameManager : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	void GetSourceAndContextTags(FGameplayTagContainer& OutSourceTags, FGameplayTagContainer& OutContextTags) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SendStatEventWithTags(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count = 1);

protected:
	UPROPERTY(Transient)
	TObjectPtr<AController> OwningController;

	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> CurrentMinigame;

};

