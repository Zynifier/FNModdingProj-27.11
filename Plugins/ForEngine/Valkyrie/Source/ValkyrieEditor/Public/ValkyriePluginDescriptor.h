// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyriePluginDescriptor.generated.h"

UENUM()
enum class EValkyrieLibraryPluginFolderMode : uint8
{
	/** Plugin folder is absent from the library hierarchy (default) */
	Absent = 0,
	/** Plugin folder in the library hierarchy is set to the plugin name */
	PluginName = 1,
	/** Plugin folder in the library hierarchy is set to 'Library Custom Path' */
	CustomPath = 2,
	COUNT = 3 UMETA(Hidden),
	DEFAULT = 0 UMETA(Hidden),
};

USTRUCT()
struct VALKYRIEEDITOR_API FGameFeaturePluginDescriptor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool BuiltInAutoActivate;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyriePluginSettings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EValkyrieLibraryPluginFolderMode LibraryFolderMode;

	UPROPERTY()
	FString LibraryCustomPath;

};

USTRUCT()
struct VALKYRIEEDITOR_API FValkyriePluginDescriptor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FValkyriePluginSettings ValkyrieSettings;

	UPROPERTY()
	FGameFeaturePluginDescriptor GameFeaturePluginDescriptor;

};

