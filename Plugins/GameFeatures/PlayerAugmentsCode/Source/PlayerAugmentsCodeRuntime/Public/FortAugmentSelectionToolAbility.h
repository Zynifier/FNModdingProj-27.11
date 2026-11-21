// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortAugmentSelectionToolAbility.generated.h"

class UInputComponent;

UCLASS(BlueprintType, Blueprintable)
class UFortAugmentSelectionToolAbility : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHighlightSelectionUpdated(int32 NewHighlightedChoiceIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHoldRerollInputChanged(bool bIsPressed, bool bCompletedHold);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRerollPressedAndCannotAfford();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectedChoiceIndex(int32 ChoiceIndex);

	UFUNCTION(BlueprintCallable)
	void SetHighlightedChoiceIndex(int32 NewChoiceIndex);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> SelectionInputComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortAugmentSelectionToolAbility")
	FScalableFloat InputPriority;

	UPROPERTY(EditDefaultsOnly, Category="FortAugmentSelectionToolAbility")
	int32 NumChoices;

	UPROPERTY(BlueprintReadOnly, Category="FortAugmentSelectionToolAbility", meta=(AllowPrivateAccess="true"))
	int32 HighlightedChoiceIndex;

	UPROPERTY(EditDefaultsOnly, Category="FortAugmentSelectionToolAbility")
	FScalableFloat RerollHoldInputSeconds;

};

