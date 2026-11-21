// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_SellItem.generated.h"

class UFortMontageItemDefinitionBase;

USTRUCT()
struct FConversationSellTaskMemory
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UFortConversationTaskNode_SellItem : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Selling", meta=(ClampMax="5", ClampMin="1", ExposeOnSpawn, UIMax="5", UIMin="1"))
	int32 SellSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationTaskNode_SellItem")
	FGameplayTag OptionalFilterCategoryTag;

	UPROPERTY(EditAnywhere, Category="Selling")
	FText BuyTextFormat;

	UPROPERTY(EditAnywhere, Category="Selling")
	FText SoldOutTextFormat;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Selling")
	TObjectPtr<UFortMontageItemDefinitionBase> ExpensivePurchaseEmote;

};

