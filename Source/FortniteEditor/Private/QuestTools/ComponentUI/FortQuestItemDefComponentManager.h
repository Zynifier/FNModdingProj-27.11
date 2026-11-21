// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/EditorQuestToolUtilityWidget.h"
#include "FortQuestItemDefComponentManager.generated.h"

class UButton;
class UCommonTextBlock;
class UFortQuestDefinitionComponent;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentManager : public UEditorQuestToolUtilityWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentManager", meta=(BindWidget, EditInline="true"))
	UButton* Button_ComponentStatus;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentManager", meta=(BindWidget, EditInline="true"))
	UCommonTextBlock* Text_ComponentStatus;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentManager", meta=(BindWidget, EditInline="true"))
	UImage* Image_ComponentStatus;

	UPROPERTY(EditInstanceOnly, Category="FortQuestItemDefComponentManager")
	TSubclassOf<UFortQuestDefinitionComponent> QuestItemDefComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefComponentManager")
	FText EnableText;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestItemDefComponentManager")
	FText DisableText;

private:
	UFUNCTION()
	void HandleComponentStatusButtonClicked();

};

