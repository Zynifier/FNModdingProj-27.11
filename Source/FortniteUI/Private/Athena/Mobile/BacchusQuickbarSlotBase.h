// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "Athena/QuickBar/AthenaQuickBarSlot.h"
#include "BacchusQuickbarSlotBase.generated.h"

class UImage;

UCLASS(Abstract)
class UBacchusQuickbarSlotBase : public UAthenaQuickBarSlot
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void EndInteraction();

	UFUNCTION(BlueprintCallable)
	void ResetSlot();

	UFUNCTION(BlueprintCallable)
	void SlotSelected(bool bStopUseImmediately);

	UFUNCTION(BlueprintImplementableEvent)
	void StartOngoingUse();

	UFUNCTION(BlueprintCallable)
	void StopUseSlot();

protected:
	UPROPERTY(BlueprintReadOnly, Category="BacchusQuickbarSlotBase")
	bool bHasOngoingUseAction;

	UPROPERTY(BlueprintReadOnly, Category="BacchusQuickbarSlotBase")
	bool bTapToLockEnabled;

	UPROPERTY(BlueprintReadOnly, Category="BacchusQuickbarSlotBase")
	bool bIsLocked;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BacchusQuickbarSlotBase")
	bool bSupportsDragAndDrop;

	UPROPERTY(BlueprintReadWrite, Category="BacchusQuickbarSlotBase")
	bool bDragDetected;

	UPROPERTY(BlueprintReadWrite, Category="BacchusQuickbarSlotBase")
	bool bDragOpStarted;

	UPROPERTY(BlueprintReadWrite, Category="BacchusQuickbarSlotBase")
	bool bInteractionStarted;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BacchusQuickbarSlotBase", meta=(BindWidget))
	FSlateColor TouchedColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BacchusQuickbarSlotBase", meta=(BindWidget))
	FSlateColor UntouchedColor;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbarSlotBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> SelectionHighlight;

	UPROPERTY(BlueprintReadOnly, Export, Category="BacchusQuickbarSlotBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> LockIcon;

};

