// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "Cosmetics/FortCosmeticAssetContext.h"
#include "FortCustomizationAssetLoader.generated.h"

class AFortPlayerPawn;
class UCustomCharacterPart;
class UFortCustomizationAssetLoader;
class UFortHeroType;
class UFortItemDefinition;
class UObject;

UENUM()
enum class EAssetLoadHistoryState : uint8
{
	None = 0,
	Requested = 1,
	Cancelled = 2,
	Finished = 3,
	Removed = 4,
};

UENUM(Flags, meta=(Bitflags))
enum class EFortCustomizationAssetLoaderFlags : uint16
{
	None = 1,
	ForceSynchronousLoad = 2,
	CustomizationDestroy = 4,
	CustomizationStart = 8,
	LoadNewAssets = 16,
	EndPlay = 32,
	Destroyed = 64,
	LevelTransition = 128,
	EndPlayInEditor = 256,
	RemovedFromWorld = 512,
	Quit = 1024,
};

USTRUCT()
struct FFortCustomizationAssetsToLoadSourceInterface
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortCustomizationAssetsToLoad : public FFortCustomizationAssetsToLoadSourceInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortHeroType>> HeroTypes;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UCustomCharacterPart>> CharacterParts;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ItemDefs;

};

UCLASS()
class UFortCustomizationAssetLoader : public UObject, public IFortCosmeticAssetContext
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> CurrentContentOnDemandItemDefs;

	UPROPERTY(Transient)
	TMap<FSoftObjectPath, TObjectPtr<UObject>> LoadedAssetPaths;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> PawnForOnDemandContentRelevance;

};

UCLASS()
class UFortCustomizationAssetLoaderSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortCustomizationAssetLoader> DetachedLoader;

};

