// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MaterialTypes.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FabricMeshProvider.generated.h"

class UFabricMeshModifierBase;
class UFabricMeshTreeNode;
class UStreamableRenderAsset;
class UTexture;

USTRUCT(BlueprintType)
struct FFabricMeshProviderMeshReferenceParamInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReferenceParamInfo")
	FMaterialParameterInfo MaterialParameterInfo;

};

USTRUCT(BlueprintType)
struct FFabricMeshProviderMeshReferenceParamInfo_Color : public FFabricMeshProviderMeshReferenceParamInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReferenceParamInfo_Color")
	FLinearColor Color;

};

USTRUCT(BlueprintType)
struct FFabricMeshProviderMeshReferenceParamInfo_Scalar : public FFabricMeshProviderMeshReferenceParamInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReferenceParamInfo_Scalar")
	float Scalar;

};

USTRUCT(BlueprintType)
struct FFabricMeshProviderMeshReferenceParams
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReferenceParams")
	double UniformScale;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReferenceParams")
	TArray<FFabricMeshProviderMeshReferenceParamInfo_Scalar> ScalarParams;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReferenceParams")
	TArray<FFabricMeshProviderMeshReferenceParamInfo_Color> ColorParams;

};

USTRUCT(BlueprintType)
struct FFabricMeshProviderMeshReference
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReference")
	TObjectPtr<UStreamableRenderAsset> Mesh;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReference")
	TObjectPtr<UTexture> Texture;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshProviderMeshReference")
	FFabricMeshProviderMeshReferenceParams Params;

};

USTRUCT(BlueprintType)
struct FFabricMeshInstanceReference
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMeshInstanceReference")
	FFabricMeshProviderMeshReference MeshReference;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshInstanceReference")
	TArray<FTransform> InstanceTransforms;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMeshProviderBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetReferenceMesh(const FFabricMeshProviderMeshReference& InMesh);

protected:
	UPROPERTY(Transient)
	FFabricMeshProviderMeshReference ReferenceMesh;

	UPROPERTY(Transient)
	TArray<FTransform> InstanceMeshes;

	UPROPERTY(Transient)
	float CurrentCableFloatValue;

	UPROPERTY(Transient)
	float CurrentCableFloatDirection;

	UPROPERTY(Transient)
	bool bCurrentCableFloatDirty;

};

UCLASS(BlueprintType)
class FABRICRUNTIME_API UFabricMeshTreeNode : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CopyProperties(const UFabricMeshTreeNode* Other);

	UFUNCTION(BlueprintPure)
	TArray<FFabricMeshInstanceReference> GenerateMeshInstanceReferences() const;

	UFUNCTION(BlueprintCallable)
	void Reset();

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshTreeNode")
	TObjectPtr<UFabricMeshModifierBase> MeshModifier;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshTreeNode")
	FFabricMeshProviderMeshReferenceParams Params;

	UPROPERTY(BlueprintReadOnly, Category="FabricMeshTreeNode")
	FFabricMeshProviderMeshReference MeshProviderReference;

	UPROPERTY(BlueprintReadWrite, Category="FabricMeshTreeNode")
	TArray<UFabricMeshTreeNode*> Children;

	UPROPERTY(VisibleAnywhere, Category="FabricMeshTreeNode")
	uint32 LastCalculatedChecksum;

	UPROPERTY(VisibleAnywhere, Category="FabricMeshTreeNode")
	bool bAllowChecksumCalculation;

};

