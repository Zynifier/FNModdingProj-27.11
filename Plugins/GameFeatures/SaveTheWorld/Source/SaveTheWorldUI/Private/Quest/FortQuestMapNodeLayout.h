// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortQuestMapNodeLayout.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UFortQuestMapScreen;
class UPanelWidget;
class USizeBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortQuestMapNodeLayout : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortQuestMapNodeLayout(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandleQuestButtonSelected(UCommonButtonBase* SelectedQuestButton, int32 ButtonIndex);

	UFUNCTION()
	void HandleQuestIndexSelectionModelIndexChanged(bool bUpdateButtonSelection);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_NodeLayout;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> ButtonPrevious;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> ButtonNext;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> StartArrow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> EndArrow;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> QuestButtonGroup;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortQuestMapScreen> ParentScreen;

};

