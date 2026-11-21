// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortItemAndCount.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FItemAndCount
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	TObjectPtr<UFortItemDefinition> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FGuid ItemVariantGuid;

};

USTRUCT(BlueprintType)
struct FItemGuidAndCount
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	int32 Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FGuid ItemGuid;

};

