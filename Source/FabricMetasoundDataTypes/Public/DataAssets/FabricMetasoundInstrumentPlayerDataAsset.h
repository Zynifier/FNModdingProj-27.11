// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FabricMetasoundInstrumentPlayerDataAsset.generated.h"

class UFabricMetasoundInstrumentPlayerDataAsset;
class UFusionPatch;

UCLASS(BlueprintType)
class UFabricMetasoundInstrumentPlayerDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetasoundInstrumentPlayerDataAsset")
	TObjectPtr<UFusionPatch> Patch;

};

UCLASS(BlueprintType, Blueprintable)
class UFabricMetasoundInstrumentPlayerDataAssetList : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetasoundInstrumentPlayerDataAssetList")
	TArray<TSoftObjectPtr<UFabricMetasoundInstrumentPlayerDataAsset>> InstrumentPlayerData;

};

