// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "FortItemsForEventMapping.generated.h"

USTRUCT()
struct FEventHotfixForPlaylistData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EventHotfixForPlaylistData")
	FGameplayTagContainer PlaylistTags;

	UPROPERTY(EditAnywhere, Category="EventHotfixForPlaylistData")
	TArray<FString> TableHotfixSyntax;

};

USTRUCT()
struct FEventItemNamedWeight
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EventItemNamedWeight")
	FName WeightName;

	UPROPERTY(EditAnywhere, Category="EventItemNamedWeight")
	FScalableFloat WeightValue;

};

USTRUCT()
struct FItemsForEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EventName")
	FString RequiredEventName;

	UPROPERTY(EditAnywhere, Category="NamedWeights")
	FEventItemNamedWeight EventItemNamedWeight;

	UPROPERTY(EditAnywhere, Category="Items")
	TArray<FPrimaryAssetId> ItemsToLoad;

	UPROPERTY(EditAnywhere, Category="Items")
	TArray<FString> GlobalTableHotfixSyntax;

	UPROPERTY(EditAnywhere, Category="Items")
	TArray<FEventHotfixForPlaylistData> PlaylistTableHotfixSyntax;

};

UCLASS()
class UFortItemsForEventMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="ItemsForEvent", meta=(TitleProperty="RequiredEventName"))
	TArray<FItemsForEventData> ItemsForEventArray;

};

