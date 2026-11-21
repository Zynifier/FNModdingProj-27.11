// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "PoiNamedWeights.generated.h"

USTRUCT()
struct FPairedWeightEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PairedWeightEntry")
	FName Name;

	UPROPERTY(EditAnywhere, Category="PairedWeightEntry")
	FScalableFloat Value;

};

USTRUCT()
struct FPairedWeightContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PairedWeightContainer", meta=(TitleProperty="Name"))
	TArray<FPairedWeightEntry> Weights;

};

UCLASS()
class UPoiNamedWeights : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PoiNamedWeights", meta=(Categories="Athena.Location", TitleProperty="Name"))
	TMap<FGameplayTag, FPairedWeightContainer> LocationSpecifiedEntries;

};

