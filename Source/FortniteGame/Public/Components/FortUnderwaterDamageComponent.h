// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "Components/ActorComponent.h"
#include "ScalableFloat.h"
#include "FortUnderwaterDamageComponent.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

UCLASS(BlueprintType, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UFortUnderwaterDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void SetUnderWater(bool bNewUnderWater);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	TSubclassOf<UGameplayEffect> GE_UnderWaterDamage;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat DamageDelay;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat LevelDuration;

private:
	UPROPERTY(Transient)
	bool bIsUnderWater;

	UPROPERTY(Transient)
	float UnderWaterStartTime;

	UPROPERTY(Transient)
	int32 CurrentLevel;

	UPROPERTY(Transient)
	bool bResetFromDBNO;

	UPROPERTY(Transient)
	FActiveGameplayEffectHandle GE_UnderWaterDamage_Handle;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAbilitySystemComponent> OwnerAbilityComp;

};

