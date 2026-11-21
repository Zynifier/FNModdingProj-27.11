// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MLDeformerAssetMapping.generated.h"

class UAthenaCharacterItemDefinition;
class UCustomCharacterPart;
class UMLDeformerAsset;
class UMeshDeformer;

UCLASS()
class UMLDeformerAssetMapping : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterItemDefinition", meta=(AssetBundles="MLDeformerAssetMaps", DisplayName="Character Item Definition To ML Deformer Asset Map Keys"))
	TArray<TSoftObjectPtr<UAthenaCharacterItemDefinition>> CharacterItemDefinitionToMLDeformerAssetMappingKeys;

	UPROPERTY(EditAnywhere, Category="CharacterItemDefinition", meta=(AssetBundles="MLDeformerAssetMaps", DisplayName="Character Item Definition To ML Deformer Asset Map Values"))
	TArray<TSoftObjectPtr<UMLDeformerAsset>> CharacterItemDefinitionToMLDeformerAssetMappingValues;

	UPROPERTY(EditAnywhere, Category="CharacterPart", meta=(AssetBundles="MLDeformerAssetMaps", DisplayName="Character Part To ML Deformer Asset Map Keys"))
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterPartToMLDeformerAssetMappingKeys;

	UPROPERTY(EditAnywhere, Category="CharacterPart", meta=(AssetBundles="MLDeformerAssetMaps", DisplayName="Character Part To ML Deformer Asset Map Values"))
	TArray<TSoftObjectPtr<UMLDeformerAsset>> CharacterPartToMLDeformerAssetMappingValues;

	UPROPERTY(EditAnywhere, Category="MeshDeformer", meta=(AssetBundles="MLDeformerAssetMaps", DisplayName="ML Deformer To Mesh Deformer Asset Map"))
	TMap<TSoftObjectPtr<UMLDeformerAsset>, TSoftObjectPtr<UMeshDeformer>> MLDeformerToMeshDeformerAssetMap;

	UPROPERTY(meta=(AssetBundles="MLDeformerAssetMaps"))
	TMap<TSoftObjectPtr<UAthenaCharacterItemDefinition>, TSoftObjectPtr<UMLDeformerAsset>> CharacterItemDefinitionToMLDeformerAssetMap_DEPRECATED;

	UPROPERTY(meta=(AssetBundles="MLDeformerAssetMaps"))
	TMap<TSoftObjectPtr<UCustomCharacterPart>, TSoftObjectPtr<UMLDeformerAsset>> CharacterPartToMLDeformerAssetMap_DEPRECATED;

};

