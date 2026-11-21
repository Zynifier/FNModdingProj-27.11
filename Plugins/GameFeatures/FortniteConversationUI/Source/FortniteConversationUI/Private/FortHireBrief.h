// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTransactionBrief.h"
#include "FortHireBrief.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortHireBrief : public UFortItemTransactionBrief
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void HandleNPCDismissal(bool bAtMaxNPCNum, bool bWillDismissNPCAtHire);

private:
	UPROPERTY(EditAnywhere, Category="FortHireBrief")
	FText TextTemplate;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHireBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Objective;

};

