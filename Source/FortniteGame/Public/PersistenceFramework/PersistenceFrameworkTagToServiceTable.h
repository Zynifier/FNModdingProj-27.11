// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistrySource.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "PersistenceFrameworkTagToServiceTable.generated.h"

class UDataRegistrySource_PersistenceFrameworkTagToServiceTable;
class UPersistenceFrameworkServiceSettingsBase;
class UPersistenceFrameworkTagToServiceTable;

USTRUCT(BlueprintType)
struct FORTNITEGAME_API FPersistenceFrameworkServiceAssetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PersistenceFrameworkServiceAssetInfo")
	TObjectPtr<UPersistenceFrameworkServiceSettingsBase> Service;

	UPROPERTY(EditAnywhere, Category="PersistenceFrameworkServiceAssetInfo")
	bool bAllowNull;

};

USTRUCT()
struct FORTNITEGAME_API FServiceRegistrySource_ServiceTableRules
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ServiceRegistry")
	bool bPrecacheTable;

	UPROPERTY(EditAnywhere, Category="ServiceRegistry")
	float CachedTableKeepSeconds;

};

UCLASS(meta=(DisplayName="Persistent Framework ServiceTable Source"))
class FORTNITEGAME_API UDataRegistrySource_PersistenceFrameworkTagToServiceTable : public UDataRegistrySource
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DataRegistry")
	TSoftObjectPtr<UPersistenceFrameworkTagToServiceTable> SourceTable;

	UPROPERTY(EditAnywhere, Category="DataRegistry")
	FServiceRegistrySource_ServiceTableRules TableRules;

protected:
	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkTagToServiceTable> CachedTable;

	UPROPERTY()
	TObjectPtr<UPersistenceFrameworkTagToServiceTable> PreloadTable;

};

UCLASS(meta=(DisplayName="Persistent Framework ServiceTable Meta Source"))
class FORTNITEGAME_API UMetaDataRegistrySource_PersistenceFrameworkTagToServiceTable : public UMetaDataRegistrySource
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="DataRegistry")
	TSubclassOf<UDataRegistrySource_PersistenceFrameworkTagToServiceTable> CreatedSource;

	UPROPERTY(EditAnywhere, Category="DataRegistry")
	FServiceRegistrySource_ServiceTableRules TableRules;

};

UCLASS(meta=(DisplayName="Persistent Framework Tag to Service Table"))
class FORTNITEGAME_API UPersistenceFrameworkTagToServiceTable : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="PersistenceFrameworkTagToServiceTable", meta=(AssetBundles="Server", Categories="Persistence.UsedBy", ForceInlineRow, TitleProperty="Service"))
	TMap<FGameplayTag, FPersistenceFrameworkServiceAssetInfo> ServiceSettings;

};

