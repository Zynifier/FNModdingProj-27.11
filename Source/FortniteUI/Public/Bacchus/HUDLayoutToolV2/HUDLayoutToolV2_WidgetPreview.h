// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_WidgetPreview.generated.h"

class UBorder;
class UCommonTextBlock;
class UCreateHUDWidgetDragDropOperation;
class UDragDropOperation;

UCLASS()
class UCreateHUDWidgetDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_WidgetPreview : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UCreateHUDWidgetDragDropOperation> CreateHUDWidgetOperation;

private:
	UFUNCTION()
	void HandleOperationDrop(UDragDropOperation* Operation);

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_WidgetPreview")
	float DragDistanceThresholdMillimeters;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_InstancesLeftCounter;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_Background;

};

