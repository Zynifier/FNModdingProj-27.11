// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/MathFwd.h"
#include "FabricScreenWidget.generated.h"

class UFabricWidget;
class UGridPanel;
class UInvalidationBox;
class UScaleBox;
class USpacer;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fabric UI", DisableNativeTick))
class FABRICUI_API UFabricScreenWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UFabricWidget* AttachFabricWidget(const TSubclassOf<UFabricWidget>& FabricWidgetClass, const FVector2D& GridPosition);

	UFUNCTION(BlueprintCallable)
	void SetScreenGridDimensions(const FVector2D& InNewDimensions);

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UInvalidationBox> InvalidationBox_RootBox;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_ScreenScale;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UGridPanel> GridPanel_ScreenGrid;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> Spacer_ElementSpacer;

};

