// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "EndOfMatchQuestUpdateWidget.generated.h"

class UAthenaChallengeRecapEntry;
class UCommonUserWidget;
class UDynamicEntryBox;
class UEndOfMatchQuestCategoryWidget;
class UFortQuestItem;
class UScrollBox;

USTRUCT()
struct FQuestRecapData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<UFortQuestItem> QuestItem;

	UPROPERTY()
	int32 LastKnownMcpValue;

	UPROPERTY()
	int32 AchivedCount;

	UPROPERTY()
	int32 RequiredCount;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEndOfMatchQuestUpdateWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void FinishedUpdateingQuests();

	UFUNCTION()
	void QuestUpdated(UFortQuestItem* InUpdateData);

	UFUNCTION(BlueprintImplementableEvent)
	void RunIntroAnim();

	UFUNCTION(BlueprintCallable)
	void TryToShowNextQuestUpdate(const bool bShouldStartShowingQuests = true);

protected:
	UFUNCTION()
	void HandleTileFocused(UCommonUserWidget* QuestEntry);

	UFUNCTION()
	void QuestUpdateCompleted(UAthenaChallengeRecapEntry* EntryWidget);

	UFUNCTION()
	void TryPlayCreatedWidgets();

	UPROPERTY(Transient)
	TArray<FQuestRecapData> QuestUpdates;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UEndOfMatchQuestCategoryWidget>> CreatedWidgets;

	UPROPERTY(EditDefaultsOnly, Category="EndOfMatchQuestUpdateWidget")
	int32 MaxNumQuestWidgets;

	UPROPERTY(EditInstanceOnly, Category="EndOfMatchQuestUpdateWidget")
	FGameplayTagContainer InclusiveFilterTags;

	UPROPERTY(EditInstanceOnly, Category="EndOfMatchQuestUpdateWidget")
	FGameplayTagContainer ExclusiveFilterTags;

private:
	UFUNCTION()
	void StartCategoryPlay(UEndOfMatchQuestCategoryWidget* CategoryWidget);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_QuestUpdates;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Quest;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UEndOfMatchQuestCategoryWidget> InProgressCategoryEntryWidget;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UEndOfMatchQuestCategoryWidget> CompletedCategoryEntryWidget;

};

