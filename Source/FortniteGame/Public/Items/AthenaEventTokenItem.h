// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "AthenaEventTokenItem.generated.h"

UCLASS()
class UAthenaEventTokenItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaEventTokenItem")
	FString game_code;

};

