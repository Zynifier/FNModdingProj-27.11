// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"
#include "GameplayTagContainer.h"
#include "UI/FortTooltip.h"
#include "FortGameplayAbilityTooltip.generated.h"

class UFortTooltipContext;
class UGameplayAbility;

UCLASS(BlueprintType, Blueprintable, meta=(ShortTooltip="Gathers data from gameplay abilities for display tooltips."))
class UFortGameplayAbilityTooltip : public UFortTooltip
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Tooltip", meta=(DisplayName="GetApplicationTag"))
	bool GetApplicationTag(const UGameplayAbility* AbilityInstance, FGameplayTag& OutTag) const;

	UFUNCTION(BlueprintPure, Category="Tooltip")
	bool GetTextForTokenFromAbilityInstance(const UGameplayAbility* AbilityInstance, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const;

	UFUNCTION(BlueprintNativeEvent, Category="Tooltip", meta=(DisplayName="GetTextForTokenFromAbilityInstance"))
	bool GetTextForTokenFromAbilityInstanceInternal(const UGameplayAbility* AbilityInstance, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const;

	UFUNCTION(BlueprintPure, Category="Tooltip")
	bool GetTextForTokenFromAbilitySpec(const FGameplayAbilitySpec& Spec, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const;

	UFUNCTION(BlueprintNativeEvent, Category="Tooltip", meta=(DisplayName="GetTextForTokenFromAbilitySpec"))
	bool GetTextForTokenFromAbilitySpecInternal(const FGameplayAbilitySpec& Spec, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Tooltip")
	void InitializeAbilityInstance(const UGameplayAbility* AbilityInstance, const UFortTooltipContext* Context) const;

	UFUNCTION(BlueprintNativeEvent, Category="Tooltip", meta=(DisplayName="InitializeAbilityInstance"))
	void InitializeAbilityInstanceInternal(const UGameplayAbility* AbilityInstance, const UFortTooltipContext* Context) const;

private:
	UPROPERTY(Transient)
	FGameplayAbilitySpec CachedSpec;

	UPROPERTY(Transient)
	TObjectPtr<UGameplayAbility> CachedAbilityInstance;

	UPROPERTY(Transient)
	TObjectPtr<UFortTooltipContext> CachedContext;

};

