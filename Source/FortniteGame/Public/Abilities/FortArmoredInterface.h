// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortArmoredInterface.generated.h"

class UFortAbilitySystemComponent;
class UGameplayEffect;

UINTERFACE(BlueprintType, Blueprintable)
class UFortArmoredInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortArmoredInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Armored")
	TArray<TSubclassOf<UGameplayEffect>> GetArmoredAppliedEffects();

	UFUNCTION(BlueprintImplementableEvent, Category="Armored")
	FBox GetArmoredArea();

	UFUNCTION(BlueprintImplementableEvent, Category="Armored")
	UFortAbilitySystemComponent* GetOwningAbilityComponent();

};

