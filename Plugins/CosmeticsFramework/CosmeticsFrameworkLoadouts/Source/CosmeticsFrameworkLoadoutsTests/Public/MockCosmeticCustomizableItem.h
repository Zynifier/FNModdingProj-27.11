// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticCustomizableItemDefinition.h"
#include "MockCosmeticLoadoutItem.h"
#include "MockCosmeticCustomizableItem.generated.h"

UCLASS(MinimalAPI)
class UMockCosmeticCustomizableItem : public UMockCosmeticLoadoutItem, public ICosmeticCustomizableItemDefinition
{
	GENERATED_BODY()

};

