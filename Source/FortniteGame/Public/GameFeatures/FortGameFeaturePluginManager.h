// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureStateChangeObserver.h"
#include "GameFeaturesProjectPolicies.h"
#include "UObject/NoExportTypes.h"
#include "FortGameFeaturePluginManager.generated.h"

UCLASS(Config=Game, MinimalAPI)
class UFortGameFeaturePluginManager : public UGameFeaturesProjectPolicies
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_AIGoals : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_EquipAbilitySet : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_FortPlayerController : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_GameplayCueObserver : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_HotfixManager : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_LevelOverlayObserver : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_PlaylistObserver : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_PreloadItemDefsInAthena : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

UCLASS()
class UFortGameFeature_StatePauseChangeObserver : public UObject, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

};

