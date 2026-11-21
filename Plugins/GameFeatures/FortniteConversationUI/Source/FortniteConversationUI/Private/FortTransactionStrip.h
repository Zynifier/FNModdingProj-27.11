// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Conversation/FortServiceTransactionInfo.h"
#include "FortTransactionStrip.generated.h"

class IFortInventoryOwnerInterface;
class UCommonTextBlock;
class UFortItemDefinition;
class UFortWorldItemDefinition;

UCLASS(Abstract)
class UFortTransactionStrip : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortTransactionStrip(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnSetTransactionCostVisibility(const bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnTransactionInfoReceived(const FFortServiceTransactionInfo& TransactionInfo);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortTransactionStrip", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CostDescription;

	UPROPERTY(BlueprintReadOnly, Category="Transactions")
	TWeakObjectPtr<UFortWorldItemDefinition> CachedGlobalCurrency;

private:
	UFUNCTION()
	void HandleOnItemCountChanged(TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner, UFortItemDefinition* Definition, int32 Delta);

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Transactions")
	TObjectPtr<UFortWorldItemDefinition> ResourceCurrency;

};

