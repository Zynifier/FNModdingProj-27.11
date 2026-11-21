// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTransactionBrief.h"
#include "FortApplyAbilityBrief.generated.h"

class UCommonRichTextBlock;
enum class EPreventAbilityUseReason : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortApplyAbilityBrief : public UFortItemTransactionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnAbleToPurchase();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnUnableToPurchase(EPreventAbilityUseReason Reason);

	UPROPERTY(EditAnywhere, Category="FortApplyAbilityBrief")
	FText PurchaseServiceText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortApplyAbilityBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Display;

};

