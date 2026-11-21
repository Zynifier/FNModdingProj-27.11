// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ServicePricingKeyRemapping.generated.h"

USTRUCT(BlueprintType)
struct FNPCServicePricingKeyRemapRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServicePricingKeyRemapRow")
	FGameplayTag NPC;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServicePricingKeyRemapRow")
	FName KeyNameOriginal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServicePricingKeyRemapRow")
	FName KeyNameRemapped;

};

USTRUCT(BlueprintType)
struct FServicePricingKeyRemappings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ServicePricingKeyRemappings")
	TMap<FName, FName> KeyNameRemappings;

};

