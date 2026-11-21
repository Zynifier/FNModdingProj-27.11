// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortConsumableAccountItemDefinition.generated.h"

UCLASS(BlueprintType)
class UFortConsumableAccountItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Consumable")
	bool bCanActivateOnSelf;

	UPROPERTY(EditAnywhere, Category="Consumable")
	bool bCanActivateOnOthers;

	UPROPERTY(EditAnywhere, Category="Consumable")
	bool bIsAutomaticallyConsumed;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConsumableAccountItemDefinition")
	EItemProfileType ProfileType;

};

