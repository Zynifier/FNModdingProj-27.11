// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTransactionBrief.h"
#include "FortShowFutureStormCircleBrief.generated.h"

class UCommonRichTextBlock;
enum class EPreventUseStormCircleServiceReason : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortShowFutureStormCircleBrief : public UFortItemTransactionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnAbleToPurchase();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnUnableToPurchase(EPreventUseStormCircleServiceReason Reason);

private:
	UPROPERTY(EditAnywhere, Category="FortShowFutureStormCircleBrief")
	FText PurchaseServiceText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowFutureStormCircleBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Display;

};

