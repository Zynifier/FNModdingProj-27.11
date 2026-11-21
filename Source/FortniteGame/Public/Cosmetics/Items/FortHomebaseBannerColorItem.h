// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortHomebaseBannerColorItem.generated.h"

UCLASS(MinimalAPI)
class UFortHomebaseBannerColorItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FName ColorRowName;

};

