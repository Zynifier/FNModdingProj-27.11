// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortRestedXpBoosterToken.generated.h"

UCLASS()
class UFortRestedXpBoosterToken : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRestedXpBoosterToken")
	EItemProfileType ProfileType;

	UPROPERTY(EditAnywhere, Category="FortRestedXpBoosterToken", meta=(ClampMin="1", UIMin="1"))
	int32 RestedXpAmountToGrant;

	UPROPERTY(EditAnywhere, Category="FortRestedXpBoosterToken")
	bool bRequiresBattlePass;

};

