// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortQuestMapNodeLayout_Legacy.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UFortQuestMapScreen_Legacy;
class UPanelWidget;
class USizeBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortQuestMapNodeLayout_Legacy : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortQuestMapNodeLayout_Legacy(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandleQuestButtonSelected(UCommonButtonLegacy* SelectedQuestButton, int32 ButtonIndex);

	UFUNCTION()
	void HandleQuestIndexSelectionModelIndexChanged(bool bUpdateButtonSelection);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_NodeLayout;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> ButtonPrevious;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> ButtonNext;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> StartArrow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> EndArrow;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> QuestButtonGroup;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortQuestMapScreen_Legacy> ParentScreen;

};

