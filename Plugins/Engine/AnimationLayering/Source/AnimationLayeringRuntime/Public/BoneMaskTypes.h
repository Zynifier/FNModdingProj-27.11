// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimData/BoneMaskFilter.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Guid.h"
#include "BoneMaskTypes.generated.h"

class USkeleton;

USTRUCT(BlueprintType)
struct ANIMATIONLAYERINGRUNTIME_API FBoneMaskEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoneMask", meta=(UIMax="1", UIMin="0"))
	float LocalSpaceWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoneMask", meta=(UIMax="1", UIMin="0"))
	float MeshSpaceWeight;

};

USTRUCT(BlueprintType)
struct ANIMATIONLAYERINGRUNTIME_API FBoneMask
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoneMask")
	TMap<FName, FBoneMaskEntry> BoneMaskMap;

};

USTRUCT(BlueprintType)
struct ANIMATIONLAYERINGRUNTIME_API FBoneMaskPerBoneData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoneMask")
	int32 SkeletonPoseBoneIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoneMask")
	float BlendWeight;

};

USTRUCT(BlueprintType)
struct ANIMATIONLAYERINGRUNTIME_API FBoneMaskBodyPartDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoneMask")
	FName Name;

	UPROPERTY(EditAnywhere, Category="BoneMask")
	TArray<FBranchFilter> BranchFilters;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BoneMask")
	TArray<FBoneMaskPerBoneData> SkeletonPoseBoneWeights;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BoneMask")
	TArray<int32> SkeletonPoseChildBoneIndices;

};

USTRUCT(BlueprintType)
struct ANIMATIONLAYERINGRUNTIME_API FBoneMaskDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoneMask")
	TArray<FBoneMaskBodyPartDefinition> BodyPartDefinitions;

};

USTRUCT(BlueprintType)
struct ANIMATIONLAYERINGRUNTIME_API FBoneMaskUpdateMultiParam
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Defaults")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Defaults")
	float LocalSpaceWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Defaults")
	float MeshSpaceWeight;

};

UCLASS(MinimalAPI, BlueprintType)
class UBoneMaskDefinitionDataAsset : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="BoneMask")
	FBoneMaskDefinition BoneMaskDefinition;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="BoneMask")
	TObjectPtr<USkeleton> Skeleton;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FGuid SkeletonGuid;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FGuid VirtualBoneGuid;
#endif

};

// @TODO: Remove this once all blueprint calls are removed.

UCLASS()
class UBoneMaskFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Bone Mask", meta=(DisplayName="Get Weights"))
	static void BP_BoneMask_GetBodyPartWeights(const FBoneMask& BoneMask, FName Name, float& LocalSpaceWeight, float& MeshSpaceWeight);

	UFUNCTION(BlueprintCallable, Category="Bone Mask", meta=(DisplayName="Update Local Space Weight"))
	static void BP_BoneMask_UpdateBodyPartLocalSpaceWeight(UPARAM(ref) FBoneMask& BoneMask, FName Name, float LocalSpaceWeight);

	UFUNCTION(BlueprintCallable, Category="Bone Mask", meta=(DisplayName="Update Mesh Space Weight"))
	static void BP_BoneMask_UpdateBodyPartMeshSpaceWeight(UPARAM(ref) FBoneMask& BoneMask, FName Name, float MeshSpaceWeight);

	UFUNCTION(BlueprintCallable, Category="Bone Mask", meta=(DisplayName="Update Weights"))
	static void BP_BoneMask_UpdateBodyPartWeights(UPARAM(ref) FBoneMask& BoneMask, FName Name, float LocalSpaceWeight, float MeshSpaceWeight);

	UFUNCTION(BlueprintCallable, Category="Bone Mask", meta=(DisplayName="Update Weights Multi"))
	static void BP_BoneMask_UpdateBodyPartWeightsMulti(UPARAM(ref) FBoneMask& BoneMask, const TArray<FBoneMaskUpdateMultiParam>& Params);

};

