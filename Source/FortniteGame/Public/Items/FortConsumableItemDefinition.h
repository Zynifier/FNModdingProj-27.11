// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "ScalableFloat.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortConsumableItemDefinition.generated.h"

class UAnimMontage;
class UGameplayEffect;

USTRUCT()
struct FConsumeEffectData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	TSoftClassPtr<UGameplayEffect> EffectClass;

	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	FScalableFloat Level;

};

UCLASS(BlueprintType)
class UFortConsumableItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Consumable")
	virtual void ConsumeItem(const FGameplayEventData& EventData);

	UFUNCTION(BlueprintPure, Category="Consumable")
	virtual float GetAnimPlayRate() const;

	UFUNCTION(BlueprintPure, Category="Consumable")
	virtual float GetHealthRestored(int32 ItemLevel) const;

	UFUNCTION(BlueprintPure, Category="Consumable")
	virtual UAnimMontage* GetUseAnimation() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	TArray<FConsumeEffectData> ConsumeEffects;

	UPROPERTY(EditAnywhere, Category="Consumable")
	TSoftObjectPtr<UAnimMontage> UseAnimation;

	UPROPERTY(EditAnywhere, Category="Consumable")
	float UseTime;

	UPROPERTY(EditAnywhere, Category="Consumable")
	bool bRequiresMissingHealth;

};

