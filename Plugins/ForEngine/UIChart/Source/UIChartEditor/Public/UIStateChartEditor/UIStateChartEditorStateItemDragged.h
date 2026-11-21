// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "UIStateChartEditorStateItemDragged.generated.h"

class UBorder;
class UTextBlock;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorStateItemDragged : public UUserWidget
{
	GENERATED_BODY()

public:
	UUIStateChartEditorStateItemDragged(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItemDragged")
	FLinearColor NormalDragColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItemDragged")
	FLinearColor ValidTargetColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UIStateChartEditorStateItemDragged")
	FLinearColor InvalidTargetColor;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItemDragged", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> BackgroundBorder;

	UPROPERTY(BlueprintReadOnly, Export, Category="UIStateChartEditorStateItemDragged", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> StateNameTextBlock;

	UPROPERTY(Transient)
	FText StateNameString;

	UPROPERTY(Transient)
	TSet<uint32> CurrentValidTargets;

	UPROPERTY(Transient)
	TSet<uint32> CurrentInvalidTargets;

};

