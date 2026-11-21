// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortBT/FortBTDecorator_QueryGameplayAbility.h"
#include "FortBTDecorator_GameplayAbility_IsClosestPawnInRange.generated.h"

UCLASS()
class FORTNITEAISERVER_API UFortBTDecorator_GameplayAbility_IsClosestPawnInRange : public UFortBTDecorator_QueryGameplayAbility
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

