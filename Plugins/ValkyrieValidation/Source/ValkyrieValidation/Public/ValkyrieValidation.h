// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ValkyrieValidation.generated.h"

UENUM()
enum class EValkyrieValidationErrorCode : uint8
{
	// There were problems with the command line passed to the content sentry. This is an internal error and shouldn't be caused by the user upload

	InternalCommandLineError = 0,
	// Internal Finalization error

	InternalFinalizationError = 1,
	// Input folder was not found on disc

	InputFolderNotFound = 2,
	// Input folder was not found on disc

	NoFilesInInputFolder = 3,
	// An asset contained an engine version that was newer than what this content worker could use

	UnsupportedEngineVersion = 4,
	// An asset contained a custom version that was newer than what this content worker could use

	UnsupportedCustomVersion = 5,
	// Sentry manifest couldn't be loaded

	MissingSentryManifest = 6,
	// Missing a required file

	MissingRequiredFile = 7,
	UnableToReadJSONFile = 8,
	// json file is there but encoded incorrectly

	InvalidEncodingJSONFile = 9,
	// json file contains malformed json

	InvalidJSONFile = 10,
	// json file schema is invalid

	InvalidJSONSchema = 11,
	// Invalid PO file

	InvalidPortableObjectFile = 12,
	// Invalid plugin composition

	InvalidPluginComposition = 13,
	// Error processing a binary package format

	InvalidBinaryPackageFormat = 14,
	// Failed to sign pak file

	FailedToSignPakFile = 15,
	// Failed to sign iostore container

	FailedToSignIOStoreContainer = 16,
	// Error processing verse module

	InvalidVerseModule = 17,
	// Error processing verse file

	InvalidVerseFile = 18,
	// An export was discovered in the package that was not in the allow-list

	DisallowedObjectType = 19,
	// Insufficient permissions to validate content

	InsufficientPermissions = 20,
	// Prohibited plugin configuration

	ProhibitedPluginConfiguration = 21,
	// Prohibited Verse path

	ProhibitedVersePath = 22,
	// Internal verse toolchain assert

	VerseToolChainInternalAssert = 23,
	// Internal verse toolchain error

	VerseToolChainLogError = 24,
	// The package contains virtualized data

	ContainsVirtualizedData = 25,
	// Insufficient permissions to create a Library project

	LibraryProjectNotPermitted = 26,
	// Public api validation error

	InvalidPublicApi = 27,
	// Dummy error used by warning logs

	Warning = 28,
	// Test error, for debugging purposes

	TestError = 29,
};

UENUM()
enum class EValkyrieValidationPermissionLevelFlag : uint8
{
	None = 0,
	VKCreateUGC = 1,
	VKCreateUGCEarlyAccess = 2,
	VKCreateUGCPartner = 4,
	VKCreateUGCEpicDeveloper = 8,
	All = 15,
};

