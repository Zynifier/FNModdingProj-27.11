// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortCharacter.generated.h"

UCLASS(Abstract, MinimalAPI, NotBlueprintable)
class UFortCharacter : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCharacter", meta=(DisplayName="SquadId"))
	FString squad_id;

	UPROPERTY(BlueprintReadOnly, Category="FortCharacter", meta=(DisplayName="SquadSlotIdx"))
	int32 squad_slot_idx;

};

