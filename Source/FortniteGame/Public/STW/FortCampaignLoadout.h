// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCampaignLoadout.generated.h"

class UFortPersonalVehicleItem;

USTRUCT(BlueprintType)
struct FFortCampaignLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCampaignLoadout")
	TObjectPtr<UFortPersonalVehicleItem> PersonalVehicle;

};

