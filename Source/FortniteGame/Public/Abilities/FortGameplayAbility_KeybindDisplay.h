// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_KeybindDisplay.generated.h"

class UFortInputComponent;

USTRUCT(BlueprintType)
struct FActionDisplayTextData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ActionDisplayTextData")
	FName KeyAction;

	UPROPERTY(EditDefaultsOnly, Category="ActionDisplayTextData")
	FName GamepadAction;

	UPROPERTY(EditDefaultsOnly, Category="ActionDisplayTextData")
	FText DisplayText;

};

UCLASS(BlueprintType, Blueprintable)
class UFortGameplayAbility_KeybindDisplay : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetActionDisplayActive(const bool bWillDisplayActive);

	UFUNCTION(BlueprintCallable)
	void SetActionDisplayText(FName Action, FText DisplayText);

	UFUNCTION(BlueprintCallable)
	void SetActionDisplayVisibility(FName Action, bool bIsVisible);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Keybind")
	TArray<FActionDisplayTextData> ActionDisplays;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortInputComponent> KeybindInputComponent;

	UPROPERTY(Transient)
	bool bIsDisplayActive;

};

