// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortCollectionBookSlotXPWeightData.generated.h"

USTRUCT()
struct FFortCollectionBookSlotXPWeightData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="XP")
	float ConstantWeight;

	UPROPERTY(VisibleAnywhere, Category="XP")
	float RarityWeight;

	UPROPERTY(VisibleAnywhere, Category="XP")
	float PremiumTierWeight;

	UPROPERTY(VisibleAnywhere, Category="XP")
	float ItemLevelWeight;

	UPROPERTY(VisibleAnywhere, Category="XP")
	float ItemRatingWeight;

};

