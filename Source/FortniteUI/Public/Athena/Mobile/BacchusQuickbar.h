// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Mobile/BacchusQuickbarBase.h"
#include "BacchusQuickbar.generated.h"

class UCommonVisibilitySwitcher;
class UFortQuickbarBase;
enum class EFortQuickBars : uint8;

UCLASS()
class UBacchusQuickbar : public UBacchusQuickbarBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Refresh();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	float SlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	EComboSlotType SlotType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	bool bIsBackwards;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbar", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortQuickbarBase> BacchusQuickbarPrimary;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbar", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortQuickbarBase> BacchusQuickbarSecondary;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbar", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortQuickbarBase> BacchusQuickbarCreative;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbar", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> BarSwitcher;

protected:
	UFUNCTION()
	void OnModeChanged(EFortQuickBars NewQuickbar, const int32 FocusedSlot);

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuickbarChanged(UFortQuickbarBase* NewBar, UFortQuickbarBase* OldBar);

private:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotLocksPropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag ReversePropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotTypePropertyTag;

};

