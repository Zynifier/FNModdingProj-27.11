// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "FortQuestItemDefComponentTabbedView.generated.h"

class UCommonButtonGroupBase;
class UDataTable;
class UFortQuestItemDefComponentTabButton;
class UHorizontalBox;
class UNamedSlot;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentTabbedView : public UQuestEditorSubWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRefreshedComponentTabs(const bool bComponentsAvailable);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentTabbedView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Tab_Box;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentTabbedView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> Slot_ComponentEditor;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefComponentTabbedView")
	TSoftObjectPtr<UDataTable> ComponentEditorClasses;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefComponentTabbedView")
	TSubclassOf<UFortQuestItemDefComponentTabButton> ComponentTabButtonClass;

private:
	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> TabGroup;

};

