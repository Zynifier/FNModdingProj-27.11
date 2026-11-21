// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "PerkSelectionEntryWidget.generated.h"

class UFortSpyTechItemDefinition;
class UPerkSelectionEntryWidget;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UPerkSelectionEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPerkSelected, UPerkSelectionEntryWidget*, Widget);

public:
	UPROPERTY(BlueprintAssignable)
	FOnPerkSelected OnPerkSelected;

protected:
	UFUNCTION(BlueprintPure)
	bool GetTechSelectVerboseModeEnabled() const;

	UFUNCTION(BlueprintCallable)
	void OnSelectionMade();

	UFUNCTION(BlueprintImplementableEvent)
	void SetItems_BP(UFortSpyTechItemDefinition* FirstItem, UFortSpyTechItemDefinition* SecondItem);

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="PerkSelectionEntryWidget")
	int32 SelectionIndex;

	UPROPERTY(BlueprintReadOnly, Category="PerkSelectionEntryWidget")
	TObjectPtr<UFortSpyTechItemDefinition> ItemA;

	UPROPERTY(BlueprintReadOnly, Category="PerkSelectionEntryWidget")
	TObjectPtr<UFortSpyTechItemDefinition> ItemB;

	UPROPERTY(BlueprintReadOnly, Category="PerkSelectionEntryWidget")
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> AllSelectableItems;

	UPROPERTY(BlueprintReadOnly, Category="PerkSelectionEntryWidget")
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> AllSelectablePassives;

};

