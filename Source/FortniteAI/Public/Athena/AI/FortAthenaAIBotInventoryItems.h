// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortItemAndCount.h"
#include "FortAthenaAIBotInventoryItems.generated.h"

UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class UFortAthenaAIBotInventoryItems : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	TArray<FItemAndCount> Items;

};

