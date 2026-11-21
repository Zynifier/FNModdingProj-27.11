// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortCloudSaveItemDefinition.h"
#include "FortOutpostItemDefinition.generated.h"

class UGameplayEffect;

USTRUCT()
struct FFortDepositedResources
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TemplateId;

	UPROPERTY()
	int32 Quantity;

};

USTRUCT()
struct FFortPlacedBuilding
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString BuildingTag;

	UPROPERTY()
	FString PlacedTag;

};

USTRUCT()
struct FFortOutpostCoreInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortPlacedBuilding> PlacedBuildings;

	UPROPERTY()
	TArray<FString> AccountsWithEditPermission;

	UPROPERTY()
	uint32 HighestEnduranceWaveReached;

};

USTRUCT()
struct FFortOutpostPOSTInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortDepositedResources> DepositedPostItems;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortOutpostItemDefinition : public UFortCloudSaveItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Display")
	FText GetLongDescription() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<TSubclassOf<UGameplayEffect>> StaticGameplayEffectsByLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 TheaterIndex;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText LongDescription;

};

