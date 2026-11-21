// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorFactories/ActorFactory.h"
#include "ValkyrieActorFactory.generated.h"

UCLASS(Abstract, MinimalAPI, HideCategories=("Object"))
class ULevelSaveRecordProviderActorFactory : public UActorFactory
{
	GENERATED_BODY()

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

};

UCLASS(MinimalAPI, HideCategories=("Object"))
class UValkyrieTrapActorFactory : public UActorFactory
{
	GENERATED_BODY()

};

