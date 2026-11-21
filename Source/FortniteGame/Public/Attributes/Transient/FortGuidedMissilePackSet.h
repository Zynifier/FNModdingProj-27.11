// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortGuidedMissilePackSet.generated.h"

UCLASS(BlueprintType)
class UFortGuidedMissilePackSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="GuidedMissilePack")
	FFortGameplayAttributeData MaxMissiles;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="GuidedMissilePack")
	FFortGameplayAttributeData Missiles;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="GuidedMissilePack")
	FFortGameplayAttributeData ReserveMaxMissiles;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="GuidedMissilePack")
	FFortGameplayAttributeData ReserveMissiles;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="GuidedMissilePack")
	FFortGameplayAttributeData ReloadDelay;

};

