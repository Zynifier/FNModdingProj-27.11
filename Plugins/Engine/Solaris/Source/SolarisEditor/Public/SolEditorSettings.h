// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "SolEditorSettings.generated.h"

class UObject;

/** Struct used to configure which Verse assets to scan for and display them into the associated folder */
USTRUCT()
struct SOLARISEDITOR_API FVerseClassAlias
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftClassPtr<UObject> VerseClassPath;

	UPROPERTY()
	FString AliasFolderName;

};

UCLASS(Config=Engine)
class SOLARISEDITOR_API USolEditorSanitizationSettings : public UObject
{
	GENERATED_BODY()

private:
	/** 
	 * If set to true IsPathValid will always return true 
	 */
	UPROPERTY(Config)
	bool bDisablePathValidation;

	/** 
	 * If set to true hyperlinks to paths that do not pass the valid 
	 * check will not even be displayed in editor log messages 
	 */
	UPROPERTY(Config)
	bool bHideInvalidHyperlinks;

	/** 
	 * List of regex patterns for which at least one must be
	 * found in the path for it to be valid
	 */
	UPROPERTY(Config)
	TArray<FString> AnyPatternRequiredList;

	/**
	 * Regex pattern for replacing the server path with a local one
	 */
	UPROPERTY(Config)
	FString ReplaceServerPathPattern;

};

UCLASS(Config=Editor)
class USolEditorSettings : public UObject
{
	GENERATED_BODY()

private:
	/** List of UClass to scan and create aliases for in the content browser */
	UPROPERTY(EditAnywhere, Config, Category="Scripts", meta=(DisplayName="Verse Class Aliases"))
	TArray<FVerseClassAlias> VerseClassAliases;

};

UCLASS(Config=EditorPerProjectUserSettings, meta=(DisplayName="Verse Scripting"))
class SOLARISEDITOR_API USolEditorUserSettings : public UDeveloperSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="Notifications", meta=(DisplayName="Prompt for Rebuild on Failed Build"))
	uint8 bPromptForRetryOnFailedBuild : 1;

	UPROPERTY(EditAnywhere, Config, Category="Notifications", meta=(DisplayName="Ignore Incomplete Linking on PIE"))
	uint8 bIgnorePendingLinkTasksOnPIE : 1;

	/** Directories where Verse script templates can be found (including subfolders) */
	UPROPERTY(EditAnywhere, Config, Category="Scripts", meta=(DisplayName="Script Template Directories"))
	TArray<FDirectoryPath> ScriptTemplateDirectories;

	/** The following parameters will be replaced at calltime: %file% %line% %column% */
	UPROPERTY(EditAnywhere, Config, Category="Scripts", meta=(DisplayName="Custom script edtior command line"))
	FString CustomScriptEditorCommandLine;

	/** Should Verse scripts be available in the Content Browser? */
	UPROPERTY(EditAnywhere, Config, Category="Scripts", meta=(ConfigRestartRequired="TRUE"))
	bool bEnableContentBrowserIntegration;

};

