// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortBT/FortBTDecorator_QueryGameplayAbility.h"
#include "FortBTDecorator_GameplayAbility_CanHitTarget.generated.h"

UCLASS()
class UFortBTDecorator_GameplayAbility_CanHitTarget : public UFortBTDecorator_QueryGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Condition")
	uint8 UseIdealYawRotationToTarget : 1;

};

