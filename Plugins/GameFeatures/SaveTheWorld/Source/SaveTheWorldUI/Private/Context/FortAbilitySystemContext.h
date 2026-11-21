// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "BlueprintContextBase.h"
#include "FortAbilitySystemContext.generated.h"

class UAbilitySystemComponent;
class UWidget;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FAttributeChangedDelegate);

UCLASS()
class UFortAbilitySystemContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AbilitySystemContext")
	bool HasMatchingGameplayTag(FGameplayTag TagToCheck) const;

	UFUNCTION(BlueprintCallable, Category="AbilitySystemContext")
	void RegisterForAttributeChanged(UWidget* Widget, UAbilitySystemComponent* ASC, FGameplayAttribute Attribute, FAttributeChangedDelegate Callback);

	UFUNCTION(BlueprintCallable, Category="AbilitySystemContext")
	void RemoveDelegatesFromWidget(UWidget* Widget);

};

