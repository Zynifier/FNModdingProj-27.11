// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIStateChartEditorTransitionList.generated.h"

class UImage;
class UListView;
class UTextBlock;
class UTexture2D;
class UWidget;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorTransitionList : public UUserWidget
{
	GENERATED_BODY()

public:
	UUIStateChartEditorTransitionList(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorTransitionList")
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorTransitionList")
	bool StartExpanded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorTransitionList")
	TObjectPtr<UTexture2D> ExpandedArrowTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorTransitionList")
	TObjectPtr<UTexture2D> CollapsedArrowTexture;

protected:
	UFUNCTION(BlueprintCallable)
	void HandleAddButtonClicked();

	UFUNCTION(BlueprintCallable)
	void ToggleListExpanded();

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TitleTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> QuantityTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> AddButtonContainer;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> TransitionListView;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorTransitionList", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> ArrowIcon;

};

