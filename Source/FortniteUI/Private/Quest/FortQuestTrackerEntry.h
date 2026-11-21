// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "FortHUDObjectiveSizeInterface.h"
#include "FortQuestTrackerEntry.generated.h"

class UCommonListView;
class UCommonTextBlock;
class UFortQuestItem;
class UFortQuestObjectiveInfo;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHUDQuestFinalObjectiveHidden, UFortQuestItem*, QuestItem);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestTrackerEntry : public UCommonUserWidget, public IUserObjectListEntry, public IFortHUDObjectiveSizeInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleHUDObjectiveCompletion(UFortQuestObjectiveInfo* QuestObjective);

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void OnSetup();

	UPROPERTY(BlueprintReadOnly, Export, Category="Quests", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> QuestNameText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Quests", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ObjectivesList;

	UPROPERTY(BlueprintReadOnly, Category="Quests")
	TObjectPtr<UFortQuestItem> TrackedQuest;

	UPROPERTY()
	FOnHUDQuestFinalObjectiveHidden OnHUDQuestFinalObjectiveHiddenDelegate;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> HUDCachedObjectiveInfos;

	UPROPERTY(BlueprintReadOnly, Category="Quests")
	bool bConfigureAsHUD;

	UPROPERTY()
	FOnSizeEstimateChanged OnSizeEstimateChangedDelegate;

};

