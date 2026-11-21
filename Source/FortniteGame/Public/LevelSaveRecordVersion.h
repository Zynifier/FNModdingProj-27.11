// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSaveRecordVersion.generated.h"

UENUM(BlueprintType)
namespace ELevelSaveRecordVersion
{
	enum Type
	{
		CloudSaveInfoAdded = 0,
		// Converted Timestamps to linearly increasing event indices.

		TimestampConversion = 1,
		// Made actor class references soft so they are not loaded automatically

		SoftActorClassReferences = 2,
		// Made actor component class references soft so they are not loaded automatically

		SoftActorComponentClassReferences = 3,
		// Additional step to remove duplicate actor records from bad user files.

		DuplicateNewActorRecordsRemoved = 4,
		// Additional step to resave the spawned actors when our save version is behind.

		StartOfResaveWhenNotLatestVersion = 5,
		// Adding CVar for how close Buildings need to be to be considered in the same location

		LowerCloseThresholdForDuplicates = 6,
		// Removed the DeleteActorRecords and NewActorRecords in favor of a map of ActorRecords

		DeprecatedDeleteAndNewActorRecords = 7,
		// Adding the dependencies from the serialized world so that the cooker find all necessary assets

		DependenciesFromSerializedWorld = 8,
		// Removing the dependencies from the serialized world (this was unneeded)

		RemovingSerializedDependencies = 9,
		// Adding Volume info actor array for custom volume actors

		AddingVolumeInfoRecordsMap = 10,
		// Adding contextual information about volumes to enforce grid placement

		AddingVolumeGridDependency = 11,
		// Adding Scale

		AddingScale = 12,
		// Adding hashed data bytes for corruption detection.

		AddingDataHash = 13,
		// Added creative island template id

		AddedIslandTemplateId = 14,
		// Adding FLevelStreamedDeleteActorRecord to track LevelStreamed changes.

		AddedLevelStreamedDeleteRecord = 15,
		// Switch to using SavedActorGUID which is a GUID instead of the Actor FName for unique identification.

		UsingSaveActorGUID = 16,
		// Applying Actor FName in Valkyrie ES to reduce name instability

		UsingActorFNameForEditorSpawning = 17,
		// Support for users to be able to wipe player persistence for their islands

		AddedPlayerPersistenceUserWipeNumber = 18,
		// No data added at this point (version shouldn't have been added)

		Unused = 19,
		// Additional Vk modules to provide placeable content

		AddedVkPalette = 20,
		// Switching to Use core UProperty Serialization.

		SwitchingToCoreSerialization = 21,
		// Adding if Navmesh is required or not

		AddedNavmeshRequired = 22,
		// UE5

		InitialUEFiveChange = 23,
		// Adding if Persistence is required or not

		AddedPersistenceRequired = 24,
		// Adding Level Instance to support embedded LSRs

		AddedLevelInstance = 25,
		// Inner archivers will serialize the header they were serialized at

		AddedInnerArchiverSerialization = 26,
		// Added FActorTemplateRecord::ActorDataHardReferences and FActorComponentRecord::ComponentDataHardReferences

		AddedHardReferenceTracking = 27,
		// Added FActorTemplateRecord::DataHeaderSize and FActorComponentRecord::DataHeaderSize

		AddedDataHeaderSize = 28,
		// Added PropertyToActorGuid and ComponentRecordPropertyToActorGuid to support actor cross reference saving

		AddedCrossReferenceSaving = 29,
		// We will now spawn actors with the FName they had when they were spawned

		SpawningActorsWithConsistentName = 30,
		// Updating PackageName from IslandTemplateId

		UpdatePackageNameFromIslandTemplateId = 31,
		// large world coordinates changed serialization of FVector and FTransform we need to use the old type of FVector3 and FTransform3

		LargeWorldCoordinateSerializationChange = 32,
		// Bumping Version for seasion 22.00

		SeasionTwentyTwoRelease = 33,
		// Updating to force unique names for actors on load once

		EnforceUniqueLabels = 34,
		// Adding config for any non saveGame property to be saveable.

		AddedConfigForNonSaveGameProperties = 35,
		// Added level save tags.

		AddedLevelSaveTags = 36,
		// Added support for serializing owned subobjects (e.g., for verse)

		AddedSubobjectSerialization = 37,
		// Refactored subobject serialization to make it more comprehensive. There is not expected to be any persisted content 
// on the previous version that would be subject to the changes in serialization flow (because it only applies to AScriptDevice at the moment)
// so the code path for AddedSubobjectSerialization has not been preserved

		RefactoredSubobjectSerialization = 38,
		// Make sure to remove any event bindings that don't have valid actors after fulling loading the level

		RemoveInvalidEventBindings = 39,
		// - Please see @Eric.Knapik and @Cory.Kolek (Creative Engineering Lead) for modifying this file.
// - Not all live servers are at the latest version and .island files are interchangeable and will need updated.
// -----<new versions can be added before this line>-------------------------------------------------
// - this needs to be the last line (see note below)

		VersionPlusOne = 40,
		LatestVersion = 39,
	};
}

