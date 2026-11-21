// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCharacterItem.h"
#include "FortHomebaseBannerIconItem.generated.h"

UCLASS(MinimalAPI)
class UFortHomebaseBannerIconItem : public UAthenaCosmeticAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FName GetBannerIconLegacyName() const;

};

