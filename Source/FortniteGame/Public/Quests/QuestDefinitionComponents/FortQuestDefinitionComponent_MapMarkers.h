// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_MapMarkers.generated.h"

USTRUCT()
struct FObjectiveExtensionMapMarkers : public FObjectiveExtensionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveExtensionMapMarkers")
	FGameplayTag ObjectiveIconOverride;

	UPROPERTY(EditAnywhere, Category="ObjectiveExtensionMapMarkers")
	FGameplayTagContainer QuestObjectiveLocationTags;

};

UCLASS(MinimalAPI, BlueprintType, meta=(DisplayName="Map Markers"))
class UFortQuestDefinitionComponent_MapMarkers : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_MapMarkers")
	FGameplayTag IconOverride;

	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_MapMarkers")
	FGameplayTagContainer QuestItemDefLocationTags;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_MapMarkers")
	FName MapName;
#endif

};

