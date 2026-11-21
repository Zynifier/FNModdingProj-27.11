// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaRewardSchedule.h"
#include "Items/AthenaSeasonItemCustomSkinCategoryData.h"
#include "Items/AthenaSeasonItemData_BattlePass.h"
#include "AthenaSeasonItemData_CustomSkin.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Battle Pass Custom Skin Data"))
class UAthenaSeasonItemData_CustomSkin : public UAthenaSeasonItemData_BattlePass
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemData_CustomSkin")
	FAthenaRewardItemReference CustomSkinCID;

	UPROPERTY(EditAnywhere, Category="BattlePassOffer")
	TArray<FAthenaSeasonItemCustomSkinCategoryData> Categories;

};

