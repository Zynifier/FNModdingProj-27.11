// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaMiniChallenges.generated.h"

class UDynamicEntryBox;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaMiniChallenges : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void AddQuestDetails(const FText& QuestDescription, int32 AchivedCount, int32 GoalCount);

	UFUNCTION(BlueprintImplementableEvent)
	void ClearQuestDescriptions();

	UFUNCTION(BlueprintImplementableEvent)
	void InspectModeEnabled(bool bEnabled);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_MiniChallenges;

	UPROPERTY(EditAnywhere, Category="AthenaMiniChallenges")
	bool bPlacedAtEndOfMatch;

	UPROPERTY(Transient)
	int32 UpdatingWidgets;

};

