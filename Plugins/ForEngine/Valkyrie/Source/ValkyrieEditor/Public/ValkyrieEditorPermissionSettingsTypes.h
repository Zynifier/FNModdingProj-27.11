// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Preferences/UnrealEdOptions.h"
#include "ValkyrieProjectDescriptor.h"
#include "ValkyrieTemplateMapInfo.h"
#include "ValkyrieEditorPermissionSettingsTypes.generated.h"

UENUM()
enum class EValkyrieAssetTypeRule : uint8
{
	Create = 0,
	View = 1,
	Import = 2,
	Export = 3,
	Public = 4,
};

UENUM()
enum class EValkyrieReadOnlyAssetsPermission : uint8
{
	All = 0,
	// Any asset that supports read only mode can be opened

	None = 1,
	// No asset can be opened in read only mode

	VkAssetsOnly = 2,
};

UENUM()
enum class EValkyrieSubclassRule : uint8
{
	// No subclasses allowed

	None = 0,
	// Only C++ subclasses, eg /Script

	NativeOnly = 1,
	// All subclasses, both native and BP

	All = 2,
};

USTRUCT()
struct VALKYRIEEDITOR_API FAllowedPlacementToolEntries
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> AllowedCategories;

	UPROPERTY()
	TArray<FName> AllowedClasses;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieAllowDenyList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> AllowList;

	UPROPERTY()
	TArray<FName> DenyList;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieAllowedAssetType
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<EValkyrieAssetTypeRule> Rules;

	UPROPERTY()
	EValkyrieSubclassRule Subclasses;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieAllowedClass
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool Visible;

	UPROPERTY()
	bool Deny;

	UPROPERTY()
	EValkyrieSubclassRule Subclasses;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieAllowedNameList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> Names;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieEditorPermissionSettings_Animation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> AllowedAnimationEditorTracks;

	UPROPERTY()
	bool bEnableAnimationBlueprints;

	UPROPERTY()
	bool bEnableAnimationBlueprintEventGraphs;

	UPROPERTY()
	bool bEnableAnimationBlueprintMacros;

	UPROPERTY()
	bool bEnableAnimationBlueprintDelegates;

	UPROPERTY()
	TArray<FName> AnimationBlueprintBaseFunctionOverridesAllowList;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieEditorPermissionSettings_Audio
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float MaxSoundWaveImportLengthSeconds;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieEditorPermissionSettings_Blueprints
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bEnableBlueprintGraph;

	UPROPERTY()
	TArray<FString> AllowedFunctions;

	UPROPERTY()
	TArray<FString> AllowedEnums;

	UPROPERTY()
	TArray<FString> AllowedStructs;

	UPROPERTY()
	TArray<FName> AllowedPinCategories;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieMenuRules : public FValkyrieAllowDenyList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool AllowExtenders;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieEditorPermissionSettings_Editor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FValkyrieAllowedAssetType> AllowedAssetTypes;

	UPROPERTY()
	TMap<FString, FValkyrieAllowedClass> AllowedClasses;

	UPROPERTY()
	bool bShowConsole;

	UPROPERTY()
	bool bEnablePropertyMatrix;

	UPROPERTY()
	TArray<FName> AllowedEditorModes;

	UPROPERTY()
	TArray<FName> AllowedImportExtensions;

	UPROPERTY()
	TArray<FString> AllowedContentBrowserFolders;

	UPROPERTY()
	TArray<FValkyrieTemplateMapInfo> AdditionalTemplateMaps;

	UPROPERTY()
	TArray<FClassPickerDefaults> AdditionalClassPickerDefaults;

	UPROPERTY()
	TMap<FName, FValkyrieAllowedNameList> AllowedEditorPreferencesSections;

	UPROPERTY()
	TMap<FName, FValkyrieMenuRules> AllowedMenus;

	UPROPERTY()
	TMap<FName, FValkyrieAllowDenyList> AllowedTabs;

	UPROPERTY()
	TMap<FName, FValkyrieAllowDenyList> AllowedInputCommands;

	UPROPERTY()
	FAllowedPlacementToolEntries AllowedPlacementToolEntries;

	UPROPERTY()
	EValkyrieReadOnlyAssetsPermission ReadOnlyAssetsPermission;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieEditorPermissionSettings_EditorUtility
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FName, FValkyrieAllowedNameList> AllowedEditorUtilityWidgets;

	UPROPERTY()
	TMap<FName, FValkyrieAllowedNameList> AllowedEditorUtilityActions;

	UPROPERTY()
	TArray<FName> AllowedEditorUtilityActorActions;

	UPROPERTY()
	TArray<FName> AllowedEditorUtilityAssetActions;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieEditorPermissionSettings_Project
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bPublishingEnabled;

	UPROPERTY()
	bool bLocalizationEnabled;

	UPROPERTY()
	bool bProjectExternalContentAllowed;

	UPROPERTY()
	bool bAddProjectExternalContentAllowed;

	UPROPERTY()
	bool bRemapLocalContentToReferencedContentAllowed;

	UPROPERTY()
	TArray<FValkyrieProjectReferenceDescriptor> DefaultProjectReferencedContent;

	UPROPERTY()
	bool bMultiPluginProjectAllowed;

	UPROPERTY()
	bool bProjectKindExposed;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyrieEditorPermissionSettings_UMG
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FName> AllowedPaletteCategories;

	UPROPERTY()
	TArray<FString> AllowedPaletteWidgets;

	UPROPERTY()
	TArray<FString> FavoriteWidgetParentClasses;

	UPROPERTY()
	TArray<FString> AllowedMVVMConversionClass;

};

