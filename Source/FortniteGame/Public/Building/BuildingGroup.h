// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Building/BuildingFoundation.h"
#include "BuildingGroup.generated.h"

class UBuildingGroup;
class UWorld;

USTRUCT(BlueprintType)
struct FFortMapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGroup")
	FGameplayTagContainer BuildingLevelTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGroup")
	float SelectionWeight;

private:
	UPROPERTY(EditAnywhere, Category="BuildingGroup")
	TSoftObjectPtr<UWorld> BuildingWorld;

};

UCLASS(EditInlineNew, MinimalAPI, BlueprintType, ClassGroup=("Building"))
class UBuildingGroup : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BuildingGroup")
	void GetAllMapNames(TArray<FString>& AllMaps) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="BuildingGroup")
	FName GroupName;

	UPROPERTY(EditAnywhere, Category="BuildingGroup")
	TObjectPtr<UBuildingGroup> FallbackGroup;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="BuildingGroup")
	TEnumAsByte<EBuildingFoundationType> FoundationType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGroup")
	FGameplayTagContainer AllBuildingLevelTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingGroup")
	TArray<FFortMapData> BuildingLevelData;

};

