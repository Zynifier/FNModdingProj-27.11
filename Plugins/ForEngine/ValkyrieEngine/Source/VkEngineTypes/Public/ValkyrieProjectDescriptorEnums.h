// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyrieProjectDescriptorEnums.generated.h"

UENUM()
enum class EValkyrieProjectDescriptorFileVersion : uint8
{
	Invalid = 0,
	Initial = 1,
	AddProjectMetadata = 2,
	AddedCompatibilityLabel = 3,
	AddBindings = 4,
	AddEditorPermissions = 5,
	AddEpicApp = 6,
	AddDataSets = 7,
	AddVersionSuffix = 8,
	AddProjectKind = 9,
	AddMetaDataTags = 10,
	RevertMetaDataTags = 11,
	AddDocsUrl = 12,
	AddTemplateCategory = 13,
	BranchDependencies = 14,
	LatestPlusOne = 15,
	Latest = 14,
};

UENUM()
enum class EValkyrieProjectKind : int32
{
	/**
	 * A project that delivers an island that can be played in the game.
	 * Island projects cannot have public assets or verse apis and cannot be referenced by other projects.
	 */
	Island = 0,
	/**
	 * A project with public assets and verse apis that can referenced by other projects.
	 * Library projects are likely to have multiple versions and are typically distributed via the marketplace hub.
	 */
	Library = 1,
	Count = 2 UMETA(Hidden),
	Unspecified = 3 UMETA(Hidden),
	Default = 0 UMETA(Hidden),
};

UENUM()
enum class EValkyrieProjectReferenceDescriptorFileVersion : uint8
{
	Invalid = 0,
	Initial = 1,
	AddLinkCode = 2,
	LatestPlusOne = 3,
	Latest = 2,
};

UENUM()
enum class EValkyrieProjectTemplateCategory : int32
{
	/** A project template that contains content created by users */
	UserGenerated = 0,
	/** A project template that represents isolated functionality and allows the user to explore and learn more about specific features or systems */
	FeatureExample = 1,
	/** A project template that are more complex and provides users with examples that are created by professional dev teams */
	SampleProject = 2,
	Count = 3 UMETA(Hidden),
	Default = 0 UMETA(Hidden),
};

