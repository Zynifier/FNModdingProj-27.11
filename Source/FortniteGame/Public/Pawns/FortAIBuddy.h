// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Pawns/FortAIPawn.h"
#include "FortAIBuddy.generated.h"

class AActor;
class AFortPlayerPawn;
class UFortWorldItemDefinition;

USTRUCT()
struct FFortBuddyTagListener
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> Actor;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Movement", "Actor", "Movement", "Game|Damage", "Navigation"))
class AFortAIBuddy : public AFortAIPawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddTagListener(AActor* TargetActor, const FGameplayTag Tag);

	UFUNCTION(BlueprintCallable)
	void RemoveTagListener(AActor* TargetActor, const FGameplayTag Tag);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FText GetInteractionString(const AFortPlayerPawn* PlayerPawn) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemsConsumed(const AFortPlayerPawn* PlayerPawn, int32 ItemsConsumed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemsDrained(const AFortPlayerPawn* PlayerPawn, int32 ItemsDrained);

	UFUNCTION(BlueprintImplementableEvent)
	void OnListenTagAdded(const AActor* TargetActor, const FGameplayTag Tag);

	UFUNCTION(BlueprintImplementableEvent)
	void OnListenTagRemoved(const AActor* TargetActor, const FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool StartItemDrain(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StopItemDrain();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIBuddy")
	TObjectPtr<UFortWorldItemDefinition> ConsumableItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIBuddy")
	FScalableFloat ConsumableItemCount;

	UPROPERTY()
	TObjectPtr<AFortPlayerPawn> DrainPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIBuddy")
	TObjectPtr<UFortWorldItemDefinition> DrainItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIBuddy")
	FScalableFloat DrainItemCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIBuddy")
	FScalableFloat DrainItemTick;

	UPROPERTY()
	TArray<FFortBuddyTagListener> TagListeners;

};

