// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "FortQuestItemDefComponentsWidget.generated.h"

class UFortActiveComponentWidget;
class UHorizontalBox;

UENUM()
enum class EObjectTypeUsability : uint8
{
	// Can be used

	Allowed = 0,
	// cannot be used because the class wouldn't be a valid dependency for the quest asset

	BlockedInvalidDependency = 1,
	// cannot be used because the class is excluded by game experience filtering

	BlockedGameExperienceFiltering = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentsWidget : public UQuestEditorSubWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OpenComponentsMenu();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentsWidget", meta=(BindWidget, EditInline="true"))
	UHorizontalBox* HorizontalBox_ActiveComponents;

	UPROPERTY(EditAnywhere, Category="FortQuestItemDefComponentsWidget")
	TSubclassOf<UFortActiveComponentWidget> ActiveComponentTextWidgetClass;

};

