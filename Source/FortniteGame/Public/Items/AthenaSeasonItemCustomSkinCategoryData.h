// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaSeasonItemCustomSkinCategoryData.generated.h"

class UAthenaSeasonItemEntryBase;

USTRUCT()
struct FAthenaSeasonItemCustomSkinCategoryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemCustomSkinCategoryData")
	FText Name;

	UPROPERTY(EditAnywhere, Instanced, Category="AthenaSeasonItemCustomSkinCategoryData")
	TArray<TObjectPtr<UAthenaSeasonItemEntryBase>> Entries;

	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemCustomSkinCategoryData")
	int32 RequiredRewardsToUnlock;

	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemCustomSkinCategoryData", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float ZoomLevel;

	UPROPERTY(EditAnywhere, Category="AthenaSeasonItemCustomSkinCategoryData", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float Rotation;

};

