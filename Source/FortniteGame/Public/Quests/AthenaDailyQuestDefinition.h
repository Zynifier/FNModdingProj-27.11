// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/FortQuestItemDefinition_Athena.h"
#include "AthenaDailyQuestDefinition.generated.h"

class UFortQuestItemDefinition_Athena;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Mission", "Functionality", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "FortItemDefinition"))
class UAthenaDailyQuestDefinition : public UFortQuestItemDefinition_Athena
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestPack")
	FString Group;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="QuestPack")
	bool bIgnoreBucketRestrictions;
#endif

protected:
	UPROPERTY(EditAnywhere, Category="QuestPack")
	bool bSuppressed;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AthenaDailyQuestDefinition")
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> RemoveIfClaimed;
#endif

};

