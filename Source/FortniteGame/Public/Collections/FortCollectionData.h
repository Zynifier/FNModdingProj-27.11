// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "FortCollectionData.generated.h"

class UFortCollectionData;
class UFortCollectionDataEntry;

USTRUCT()
struct FFortCollectionDataMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCollectionDataMapping")
	FString CollectionType;

	UPROPERTY(EditDefaultsOnly, Category="FortCollectionDataMapping")
	bool bEnsureAllTaggedItemsAreInTheCollection;

	UPROPERTY(EditDefaultsOnly, Category="FortCollectionDataMapping", meta=(AssetBundles="ServerAthena, ClientAthena"))
	TSoftObjectPtr<UFortCollectionData> Collection;

};

UCLASS(MinimalAPI)
class UFortCollectionData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="FortCollectionData", meta=(TitleProperty="EntryName"))
	TArray<TObjectPtr<UFortCollectionDataEntry>> Entries;

};

UCLASS(EditInlineNew, MinimalAPI)
class UFortCollectionDataEntry : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, DuplicateTransient, Category="FortCollectionDataEntry")
	bool bHideInCollectionsScreen;

	UPROPERTY(EditDefaultsOnly, DuplicateTransient, Category="FortCollectionDataEntry")
	bool bAutoCollectOnServerJoin;

};

UCLASS(MinimalAPI)
class UFortCollectionsDataTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortCollectionsDataTable", meta=(TitleProperty="Collection"))
	TArray<FFortCollectionDataMapping> Collections;

};

