// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "OnlineLinkId.h"
#include "ValkyrieProjectDescriptorEnums.h"
#include "ValkyrieProjectDescriptor.generated.h"

USTRUCT()
struct VKENGINETYPES_API FValkyriePluginReferenceDescriptor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	bool bIsRoot;

	UPROPERTY()
	bool bIsPublic;

};

USTRUCT()
struct VKENGINETYPES_API FValkyrieProjectBindingsDescriptor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FString ProjectVersePath;

	UPROPERTY()
	TMap<FString, FString> Modules;

};

USTRUCT()
struct VKENGINETYPES_API FValkyrieProjectReferenceDescriptor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint8 FileVersion;

	UPROPERTY()
	FString Id;

	UPROPERTY()
	FOnlineLinkId LinkCode;

	UPROPERTY()
	bool bEnabled;

};

USTRUCT()
struct VKENGINETYPES_API FValkyrieProjectDescriptor
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FValkyrieProjectBindingsDescriptor Bindings;

private:
	UPROPERTY()
	uint8 FileVersion;

	UPROPERTY()
	FString VersionSuffix;

	UPROPERTY()
	FString Title;

	UPROPERTY()
	FString Description;

	UPROPERTY()
	FString KeyArt;

	UPROPERTY()
	FString DocsUrl;

	UPROPERTY()
	EValkyrieProjectKind Kind;

	UPROPERTY()
	EValkyrieProjectTemplateCategory TemplateCategory;

	UPROPERTY()
	FString CompatibilityVersion;

	UPROPERTY()
	TArray<FString> EditorPermissions;

	UPROPERTY()
	FString EpicApp;

	UPROPERTY()
	float SortPriority;

	UPROPERTY()
	TArray<FValkyriePluginReferenceDescriptor> Plugins;

	UPROPERTY()
	TMap<FString, FJsonObjectWrapper> DataSets;

	UPROPERTY()
	TArray<FValkyrieProjectReferenceDescriptor> Dependencies_DEPRECATED;

};

USTRUCT()
struct VKENGINETYPES_API FValkyrieProjectDescriptorIOContext
{
	GENERATED_BODY()

};

