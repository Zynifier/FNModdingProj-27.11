// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortMatchXPTotalEntry.generated.h"

class UCommonNumericTextBlock;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMatchXPTotalEntry : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetXPTarget();

protected:
	UFUNCTION(BlueprintCallable)
	void InitializeXPCounter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMatchXPTotalEntry")
	bool bIsTotal;

private:
	UPROPERTY(EditAnywhere, Category="FortMatchXPTotalEntry")
	FText XPType;

	UPROPERTY(EditAnywhere, Category="FortMatchXPTotalEntry")
	FText XPSymbol;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> NumericText_XPValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_XPType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_XPSymbol;

};

