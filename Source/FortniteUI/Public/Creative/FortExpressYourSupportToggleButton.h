// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortExpressYourSupportToggleButton.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortExpressYourSupportToggleButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool LeaveCreativeFavoriteButtonEnabled();

	UFUNCTION(BlueprintPure)
	static bool LeaveCreativeSupportButtonEnabled();

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NormalText;

	UPROPERTY(EditAnywhere, Category="FortExpressYourSupportToggleButton")
	FText ToggledOnText;

	UPROPERTY(EditAnywhere, Category="FortExpressYourSupportToggleButton")
	FText ToggledOffText;

	UPROPERTY(EditAnywhere, Category="FortExpressYourSupportToggleButton")
	FText ToggledOnHoveredText;

};

