// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelSlot.h"
#include "Components/PanelWidget.h"
#include "FortRelativeAnchorCanvas.generated.h"

class UFortRelativeAnchorCanvasSlot;
class UWidget;

UCLASS(BlueprintType)
class UFortRelativeAnchorCanvas : public UPanelWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UFortRelativeAnchorCanvasSlot* AddSlot(const UWidget* ContentWidget, const UWidget* AnchorWidget);

	UFUNCTION(BlueprintCallable)
	void SetZLayerOffset(const int32 Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRelativeAnchorCanvas")
	int32 ZLayerOffset;

};

UCLASS(BlueprintType)
class UFortRelativeAnchorCanvasSlot : public UPanelSlot
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetAnchorWidget(const UWidget* NewAnchorWidget);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortRelativeAnchorCanvasSlot", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UWidget> AnchorWidget;

};

