// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortAnimationBlueprintEditorLibrary.generated.h"

class USkeleton;

UCLASS(BlueprintType, Blueprintable)
class UFortAnimationBlueprintEditorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void CompileAnimationBlueprints(const FString& OutputFilePath, const TArray<FAssetData>& AssetData, const FString ParentFilter);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void FilterAssetByParent(FName ClassName, TArray<FAssetData>& OutAssetData, bool bUseNativeParent, const TArray<FAssetData>& InAssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationBlueprintCustomBlueprintEvents(const FString& OutputFilePath, const FAssetData& AnimBlueprintAsset);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationBlueprintParents(const FString& OutputFilePath, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationBlueprintSlotUsage(const FString& OutputFilePath, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationLayerInterfacesImplementations(const FString& OutputFilePath, const bool bCompileBlueprints, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationLayerInterfacesUsage(const FString& OutputFilePath, const bool bCompileBlueprints, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationSequenceCurveUsage(const FString& OutputFilePath, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationSequencesByRetargetSource(const FString& SearchString, const FString& OutputFilePath, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationSequencesForSkeleton(const USkeleton* Skeleton, const TArray<FAssetData>& AssetData, TArray<FAssetData>& AnimSequenceAssets);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationSequencesWithBoneData(const USkeleton* Skeleton, const FString& BoneName, const FString& OutputFilePath, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationSetsContent(const FString& OutputFilePath, const TArray<FAssetData>& AssetData, const bool bFortWeaponAnimSet = true, const bool bFortPlayerGliderAnimSet = true, const bool bFortPatrolAnimAsset = true, const bool bFortPlayerSkydiveAnimSet = true, const bool bFortWeaponAdditiveAnimSet = true, const bool bFortLocomotionAnimSetData = true, const bool bFortTacticalStateAnimSetData = true);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListAnimationSyncData(const FString& OutputFilePath, const FAssetData& AnimBlueprintAsset);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void ListWeaponMontageUsage(const FString& OutputFilePath, const TArray<FAssetData>& AssetData);

	UFUNCTION(BlueprintCallable, Category="Animation|Utilities")
	static void SaveAllBlueprintsAsText(const FString& OutputDirectory, const TArray<FAssetData>& AssetData);

};

