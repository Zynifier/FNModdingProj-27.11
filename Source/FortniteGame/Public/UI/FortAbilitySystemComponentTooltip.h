// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "AttributeSet.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UI/FortTooltip.h"
#include "UI/FortTooltipManager.h"
#include "FortAbilitySystemComponentTooltip.generated.h"

class UFortAbilitySystemComponentTooltipContext;
class UFortTooltipContext;

USTRUCT()
struct FTokenAttributePair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Tooltip", meta=(Categories="Tooltip.Token.Attribute"))
	FGameplayTag Token;

	UPROPERTY(EditAnywhere, Category="Tooltip")
	FGameplayAttribute Attribute;

};

UCLASS(BlueprintType, Blueprintable, meta=(ShortTooltip="Gathers data from ability system components for display tooltips."))
class UFortAbilitySystemComponentTooltip : public UFortTooltip
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortTooltipContext> CachedContext;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAbilitySystemComponentTooltipContext : public UFortTooltipContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips")
	static UFortAbilitySystemComponentTooltipContext* SpawnAbilitySystemTooltipContext();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Tooltips")
	static UFortAbilitySystemComponentTooltipContext* SpawnAbilitySystemTooltipContextFromOtherContext(const UFortTooltipContext* OtherContext);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip|Context")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltip|Context")
	FActiveGameplayEffectHandle ActiveGEHandle;

};

UCLASS()
class UFortTokenToAttributeTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Tokens")
	TArray<FTokenAttributePair> TokenToAttributeList;

};

