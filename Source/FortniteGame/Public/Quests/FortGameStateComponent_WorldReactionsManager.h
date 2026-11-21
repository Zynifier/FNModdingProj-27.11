// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortGameStateComponent_WorldReactionsManager.generated.h"

class UDataTable;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWorldStateChangeSignature);

USTRUCT()
struct FFortWorldReactionData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ReactionRowName;

	UPROPERTY()
	bool bReactionsTriggered;

};

USTRUCT()
struct FFortWorldReactionDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortWorldReactionData> WorldReactions;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_WorldReactionsManager : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_WorldReactionsManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_WorldReactionsManager", meta=(RowType="/Script/FortniteGame.FortEventReactionsTableRow"))
	TArray<TObjectPtr<UDataTable>> WorldReactionsTables;

	UPROPERTY(Transient, Replicated)
	FFortWorldReactionDataArray WorldReactionsArray;

	UPROPERTY(Transient, Replicated)
	FGameplayTagContainer DebugWorldStates;

};

