// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGridSorting.generated.h"

class UObject;

UENUM(BlueprintType)
enum class EGridSortKind : uint8
{
	/** No sorting */
	None = 0,
	/** Sort only by number */
	ByNumber = 1,
	/** Sort only by string */
	ByString = 2,
	/** Sort lexicographically by number then string */
	ByNumberThenString = 3,
	/** Sort lexicographically by number then string */
	ByStringThenNumber = 4,
};

USTRUCT(BlueprintType)
struct FGridSortKey
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Grid")
	float Number;

	UPROPERTY(BlueprintReadWrite, Category="Grid")
	FString String;

};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(FGridSortKey, FGetSortKeyFor, UObject*, Data);

