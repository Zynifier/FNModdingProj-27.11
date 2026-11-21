// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticLoadoutSlot.h"
#include "CosmeticLoadout.generated.h"

USTRUCT(BlueprintType)
struct FCosmeticLoadout
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="CosmeticLoadout")
	TArray<FCosmeticLoadoutSlot> Slots;

};

