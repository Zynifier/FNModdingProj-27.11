// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortAthenaRewardEventGraphPurchaseToken.generated.h"

class UAthenaRewardEventGraph;
class UFortRepeatableDailiesCardItemDefinition;

UCLASS()
class UFortAthenaRewardEventGraphPurchaseToken : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaRewardEventGraphPurchaseToken")
	EItemProfileType ProfileType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaRewardEventGraphPurchaseToken")
	TSoftObjectPtr<UAthenaRewardEventGraph> RewardEventGraphDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaRewardEventGraphPurchaseToken")
	TSoftObjectPtr<UFortRepeatableDailiesCardItemDefinition> RepeatableDailiesCardItemDefinition;

};

