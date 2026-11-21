// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortSurvivorData.generated.h"

class UDataTable;

UCLASS(BlueprintType)
class UFortSurvivorData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Survivors")
	TObjectPtr<UDataTable> SurvivorFemaleFirstNameData;

	UPROPERTY(EditDefaultsOnly, Category="Survivors")
	TObjectPtr<UDataTable> SurvivorMaleFirstNameData;

	UPROPERTY(EditDefaultsOnly, Category="Survivors")
	TObjectPtr<UDataTable> SurvivorFemaleLastNameData;

	UPROPERTY(EditDefaultsOnly, Category="Survivors")
	TObjectPtr<UDataTable> SurvivorMaleLastNameData;

};

