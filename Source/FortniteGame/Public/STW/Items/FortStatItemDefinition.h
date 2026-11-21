// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortStatItemDefinition.generated.h"

UENUM(BlueprintType)
enum class EFortStatType : uint8
{
	Fortitude = 0,
	Offense = 1,
	Resistance = 2,
	Technology = 3,
	Fortitude_Team = 4,
	Offense_Team = 5,
	Resistance_Team = 6,
	Technology_Team = 7,
	Invalid = 8,
};

UCLASS(BlueprintType)
class UFortStatItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="StatItem")
	EFortStatType Stat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="StatItem")
	FGameplayAttribute StatAttribute;

};

