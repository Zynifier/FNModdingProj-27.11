// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistryId.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_MilestoneQuests.generated.h"

class AFortGameStateAthena;
class IQuestDefinitionInterface;
class UFortPlaylist;

USTRUCT(BlueprintType)
struct FMilestoneQuestTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MilestoneQuestTableRow")
	TScriptInterface<IQuestDefinitionInterface> Quest;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_MilestoneQuests : public UFortGameStateComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& GameplayTags);

	UPROPERTY(Config)
	FDataRegistryType DataRegistryType_SeasonalMilestoneQuests;

};

