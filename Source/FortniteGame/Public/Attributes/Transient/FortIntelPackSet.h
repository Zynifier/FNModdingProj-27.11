// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortIntelPackSet.generated.h"

UCLASS(BlueprintType)
class UFortIntelPackSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData MaxCharges;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData CurrentCharges;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData StormTrackerCost;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData RevealedTargetsRange;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData RevealedTargetsDuration;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="IntelPack")
	FFortGameplayAttributeData RevealedTargetsCost;

};

