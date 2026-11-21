// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortHUDVisibilityData.generated.h"

UCLASS(BlueprintType)
class UFortHUDVisibilityData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortHUDVisibilityData")
	FGameplayTag HUDVisibilityGameplayTag;

	UPROPERTY(BlueprintReadWrite, Category="FortHUDVisibilityData")
	FText DisplayText;

	UPROPERTY(BlueprintReadWrite, Category="FortHUDVisibilityData")
	FText TooltipText;

	UPROPERTY(BlueprintReadWrite, Category="FortHUDVisibilityData")
	bool Visible;

};

