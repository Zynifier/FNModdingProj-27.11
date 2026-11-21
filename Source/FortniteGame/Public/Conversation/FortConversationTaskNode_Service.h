// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationTaskNode.h"
#include "FortConversationTaskNode_Service.generated.h"

class UCurveTable;
class UFortWorldItemDefinition;

UCLASS(Abstract, MinimalAPI)
class UFortConversationTaskNode_Service : public UFortConversationTaskNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Selling")
	TObjectPtr<UFortWorldItemDefinition> ResourceCurrency;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Selling")
	TArray<TObjectPtr<UCurveTable>> PricingTables;

	UPROPERTY(EditDefaultsOnly, Category="Selling")
	bool bPriceDiscountsEnabled;

};

