// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Extensibility/FortCosmeticItemAdditionalData.h"
#include "MeshCosmeticsSchemaData.generated.h"

class UMeshCosmeticsLayoutSchema;

UCLASS(MinimalAPI)
class UMeshCosmeticsAppliedSchemaData : public UFortCosmeticItemAdditionalData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MeshCosmetics", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UMeshCosmeticsLayoutSchema> SchemaAsset;

};

UCLASS()
class UMeshCosmeticsSupportedSchemaData : public UFortCosmeticItemAdditionalData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MeshCosmetics")
	TArray<TSoftObjectPtr<UMeshCosmeticsLayoutSchema>> SupportedSchemas;

};

