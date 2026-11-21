// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortGiftBoxUnlockItemDefinition.generated.h"

class UFortGiftBoxItemDefinition;

UCLASS(MinimalAPI, BlueprintType)
class UFortGiftBoxUnlockItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortGiftBoxUnlockItemDefinition")
	TSoftObjectPtr<UFortGiftBoxItemDefinition> UnlockedGiftBox;

	UPROPERTY(VisibleAnywhere, Category="FortGiftBoxUnlockItemDefinition")
	FDateTime CreationDate;

};

