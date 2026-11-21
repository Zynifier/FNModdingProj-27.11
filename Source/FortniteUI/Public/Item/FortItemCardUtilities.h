// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortItemCardUtilities.generated.h"

enum class EFortItemCardSize : uint8;
enum class EFortItemType : uint8;

UCLASS(MinimalAPI)
class UFortItemCardUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item Card Utilities")
	static FVector2D GetCardDimensions(const EFortItemType ItemType, const EFortItemCardSize CardSize, const bool IsReward, const bool UseNewItemCardSizes);

};

