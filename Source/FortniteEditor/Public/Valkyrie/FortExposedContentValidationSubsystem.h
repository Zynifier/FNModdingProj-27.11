// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "UObject/TopLevelAssetPath.h"
#include "FortExposedContentValidationSubsystem.generated.h"

class AActor;
class ILevelSaveRecordProvider;
class UFortExposedContentManifest;
class UFortExposedContentValidationActorProxy;
class UFortExposedContentValidationWorldProxy;
class ULevelSaveRecord;
class UWorld;

USTRUCT(BlueprintType)
struct FFortExposedContentValidatedPackage
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	FName PackageName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	FString PackageFilename;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	TArray<FString> PackageErrors;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	TArray<FString> PackageWarnings;

};

USTRUCT(BlueprintType)
struct FFortExposedContentValidatePackagesResult
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	TArray<FFortExposedContentValidatedPackage> ValidatedPackages;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	TArray<FString> GeneralErrors;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	TArray<FString> GeneralWarnings;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	bool bHasAnyErrors;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortExposedContent")
	bool bHasAnyWarnings;

};

UCLASS(Transient, MinimalAPI)
class UFortExposedContentManifest : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	bool HasManifest() const;

	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	FFortExposedContentValidatePackagesResult ValidatePackage(const FString& PackageFilename) const;

	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	FFortExposedContentValidatePackagesResult ValidatePackages(const TArray<FString>& PackageFilenames) const;

	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	FFortExposedContentValidatePackagesResult ValidatePluginPackage(const FString& PackageFilename, const TArray<FString>& AllowedPluginReferences) const;

	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	FFortExposedContentValidatePackagesResult ValidatePluginPackages(const TArray<FString>& PackageFilenames, const TArray<FString>& AllowedPluginReferences) const;

private:
	UFUNCTION(BlueprintPure, Category="FortExposedContent", meta=(DisplayName="Is Valid Reference (Asset Path)"))
	bool IsValidAssetPathReference(const FTopLevelAssetPath& AssetPath) const;

	UFUNCTION(BlueprintPure, Category="FortExposedContent", meta=(DisplayName="Is Valid Reference (Object Path)"))
	bool IsValidObjectPathReference(const FSoftObjectPath& ObjectPath) const;

};

UCLASS(Transient, MinimalAPI)
class UFortExposedContentValidationActorProxy : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	void DestroyActor();

	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	AActor* GetActor() const;

	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	FFortExposedContentValidatePackagesResult ValidateActor(const UFortExposedContentManifest* Manifest) const;

private:
	UPROPERTY()
	TSoftObjectPtr<AActor> Actor;

};

UCLASS(MinimalAPI)
class UFortExposedContentValidationSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	bool BuildCurrentManifest(const bool bSilent = false) const;

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	UFortExposedContentValidationWorldProxy* CreateBackgroundValidationWorld();

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	UFortExposedContentValidationWorldProxy* CreateEditorValidationWorld(const bool bSilent = false);

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	const UFortExposedContentManifest* GetCurrentManifest();

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	const UFortExposedContentManifest* GetPreviousManifest();

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	void ShowValidationReport(const FFortExposedContentValidatePackagesResult& Result, const bool bClearPage = true);

	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	bool SyncCurrentManifest(const bool bSilent = false) const;

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortExposedContentManifest>> CachedManifests;

};

UCLASS(Transient, MinimalAPI)
class UFortExposedContentValidationWorldProxy : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortExposedContent")
	virtual UWorld* GetWorld() const;

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	UFortExposedContentValidationActorProxy* SpawnActor(const TSubclassOf<AActor>& ActorClass);

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	UFortExposedContentValidationActorProxy* SpawnActorWithTransform(const TSubclassOf<AActor>& ActorClass, const FTransform& ActorTransform);

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	TArray<UFortExposedContentValidationActorProxy*> SpawnLevelSaveRecord(ULevelSaveRecord* LevelSaveRecord);

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	TArray<UFortExposedContentValidationActorProxy*> SpawnLevelSaveRecordProvider(TScriptInterface<ILevelSaveRecordProvider> LevelSaveRecordProvider);

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	TArray<UFortExposedContentValidationActorProxy*> SpawnLevelSaveRecordProviderWithTransform(TScriptInterface<ILevelSaveRecordProvider> LevelSaveRecordProvider, const FTransform& LevelSaveRecordRootTransform);

	UFUNCTION(BlueprintCallable, Category="FortExposedContent")
	TArray<UFortExposedContentValidationActorProxy*> SpawnLevelSaveRecordWithTransform(ULevelSaveRecord* LevelSaveRecord, const FTransform& LevelSaveRecordRootTransform);

private:
	UPROPERTY()
	TSoftObjectPtr<UWorld> World;

	UPROPERTY()
	TObjectPtr<UWorld> OwnedWorld;

};

