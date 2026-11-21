// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Layout/Margin.h"
#include "ClassSelectorTabButtons.generated.h"

class UClassSelectorTeamTile;
class UCommonActionWidget;
class UCommonButtonBase;
class UScrollBox;

UCLASS(Abstract)
class UClassSelectorTabButtons : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="ClassSelectorTabButtons", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> LeftActionWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="ClassSelectorTabButtons", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> RightActionWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="ClassSelectorTabButtons", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> TabButtonsScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="ClassSelectorTabButtons", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> LeftButton;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="ClassSelectorTabButtons", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> RightButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassSelectorTabButtons")
	FDataTableRowHandle LeftInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ClassSelectorTabButtons")
	FDataTableRowHandle RightInputAction;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UClassSelectorTeamTile>> TabButtons;

	UPROPERTY(EditAnywhere, Category="ClassSelectorTabButtons")
	TSubclassOf<UClassSelectorTeamTile> TabButtonClass;

	UPROPERTY(EditAnywhere, Category="ClassSelectorTabButtons")
	FMargin TabButtonPadding;

	UPROPERTY(EditAnywhere, Category="ClassSelectorTabButtons")
	TArray<FText> DesignerPreviewTabNames;

	UPROPERTY(EditAnywhere, Category="ClassSelectorTabButtons", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float ButtonScrollAmount;

};

