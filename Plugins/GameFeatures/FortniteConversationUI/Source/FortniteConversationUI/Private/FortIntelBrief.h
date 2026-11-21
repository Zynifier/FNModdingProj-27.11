// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTransactionBrief.h"
#include "FortIntelBrief.generated.h"

class UCommonRichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortIntelBrief : public UFortItemTransactionBrief
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortIntelBrief")
	FText TextTemplate;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortIntelBrief", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Objective;

};

