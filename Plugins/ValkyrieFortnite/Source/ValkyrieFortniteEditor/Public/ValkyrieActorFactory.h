// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "ValkyrieActorFactory.generated.h"

UCLASS(Abstract, MinimalAPI, HideCategories=("Object"))
class ULevelSaveRecordProviderActorFactory : public UActorFactory
{
	GENERATED_BODY()

public:
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override
	{
		// The base implementation dereferences the default actor for valid assets.
		return GetDefaultActor(AssetData) != nullptr && Super::CanCreateActorFrom(AssetData, OutErrorMsg);
	}

};

UCLASS(MinimalAPI, HideCategories=("Object"))
class UValkyriePlaysetActorFactory : public ULevelSaveRecordProviderActorFactory
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Object"))
class UValkyriePlaysetPropActorFactory : public ULevelSaveRecordProviderActorFactory
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Object"))
class UValkyrieSpawnableItemActorFactory : public UActorFactory
{
	GENERATED_BODY()

public:
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override
	{
		// The base implementation dereferences the default actor for valid assets.
		return GetDefaultActor(AssetData) != nullptr && Super::CanCreateActorFrom(AssetData, OutErrorMsg);
	}

};

UCLASS(MinimalAPI, HideCategories=("Object"))
class UValkyrieTrapActorFactory : public UActorFactory
{
	GENERATED_BODY()

public:
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override
	{
		// The base implementation dereferences the default actor for valid assets.
		return GetDefaultActor(AssetData) != nullptr && Super::CanCreateActorFrom(AssetData, OutErrorMsg);
	}

};

