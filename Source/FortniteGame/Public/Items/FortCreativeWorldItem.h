// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerCustomizableInterface.h"
#include "FortPropertyOverrideData.h"
#include "Items/FortWorldItem.h"
#include "FortCreativeWorldItem.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortCreativeWorldItem : public UFortWorldItem, public IFortPlayerCustomizable, public IFortPropertyOverrideProvider
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	int32 MaxRegenStacks;

};

