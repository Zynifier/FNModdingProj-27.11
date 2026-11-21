// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHUDObjectiveSizeInterface.h"
#include "FortQuestTrackerList.generated.h"

class UCommonListView;
class UFortQuestItem;
class UObject;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestTrackerList : public UCommonUserWidget, public IFortHUDObjectiveSizeInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	TArray<UFortQuestItem*> GetQuestsToDisplay();

	UFUNCTION(BlueprintCallable, Category="Quests")
	TArray<UFortQuestItem*> GetVisibleQuestsToDisplay();

	UFUNCTION()
	void HandleHUDFinalObjectiveHidden(UFortQuestItem* QuestItem);

	UFUNCTION()
	void HandlePinnedQuestsChanged();

	UFUNCTION()
	void HandleQuestsUpdated();

	UFUNCTION()
	void HandleSizeEstimateChanged(UObject* ChangedElement);

	UPROPERTY(EditInstanceOnly, Category="Quests")
	bool bConfigureAsHUD;

	UPROPERTY(BlueprintReadOnly, Export, Category="Quests", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> QuestList;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestItem>> HUDCachedQuests;

	UPROPERTY()
	FOnSizeEstimateChanged OnSizeEstimateChangedDelegate;

	UPROPERTY()
	bool bHasHiddenItemsDueToSize;

};

