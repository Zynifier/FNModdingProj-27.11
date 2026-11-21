// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Quests/FortQuestTypes.h"
#include "FortItemToQuestData.generated.h"

USTRUCT(BlueprintType)
struct FFortItemToQuestData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortItemToQuestData")
	FString ItemTemplateID;

	UPROPERTY(EditDefaultsOnly, Category="FortItemToQuestData")
	FString QuestTemplateID;

	UPROPERTY(EditDefaultsOnly, Category="FortItemToQuestData")
	EFortQuestState QuestGrantState;

};

