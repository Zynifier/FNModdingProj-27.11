// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortHomebase/FortHomebaseTypes.h"
#include "FortHomebaseBannerColorMap.generated.h"

UCLASS()
class UFortHomebaseBannerColorMap : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Colors")
	TMap<FName, FHomebaseBannerColor> ColorMap;

};

