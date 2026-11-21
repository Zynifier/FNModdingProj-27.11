// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_ContextualChallenges.generated.h"

class AController;
class UFortQuestItem;
enum class EContextualContext : uint8;

UENUM()
enum class EContextualContext : uint8
{
	// warmup, etc

	DoNotShow = 0,
	// land at/visit - might eventually be dynamic?

	BusPhase = 1,
	Skydiving = 2,
	Gameplay = 3,
};

UENUM()
enum class EContextualEvent : uint8
{
	Generic = 0,
	Location = 1,
	InventoryAdded = 2,
	InventoryRemoved = 3,
	// really, the only special one - here we want to surface visit/land objectives.

	StartSkydiving = 4,
	// when we get new quests

	NewQuests = 5,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInvalidateContextualObjectives);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewContextualObjectives, const TArray<UFortQuestItem*>&, NewQuestItems);

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_ContextualChallenges : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(Client, Reliable)
	void ClientSetContext(EContextualContext NextContext);

	UFUNCTION()
	void FirstTimePlayerLanded(const FHitResult& Hit);

	UFUNCTION()
	void GenericAircraftUpdate(AController* InController);

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> SortedContextualObjectives;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> ContextualObjectivesToProcess;

};

