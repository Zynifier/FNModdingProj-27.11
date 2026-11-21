// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "AttachableWheel.h"
#include "WheelGrenadeWheel.generated.h"

class AActor;
class AController;
class UFortAbilitySystemComponent;

UCLASS(BlueprintType, Blueprintable)
class WHEELGRENADERUNTIME_API AWheelGrenadeWheel : public AAttachableWheel, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetHealth() const;

	UFUNCTION(BlueprintPure)
	float GetMaxHealth() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleDamaged(float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintNativeEvent)
	void HandleOutOfHealth(const float InDamage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& InEffectContext, AController* InEventInstigator, AActor* InDamageCauser);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="WheelGrenadeWheel")
	float MaxHealth;

	UPROPERTY(BlueprintReadOnly, Export, Category="WheelGrenadeWheel", meta=(EditInline="true"))
	UFortAbilitySystemComponent* AbilitySystemComponent;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};

