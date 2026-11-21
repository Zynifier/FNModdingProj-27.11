// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CosmeticLoadoutItemDefinition.h"
#include "MockCosmeticLoadoutItem.generated.h"

UCLASS(Hidden)
class UMockCosmeticLoadoutItem : public UPrimaryDataAsset, public ICosmeticLoadoutItemDefinition
{
	GENERATED_BODY()

};

