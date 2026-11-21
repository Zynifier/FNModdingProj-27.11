// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScalableFloat.h"
#include "FortAthenaInventoryLoadout.generated.h"

class UFortWorldItemDefinition;

USTRUCT()
struct FAthenaLoadoutEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Loadout Info")
	TObjectPtr<UFortWorldItemDefinition> ItemToGrant;

	UPROPERTY(EditAnywhere, Category="Loadout Info")
	FScalableFloat NumberOfItemsToGrant;

	UPROPERTY(EditAnywhere, Category="Loadout Info")
	int32 DesiredSlot;

};

UCLASS()
class UFortAthenaInventoryLoadout : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loadout Display")
	FText LoadoutTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Loadout Display")
	FText LoadoutDescription;

	UPROPERTY(EditAnywhere, Category="Loadout Info")
	TArray<FAthenaLoadoutEntry> LoadoutInfo;

	UPROPERTY(EditAnywhere, Category="Loadout Info")
	FScalableFloat LoadoutEnabled;

};

