// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Quests/FortQuestTypes.h"
#include "FortQuestAchievementData.generated.h"

USTRUCT(BlueprintType)
struct FFortQuestAchievementTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestAchievementTableRow")
	EFortQuestState QuestState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestAchievementTableRow")
	int32 XboxAchievementID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestAchievementTableRow")
	int32 PS4TrophyID;

};

