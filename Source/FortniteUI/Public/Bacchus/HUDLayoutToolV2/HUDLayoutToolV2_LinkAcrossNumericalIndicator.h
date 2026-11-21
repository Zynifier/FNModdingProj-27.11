// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "HUDLayoutToolV2_LinkAcrossNumericalIndicator.generated.h"

class UCommonTextBlock;

UENUM(BlueprintType)
enum class ENumericalIndicatorActionType : uint8
{
	Adding = 0,
	Removing = 1,
	Nothing = 2,
};

USTRUCT()
struct FLinkAcrossNumericalIndicatorActionSymbol
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LinkAcrossNumericalIndicatorActionSymbol")
	ENumericalIndicatorActionType ActionType;

	UPROPERTY(EditAnywhere, Category="LinkAcrossNumericalIndicatorActionSymbol")
	FText ActionSymbol;

	UPROPERTY(EditAnywhere, Category="LinkAcrossNumericalIndicatorActionSymbol")
	FLinearColor ActionColor;

};

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_LinkAcrossNumericalIndicator : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LinkAcrossNumericalIndicator")
	FLinearColor MaximumInstancesColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LinkAcrossNumericalIndicator")
	TArray<FLinkAcrossNumericalIndicatorActionSymbol> ActionSymbols;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActionSymbol;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InstanceCounter;

};

