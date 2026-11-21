// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Mobile/BacchusQuickbarBase.h"
#include "BacchusQuickbarComboSlot.generated.h"

class UBacchusQuickbarSlotBase;
enum class EFortQuickBars : uint8;

UCLASS()
class UBacchusQuickbarComboSlot : public UBacchusQuickbarBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortQuickBars GetQuickbarType() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Refresh();

	UFUNCTION(BlueprintCallable)
	void SetQuickbarType(int32 NewType);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetSize(float NewButtonSize);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	float SlotSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	EComboSlotType SlotType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	int32 SlotIndex;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbarComboSlot", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBacchusQuickbarSlotBase> PrimarySlot;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbarComboSlot", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBacchusQuickbarSlotBase> SecondarySlot;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbarComboSlot", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBacchusQuickbarSlotBase> CreativeSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Display")
	FGameplayTagContainer RefreshHUDStateTags;

private:
	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotTypePropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotLockPropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotNumberPropertyTag;

};

