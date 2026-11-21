// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "EndOfMatchQuestCategoryWidget.generated.h"

class UDynamicEntryBox;
class UEndOfMatchQuestEntryWidget;
class USizeBox;
class UWidgetSwitcher;

UENUM()
enum class EEndOfMatchQuestCategoryType : uint8
{
	Completed = 0,
	InProgress = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndOfMatchQuestCategoryPlayComplete);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEndOfMatchQuestCategoryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_CategoryType;

private:
	UFUNCTION()
	void MoveAllEntriesDown();

	UFUNCTION()
	void ShowNextUpdate();

	UFUNCTION()
	void StartFirstEntryIntro();

	UFUNCTION()
	void StartMoveEntriesDown(UEndOfMatchQuestEntryWidget* NextWidget);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> EntryBox_SizeBox;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_QuestUpdates;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UEndOfMatchQuestEntryWidget>> QuestWidgetsToShow;

};

