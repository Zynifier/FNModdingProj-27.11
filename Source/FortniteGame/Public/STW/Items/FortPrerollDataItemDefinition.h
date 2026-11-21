// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortPrerollDataItemDefinition.generated.h"

UCLASS(BlueprintType)
class UFortPrerollDataItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPrerollDataItemDefinition", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float StreakbreakerRefundMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPrerollDataItemDefinition", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float StreakbreakerAccumulationMultiplier;

};

