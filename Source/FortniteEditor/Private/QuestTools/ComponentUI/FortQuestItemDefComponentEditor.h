// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "QuestTools/EditorQuestToolUtilityWidget.h"
#include "FortQuestItemDefComponentEditor.generated.h"

class UCommonTextBlock;
class UCustomPropertyView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestItemDefComponentEditor : public UEditorQuestToolUtilityWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCustomPropertyView> PropertyView_ComponentProperties;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestItemDefComponentEditor", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ComponentName;

	UPROPERTY()
	FInstancedStruct ComponentEditorDataInstanced;

};

