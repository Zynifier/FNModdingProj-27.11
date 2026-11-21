// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/PrimaryAssetId.h"
#include "FortCharacterConversionAsset.generated.h"

class UAssembledMeshSchema;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FSchemaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SchemaData")
	TSoftObjectPtr<UAssembledMeshSchema> Schema;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SchemaData")
	bool bEnabled;

};

UCLASS(BlueprintType)
class UFortCharacterConversionAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortCharacterConversionAsset")
	TMap<FPrimaryAssetId, FSchemaData> AssetToSchemaMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortCharacterConversionAsset")
	TArray<TObjectPtr<UAssembledMeshSchema>> DefaultAssembledMeshSchemas;

};

