// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "InstancedStruct.h"
#include "FortEventReactionsTableRow.generated.h"

USTRUCT(BlueprintType)
struct FFortEventReactionsTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Event Reaction System", meta=(BaseStruct="/Script/FortniteGame.FortEventConditionalBase", ExcludeBaseStruct))
	FInstancedStruct EventConditional;

	UPROPERTY(EditAnywhere, Category="Event Reaction System", meta=(BaseStruct="/Script/FortniteGame.FortEventReactionBase", ExcludeBaseStruct))
	TArray<FInstancedStruct> EventReactions;

};

