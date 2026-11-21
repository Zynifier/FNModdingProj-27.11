// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_AddToInventory.generated.h"

USTRUCT(meta=(DisplayName="Add To Inventory"))
struct FFortObjectiveFilter_AddToInventory : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AddToInventory", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags Item;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AddToInventory", meta=(DisplayAfter="Item"))
	uint8 bRequireBrandNewItem : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AddToInventory", meta=(DisplayPriority="-1"))
	uint8 bIncrementByItemCount : 1;

};

UCLASS()
class UFortObjectiveProcessor_AddToInventory : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

