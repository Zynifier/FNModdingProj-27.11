// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRegenHealthSetInterface.generated.h"

class UGameplayEffect;

UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class UFortHealthRegenInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortHealthRegenInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Health")
	virtual UGameplayEffect* GetHealthRegenDelayGameplayEffect() const;

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual UGameplayEffect* GetHealthRegenGameplayEffect() const;

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual TSubclassOf<UGameplayEffect> GetHealthRegenGameplayEffectClass() const;

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual UGameplayEffect* GetShieldRegenDelayGameplayEffect() const;

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual UGameplayEffect* GetShieldRegenGameplayEffect() const;

	UFUNCTION(BlueprintCallable, Category="Health")
	virtual TSubclassOf<UGameplayEffect> GetShieldRegenGameplayEffectClass() const;

};

