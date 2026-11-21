// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DeveloperSettings.h"
#include "ValkyrieEditorSettings.generated.h"

class UDataTable;
class UGameFeatureData;
class UProjectPickerWrapper;
class UValkyrieAssetImportDefaults;
class UValkyrieUIData;

USTRUCT()
struct FValkyrieEditorPermission
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ValkyrieEditorPermission")
	FString Role;

	UPROPERTY(EditAnywhere, Category="ValkyrieEditorPermission")
	FString EntitlementId;

	UPROPERTY(EditAnywhere, Category="ValkyrieEditorPermission")
	FString JsonFileRelativeToProjectDir;

	UPROPERTY(EditAnywhere, Category="ValkyrieEditorPermission")
	TArray<FString> IncludedRoles;

	UPROPERTY(EditAnywhere, Category="ValkyrieEditorPermission")
	bool bDefaultToDisabled;

};

UCLASS(Config=Editor)
class VALKYRIEEDITOR_API UValkyrieEditorSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	bool bAddIslandsAsTemplateMaps;

	UPROPERTY(EditAnywhere, Config, Category="Editor Permissions")
	TArray<FValkyrieEditorPermission> EditorPermissions;

	UPROPERTY(EditAnywhere, Config, Category="Logging")
	TArray<FName> ValkyrieLogCategories;

private:
	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	FString AppShortName;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	TArray<FString> ProjectFileExtensions;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	FString CMSSuffix;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	FString BaseDocsUrlId;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	FString IntrinsicProjectVersePathRoot;

	UPROPERTY(EditAnywhere, Config, Category="UI")
	TSoftObjectPtr<UValkyrieUIData> UIData;

	UPROPERTY(Transient)
	TObjectPtr<UValkyrieUIData> UIDataInstance;

	UPROPERTY(EditAnywhere, Config, Category="Import Defaults")
	TSoftObjectPtr<UValkyrieAssetImportDefaults> AssetImportDefaults;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	TSoftClassPtr<UGameFeatureData> GameFeatureDataClass;

	UPROPERTY(EditAnywhere, Config, Category="ValkyrieEditorSettings")
	TSoftObjectPtr<UDataTable> TemplateProjectLocalizationData;

};

UCLASS(BlueprintType)
class UValkyrieUIData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Export, Category="Screens", meta=(EditInline="true"))
	TObjectPtr<UProjectPickerWrapper> ValkyrieProjectBrowser;

};

