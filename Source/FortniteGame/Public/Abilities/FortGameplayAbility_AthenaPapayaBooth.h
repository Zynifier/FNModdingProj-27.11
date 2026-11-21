// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_AthenaPapayaBooth.generated.h"

class UUserWidget;

UCLASS(BlueprintType, Blueprintable)
class UFortGameplayAbility_AthenaPapayaBooth : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	TSoftClassPtr<UUserWidget> GetStandaloneLockerScreenClass() const;

	UPROPERTY(BlueprintGetter=GetStandaloneLockerScreenClass, Category="FortGameplayAbility_AthenaPapayaBooth")
	TSoftClassPtr<UUserWidget> StandaloneLockerScreenClass;

};

