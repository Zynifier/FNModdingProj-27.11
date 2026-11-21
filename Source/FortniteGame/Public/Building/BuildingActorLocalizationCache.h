// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/TopLevelAssetPath.h"
#include "BuildingActorLocalizationCache.generated.h"

class ABuildingActor;

USTRUCT()
struct FBuildingActorLocalizedStrings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> LocalizedStrings;

	UPROPERTY()
	uint32 SourceStringHash;

};

USTRUCT()
struct FBuildingActorLocalizationEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FBuildingActorLocalizedStrings DisplayName;

};

UCLASS(MinimalAPI)
class UBuildingActorLocalizationCache : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BuildingActorLocalization")
	const TArray<FString>& GetCachedLanguages() const;

	UFUNCTION(BlueprintPure, Category="BuildingActorLocalization")
	FString GetDisplayNameForBuildingActor(const TSubclassOf<ABuildingActor>& Class, const FString& Language, const FString& SourceString = TEXT("")) const;

private:
	UPROPERTY()
	TArray<FString> CachedLanguages;

	UPROPERTY()
	TMap<FTopLevelAssetPath, FBuildingActorLocalizationEntry> CachedBuildingActors;

};

