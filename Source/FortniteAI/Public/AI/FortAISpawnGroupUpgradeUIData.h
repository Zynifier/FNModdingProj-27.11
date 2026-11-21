// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"
#include "FortAISpawnGroupUpgradeUIData.generated.h"

class UTexture2D;

USTRUCT()
struct FFortAISpawnGroupUpgradeUIData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeUIData")
	bool bAlwaysDisplayHealthBar;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeUIData")
	bool bOverrideHealthBarColor;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeUIData")
	TSoftObjectPtr<UTexture2D> UpgradeIconImage;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeUIData")
	FSlateColor UpgradeIconTintColor;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeUIData")
	FLinearColor HealthBarColorOverride;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgradeUIData")
	FText UpgradeName;

};

