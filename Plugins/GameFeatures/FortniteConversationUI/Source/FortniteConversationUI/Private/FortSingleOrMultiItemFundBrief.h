// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortConversationOptionBrief.h"
#include "FortSingleOrMultiItemFundBrief.generated.h"

class UFortConversationOptionBrief;
class UOverlay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSingleOrMultiItemFundBrief : public UFortConversationOptionBrief
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Details")
	TSoftClassPtr<UFortConversationOptionBrief> SingleItemBrief;

	UPROPERTY(EditAnywhere, Category="Details")
	TSoftClassPtr<UFortConversationOptionBrief> MultiItemsBrief;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Brief;

};

