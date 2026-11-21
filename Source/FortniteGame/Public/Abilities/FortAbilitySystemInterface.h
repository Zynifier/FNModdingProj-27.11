// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "FortAbilitySystemInterface.generated.h"

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortAbilitySystemInterface : public UAbilitySystemInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortAbilitySystemInterface : public IAbilitySystemInterface
{
	GENERATED_BODY()

};

