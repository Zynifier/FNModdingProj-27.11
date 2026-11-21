// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "UIStateChartEditorTransitionItem.generated.h"

class UMenuAnchor;
class UTextBlock;
class UUIStateChartEditorTransitionInfo;
class UUIStateChartEditorTransitionOptionsMenu;
class UUIStateChartEditorWidget;
class UWidget;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorTransitionItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UUIStateChartEditorTransitionItem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	void HandleOptionsMenuCreated(UUIStateChartEditorTransitionOptionsMenu* InMenu);

	UFUNCTION(BlueprintCallable)
	void HandleSourceClicked();

	UFUNCTION(BlueprintCallable)
	void HandleTargetClicked();

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> EditMenu;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> SourceRow;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> TargetRow;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TriggerTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> SourceTextBlock;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="UIStateChartEditorTransitionItem", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TargetTextBlock;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateChartEditorWidget> StateChartEditor;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartEditorTransitionInfo> TransitionInfo;

};

