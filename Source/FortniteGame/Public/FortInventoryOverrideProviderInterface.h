// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemAndCount.h"
#include "FortInventoryOverrideProviderInterface.generated.h"

UINTERFACE(BlueprintType)
class UFortInventoryOverrideProvider : public UInterface
{
	GENERATED_BODY()
};

class IFortInventoryOverrideProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	bool GetInventoryOverrides(TArray<FItemAndCount>& InventoryItems) const;

};

