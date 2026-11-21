// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SquadManagement/FortSquadManagementScreenBase.h"
#include "FortSurvivorSquadManagementScreen.generated.h"

class UFortSurvivorSquadStatMatchesBase;
class UFortWorker;

USTRUCT(BlueprintType)
struct FFortSurvivorSquadSlottingFeedbackData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortSurvivorSquadSlottingFeedbackData")
	bool HadLeaderMatch;

	UPROPERTY(BlueprintReadOnly, Category="FortSurvivorSquadSlottingFeedbackData")
	bool HasLeaderMatch;

	UPROPERTY(BlueprintReadOnly, Category="FortSurvivorSquadSlottingFeedbackData")
	TMap<FGameplayTag, int32> PreviousSetBonusCounts;

	UPROPERTY(BlueprintReadOnly, Category="FortSurvivorSquadSlottingFeedbackData")
	TMap<FGameplayTag, int32> CurrentSetBonusCounts;

	UPROPERTY(BlueprintReadOnly, Category="FortSurvivorSquadSlottingFeedbackData")
	int32 PreviousPersonalityMatchCount;

	UPROPERTY(BlueprintReadOnly, Category="FortSurvivorSquadSlottingFeedbackData")
	int32 CurrentPersonalityMatchCount;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSurvivorSquadManagementScreen : public UFortSquadManagementScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void PlayFeedbackForSlottingPerson(UFortWorker* Worker, int32 SlotIndex, const FFortSurvivorSquadSlottingFeedbackData& FeedbackData);

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void ShowHelpDialog();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void UpdateCycleButtons();

	UPROPERTY(BlueprintReadOnly, Export, Category="Squad Management Screen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSurvivorSquadStatMatchesBase> StatMatchesWidget;

};

