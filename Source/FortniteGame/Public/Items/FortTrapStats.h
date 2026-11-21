// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortTrapStats.generated.h"

USTRUCT(BlueprintType)
struct FFortTrapStats : public FFortBaseWeaponStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	float ArmTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	float FireDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	float DamageDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	int32 PlacementScore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	int32 ActivationScore;

};

