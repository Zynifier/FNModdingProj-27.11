// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "UObject/SoftObjectPath.h"
#include "FortAbilitySystemGlobals.generated.h"

UCLASS()
class UFortAbilitySystemGlobals : public UAbilitySystemGlobals
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FSoftObjectPath> BROnlyAttributeSetDefaultsToExclude;

};

