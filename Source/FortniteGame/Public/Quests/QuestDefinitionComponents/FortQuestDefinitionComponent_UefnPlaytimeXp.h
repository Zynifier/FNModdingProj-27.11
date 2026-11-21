// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_UefnPlaytimeXp.generated.h"

class UFortQuestItemDefinition_Athena;

UENUM()
enum class EUefnPlaytimeQuestType : uint8
{
	// Should match enum defined in ProcessUefnPlaytimeXp.java

	Other = 0,
	XP = 1,
	LevelUp = 2,
};

USTRUCT()
struct FUefnPlaytimeBonusGoalData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UefnPlaytimeBonusGoalData")
	FString ObjectiveToComplete;

	UPROPERTY(EditDefaultsOnly, Category="UefnPlaytimeBonusGoalData")
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> BonusGoalsToProgressWhenCompleted;

};

UCLASS(BlueprintType, meta=(DisplayName="Uefn Playtime Xp Component"))
class UFortQuestDefinitionComponent_UefnPlaytimeXp : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortQuestDefinitionComponent_UefnPlaytimeXp")
	EUefnPlaytimeQuestType QuestType;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortQuestDefinitionComponent_UefnPlaytimeXp")
	TArray<FUefnPlaytimeBonusGoalData> BonusGoalData;
#endif

};

