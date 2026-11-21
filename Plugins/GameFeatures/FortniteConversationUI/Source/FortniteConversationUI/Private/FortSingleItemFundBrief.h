// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/DataDrivenServiceTypes.h"
#include "FortConversationOptionBrief.h"
#include "FortSingleItemFundBrief.generated.h"

class UFortItemFundBrief;
class UFortNPCTextDisplay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSingleItemFundBrief : public UFortConversationOptionBrief
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSingleItemFundBrief", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemFundBrief> Item_Entry;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSingleItemFundBrief", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortNPCTextDisplay> NPCTextDisplay;

	UPROPERTY(EditAnywhere, Category="FortSingleItemFundBrief")
	TMap<FName, FDataDrivenServiceBriefConfig> ServiceConfigs;

};

