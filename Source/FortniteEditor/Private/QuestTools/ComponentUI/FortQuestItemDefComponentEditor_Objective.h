// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/ComponentUI/FortQuestItemDefComponentEditor.h"
#include "FortQuestItemDefComponentEditor_Objective.generated.h"

class UButton;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentEditor_Objective : public UFortQuestItemDefComponentEditor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void HandleAddObjectiveExtension();

	UFUNCTION()
	virtual void HandleRemoveObjectiveExtension();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_Objective", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_AddObjectiveExtensionData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_Objective", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> Button_RemoveObjectiveExtensionData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor_Objective", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AddExtensionData;

};

