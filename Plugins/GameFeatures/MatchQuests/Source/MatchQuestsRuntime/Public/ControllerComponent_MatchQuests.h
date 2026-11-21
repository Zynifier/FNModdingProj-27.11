// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "ControllerComponent_MatchQuests.generated.h"

class IQuestDefinitionInterface;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class MATCHQUESTSRUNTIME_API UControllerComponent_MatchQuests : public UControllerComponent
{
	GENERATED_BODY()

public:
	UControllerComponent_MatchQuests(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void OnRep_QuestOffering() const;

	UFUNCTION(Server, Reliable)
	void Server_SetSelectedQuest(const TScriptInterface<IQuestDefinitionInterface>& Quest);

	UPROPERTY(ReplicatedUsing=OnRep_QuestOffering)
	TArray<TScriptInterface<IQuestDefinitionInterface>> QuestOffering;

};

