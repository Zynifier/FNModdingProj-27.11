// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortBotItemDataTable.generated.h"

class UFortPlayerAugmentItemDefinition;

USTRUCT()
struct FFortBotAugmentsDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Augments")
	TObjectPtr<UFortPlayerAugmentItemDefinition> AugmentItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Augments", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float Weight;

};

USTRUCT()
struct FFortBotItemDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	bool bIsSupported;

};

