// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Fonts/SlateFontInfo.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "AthenaQuickBarNativeCell.generated.h"

class UFortItem;

UCLASS()
class UAthenaQuickBarNativeCell : public UContentWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AthenaQuickBar")
	void DesiredSizeOverride(float WidthOverride, float HeightOverride);

	UFUNCTION(BlueprintCallable, Category="AthenaQuickBar")
	void SetIsSelected(bool bInSelected);

	UFUNCTION(BlueprintCallable, Category="AthenaQuickBar")
	void SetItemToRepresent(UFortItem* InItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="AthenaQuickBar")
	void UpdateItemPortrait();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FVector2D SelectionOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	float SelectionAnimLength_Seconds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush EmptyCell_Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FVector2D EmptyCell_Padding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush SelectedCell_Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush InactivePortrait_Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush ItemPortrait_Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush AmmoType_Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FVector2D AmmoTypeIcon_Size;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FVector2D AmmoTypeIcon_Padding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Font")
	FSlateFontInfo ItemCount_Font;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Color")
	FLinearColor ItemCount_Color;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	float ItemCount_OutlineAlphaFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FSlateBrush GadgetFuel_Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	FVector2D GadgetFuel_Padding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	float GadgetFuelChargeCount_OutlineAlphaFactor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Font")
	FSlateFontInfo GadgetFuelChargeCount_Font;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Color")
	FLinearColor GadgetFuelChargeCount_Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	uint8 bShowSelectedWhenEmpty : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	uint8 bSupportsWideItems : 1;

};

