// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "Components/FortGameStateComponent.h"
#include "Quests/IFortQuestInstanceManagerInterface.h"
#include "Quests/QuestTypes.h"
#include "FortGameStateComponent_Quests.generated.h"

class AFortPlayerController;

USTRUCT()
struct FFortQuestPostUpdateTick : public FActorTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FFortQuestPostUpdateTick> : public TStructOpsTypeTraitsBase2<FFortQuestPostUpdateTick>
{
	enum
	{
		WithCopy = false
	};
};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_Quests : public UFortGameStateComponent, public IFortQuestInstanceManagerInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerController>> PlayersReceivingStatEvents;

private:
	UPROPERTY(Transient, Replicated)
	FFortGrantedQuestDataArray GrantedQuestDataArray;

	UPROPERTY(Transient, Replicated)
	FUpdatedQuestObjectiveDataArray UpdatedQuestObjectivesArray;

};

