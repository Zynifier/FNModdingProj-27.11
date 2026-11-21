// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortCreativeWorldItem.h"
#include "FortCreativeEmoteWorldItem.generated.h"

class UFortMontageItemDefinitionBase;

UCLASS(BlueprintType)
class UFortCreativeEmoteWorldItem : public UFortCreativeWorldItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortMontageItemDefinitionBase* GetEmoteItemDefinition() const;

};

