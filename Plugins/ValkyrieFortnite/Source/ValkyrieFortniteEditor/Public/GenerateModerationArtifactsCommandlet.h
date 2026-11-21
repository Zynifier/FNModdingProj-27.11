// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/BaseIteratePackagesCommandlet.h"
#include "UObject/NoExportTypes.h"
#include "UObject/TopLevelAssetPath.h"
#include "ThumbnailSpawnerInterface.h"
#include "GenerateModerationArtifactsCommandlet.generated.h"

class UMaterialInterface;
class USkinnedAsset;
class UStaticMesh;

UENUM()
enum class EModerationAssetFlags : uint8
{
	GeneratedMeshPreview = 1,
	GeneratedFStrings = 2,
	GeneratedLocalization = 4,
	GeneratedTexture = 8,
	None = 0,
};

USTRUCT()
struct FFileInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString File;

	UPROPERTY()
	FString PackagePath;

	UPROPERTY()
	FString Hash;

	UPROPERTY()
	FString HashWithDependencies;

};

USTRUCT()
struct FModerationArtifact
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Filename;

	UPROPERTY()
	FString Hash;

	UPROPERTY()
	TArray<FString> Tags;

};

USTRUCT()
struct FModerationAsset
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString FullPath;

	UPROPERTY()
	FString ClassName;

	UPROPERTY()
	TArray<FModerationArtifact> Artifacts;

	UPROPERTY()
	TArray<uint32> StringArtifactIndexes;

	UPROPERTY()
	FString InputHash;

	UPROPERTY()
	FString ApproximateVisualHash;

	UPROPERTY()
	TArray<FString> Tags;

};

USTRUCT()
struct FModerationPackage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PackagePath;

	UPROPERTY()
	FString PackageHash;

	UPROPERTY()
	TArray<FModerationAsset> Assets;

};

USTRUCT()
struct FModerationManifest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Files;

	UPROPERTY()
	TArray<FModerationPackage> Packages;

};

USTRUCT()
struct FModerationMeshPreviewEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UStaticMesh* StaticMesh;

	UPROPERTY()
	USkinnedAsset* SkinnedMesh;

	UPROPERTY()
	UMaterialInterface* OverlayMaterial;

	UPROPERTY()
	TArray<UMaterialInterface*> Materials;

};

USTRUCT()
struct FModerationStringManifest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Strings;

};

UCLASS(Config=Editor)
class UGenerateModerationArtifactsCommandlet : public UBaseIteratePackagesCommandlet
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void LogAnalytics();

	UPROPERTY(Config)
	bool bGeneratePreviewMeshArtifacts;

	UPROPERTY(Config)
	bool bGenerateInputHash;

	UPROPERTY(Config)
	bool bPreviewMeshesWithOverriddenMaterials;

	UPROPERTY(Config)
	bool bGenerateLocalizationArtifacts;

	UPROPERTY(Config)
	bool bGenerateLocalizationStats;

	UPROPERTY(Config)
	bool bGenerateFStringArtifacts;

	UPROPERTY(Config)
	bool bTreatLoadingErrorsAsWarnings;

	UPROPERTY(Config)
	bool bRemoveBlankMeshPreviews;

	UPROPERTY(Config)
	bool bEnforceMinTextureSize;

	UPROPERTY(Config)
	int32 MinTextureSizeToModerate;

	UPROPERTY(Config)
	int64 MaxArtifactSize;

	UPROPERTY(Config)
	int64 MaxImageSquareInPixels;

	UPROPERTY(Config)
	int32 NumPitchPreviewCaptures;

	UPROPERTY(Config)
	int32 NumYawPreviewCaptures;

	UPROPERTY(Config)
	int32 NumRollPreviewCaptures;

	UPROPERTY(Config)
	TArray<FTopLevelAssetPath> GatherFStrings_TypesToSkip;

	UPROPERTY(Config)
	TArray<TFieldPath<FProperty>> GatherFStrings_PropertiesToSkip;

	UPROPERTY(Config)
	TArray<FTopLevelAssetPath> TypesToDisgregardForStringModeration;

	UPROPERTY(Config)
	TArray<FName> StructsToDisgregardForStringModeration;

	UPROPERTY(Config)
	TArray<FString> IgnoreForStringModeration;

	UPROPERTY(Config)
	int32 ModerationGarbageCollectionFrequency;

	UPROPERTY(Config)
	int32 ModerationGarbageCollectionFrequencyMesh;

	UPROPERTY(Config)
	TArray<FTopLevelAssetPath> SubstituteEmissiveBlack;

	UPROPERTY(Config)
	TArray<FTopLevelAssetPath> SubstituteMasksAllOne;

	UPROPERTY(Config)
	TArray<FTopLevelAssetPath> SubstituteMasksAllZero;

	UPROPERTY(Config)
	TArray<FTopLevelAssetPath> SubstituteMasksSpecRoughMetal;

	UPROPERTY(Config)
	TArray<FTopLevelAssetPath> SubstituteNormalMap;

};

UCLASS()
class UModerationSpawner : public UObject, public IThumbnailSpawner
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FModerationMeshPreviewEntry> PreviewEntries;

};

