// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortBT/FortBTDecorator_QueryGameplayAbility.h"
#include "FortBTDecorator_GameplayAbility_HasNearbyPawns.generated.h"

UCLASS()
class UFortBTDecorator_GameplayAbility_HasNearbyPawns : public UFortBTDecorator_QueryGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Condition")
	float NearbyPawnDistance;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bFilterAIPawns;

	UPROPERTY(EditAnywhere, Category="Condition")
	bool bFilterPlayerPawns;

};

