// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_Reload.generated.h"

UCLASS()
class UFortGameplayAbility_Reload : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 NumTimesReloaded;

};

