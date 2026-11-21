// Copyright Epic Games, Inc. All Rights Reserved.

#include "Valkyrie/FortExposedContentValidationSubsystem.h"

bool UFortExposedContentManifest::HasManifest() const
{
	return false;
}

bool UFortExposedContentManifest::IsValidAssetPathReference(const FTopLevelAssetPath& AssetPath) const
{
	return false;
}

bool UFortExposedContentManifest::IsValidObjectPathReference(const FSoftObjectPath& ObjectPath) const
{
	return false;
}

FFortExposedContentValidatePackagesResult UFortExposedContentManifest::ValidatePackage(const FString& PackageFilename) const
{
	return FFortExposedContentValidatePackagesResult();
}

FFortExposedContentValidatePackagesResult UFortExposedContentManifest::ValidatePackages(const TArray<FString>& PackageFilenames) const
{
	return FFortExposedContentValidatePackagesResult();
}

FFortExposedContentValidatePackagesResult UFortExposedContentManifest::ValidatePluginPackage(const FString& PackageFilename, const TArray<FString>& AllowedPluginReferences) const
{
	return FFortExposedContentValidatePackagesResult();
}

FFortExposedContentValidatePackagesResult UFortExposedContentManifest::ValidatePluginPackages(const TArray<FString>& PackageFilenames, const TArray<FString>& AllowedPluginReferences) const
{
	return FFortExposedContentValidatePackagesResult();
}

void UFortExposedContentValidationActorProxy::DestroyActor()
{
}

AActor* UFortExposedContentValidationActorProxy::GetActor() const
{
	return nullptr;
}

FFortExposedContentValidatePackagesResult UFortExposedContentValidationActorProxy::ValidateActor(const UFortExposedContentManifest* Manifest) const
{
	return FFortExposedContentValidatePackagesResult();
}

bool UFortExposedContentValidationSubsystem::BuildCurrentManifest(const bool bSilent) const
{
	return false;
}

UFortExposedContentValidationWorldProxy* UFortExposedContentValidationSubsystem::CreateBackgroundValidationWorld()
{
	return nullptr;
}

UFortExposedContentValidationWorldProxy* UFortExposedContentValidationSubsystem::CreateEditorValidationWorld(const bool bSilent)
{
	return nullptr;
}

const UFortExposedContentManifest* UFortExposedContentValidationSubsystem::GetCurrentManifest()
{
	return nullptr;
}

const UFortExposedContentManifest* UFortExposedContentValidationSubsystem::GetPreviousManifest()
{
	return nullptr;
}

void UFortExposedContentValidationSubsystem::ShowValidationReport(const FFortExposedContentValidatePackagesResult& Result, const bool bClearPage)
{
}

bool UFortExposedContentValidationSubsystem::SyncCurrentManifest(const bool bSilent) const
{
	return false;
}

UWorld* UFortExposedContentValidationWorldProxy::GetWorld() const
{
	return nullptr;
}

UFortExposedContentValidationActorProxy* UFortExposedContentValidationWorldProxy::SpawnActor(const TSubclassOf<AActor>& ActorClass)
{
	return nullptr;
}

UFortExposedContentValidationActorProxy* UFortExposedContentValidationWorldProxy::SpawnActorWithTransform(const TSubclassOf<AActor>& ActorClass, const FTransform& ActorTransform)
{
	return nullptr;
}

TArray<UFortExposedContentValidationActorProxy*> UFortExposedContentValidationWorldProxy::SpawnLevelSaveRecord(ULevelSaveRecord* LevelSaveRecord)
{
	return TArray<UFortExposedContentValidationActorProxy*>();
}

TArray<UFortExposedContentValidationActorProxy*> UFortExposedContentValidationWorldProxy::SpawnLevelSaveRecordProvider(TScriptInterface<ILevelSaveRecordProvider> LevelSaveRecordProvider)
{
	return TArray<UFortExposedContentValidationActorProxy*>();
}

TArray<UFortExposedContentValidationActorProxy*> UFortExposedContentValidationWorldProxy::SpawnLevelSaveRecordProviderWithTransform(TScriptInterface<ILevelSaveRecordProvider> LevelSaveRecordProvider, const FTransform& LevelSaveRecordRootTransform)
{
	return TArray<UFortExposedContentValidationActorProxy*>();
}

TArray<UFortExposedContentValidationActorProxy*> UFortExposedContentValidationWorldProxy::SpawnLevelSaveRecordWithTransform(ULevelSaveRecord* LevelSaveRecord, const FTransform& LevelSaveRecordRootTransform)
{
	return TArray<UFortExposedContentValidationActorProxy*>();
}
