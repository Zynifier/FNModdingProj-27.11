// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FabricMetasoundDrumPlayerDataAsset.generated.h"

class UFabricMetasoundDrumPlayerSampleBankAsset;
class USoundWave;

USTRUCT(BlueprintType)
struct FFabricMetasoundDrumPlayerSampleData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetasoundDrumPlayerSampleData")
	FText SampleLabel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetasoundDrumPlayerSampleData")
	TObjectPtr<USoundWave> WaveAsset;

};

UCLASS(BlueprintType, Blueprintable)
class UFabricMetasoundDrumPlayerDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetasoundDrumPlayerDataAsset")
	TArray<TSoftObjectPtr<UFabricMetasoundDrumPlayerSampleBankAsset>> SampleBanks;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICMETASOUNDDATATYPES_API UFabricMetasoundDrumPlayerSampleBankAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetasoundDrumPlayerSampleBankAsset")
	TArray<FFabricMetasoundDrumPlayerSampleData> Samples;

};

