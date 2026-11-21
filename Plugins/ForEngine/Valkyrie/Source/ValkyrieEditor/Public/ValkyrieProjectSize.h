// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "Misc/DateTime.h"
#include "UObject/TopLevelAssetPath.h"
#include "VkContentServiceTypes.h"
#include "ValkyrieProjectSize.generated.h"

USTRUCT()
struct FValkyrieModuleCookedSizeStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int64 SizeBytes;

	UPROPERTY()
	TMap<FTopLevelAssetPath, int64> PerTypeSizesBytes;

	UPROPERTY()
	TMap<FName, int64> PerPackageSizesBytes;

	UPROPERTY()
	TMap<FName, FTopLevelAssetPath> PerPackagePrimaryTypes;

};

USTRUCT()
struct FValkyrieModuleDependencySizeStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVkModuleVersionRef ModuleVersionId;

	UPROPERTY()
	FString ModuleName;

	UPROPERTY()
	int64 DownloadSizeBytes;

};

USTRUCT()
struct FValkyrieProjectSizeStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime LastUploaded;

	UPROPERTY()
	FVkModuleVersionRef RootModuleVersionId;

	UPROPERTY()
	int64 UploadSizeBytes;

	UPROPERTY()
	int64 DownloadSizeBytes;

	UPROPERTY()
	FValkyrieModuleCookedSizeStats CookedSize;

	UPROPERTY()
	TArray<FValkyrieModuleDependencySizeStats> DependencySizes;

	UPROPERTY()
	bool bIsValid;

};

UCLASS()
class VALKYRIEEDITOR_API UValkyrieProjectSize : public UEditorSubsystem
{
	GENERATED_BODY()

};

