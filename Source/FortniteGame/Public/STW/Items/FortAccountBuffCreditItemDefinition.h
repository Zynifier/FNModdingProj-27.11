// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortConsumableAccountItemDefinition.h"
#include "FortAccountBuffCreditItemDefinition.generated.h"

class UFortAccountBuffItemDefinition;

UCLASS(BlueprintType)
class UFortAccountBuffCreditItemDefinition : public UFortConsumableAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAccountBuffCreditItemDefinition")
	TSoftObjectPtr<UFortAccountBuffItemDefinition> BuffToGrant;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAccountBuffCreditItemDefinition")
	int32 MinutesOfBuffTimeToGrant;

};

