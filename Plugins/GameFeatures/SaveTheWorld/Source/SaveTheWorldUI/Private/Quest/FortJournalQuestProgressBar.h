// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "FortJournalQuestProgressBar.generated.h"

class UFortQuestObjectiveInfo;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortJournalQuestProgressBar : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Quest Objective Info")
	void GetProgressDetails(FText& OutNumerator, FText& OutDenominator, float& OutFraction);

	UPROPERTY(BlueprintReadOnly, Category="Quest Objective Info")
	TWeakObjectPtr<UFortQuestObjectiveInfo> QuestObjectiveInfo;

};

