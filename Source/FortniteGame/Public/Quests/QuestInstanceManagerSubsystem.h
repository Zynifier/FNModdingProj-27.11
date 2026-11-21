// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Quests/IQuestInstanceManagerInterfaceBlueprintParameters.h"
#include "QuestInstanceManagerSubsystem.generated.h"

class IQuestInstanceInterface;

UCLASS()
class FORTNITEGAME_API UQuestInstanceManagerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, meta=(AutoCreateRefTerm="Parameters"))
	TScriptInterface<IQuestInstanceInterface> GrantQuest(const FGrantQuestBlueprintParameters& Parameters) const;

};

