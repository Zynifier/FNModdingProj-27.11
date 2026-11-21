// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "UObject/NoExportTypes.h"
#include "Items/FortPlaysetSettings.h"
#include "PlaysetGeneration.generated.h"

class AActor;
class UFortPlaysetItemDefinition;
class UFortPlaysetPropItemDefinition;
class UWorld;

UCLASS()
class UActorPlaysetGenerationTask : public UObject
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TSubclassOf<AActor> ActorClass;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UFortPlaysetItemDefinition> Playset;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	FPlaysetSettings PlaysetSettings;
#endif

};

UCLASS()
class UPPIDThumbnailGenerationQueue : public UObject
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortPlaysetPropItemDefinition>> PPIDs;
#endif

};

UCLASS()
class UPlaysetGenerationQueue : public UObject
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortPlaysetItemDefinition>> Playsets;
#endif

};

UCLASS()
class UWorldPlaysetGenerationTask : public UObject
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UWorld> World;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortPlaysetItemDefinition>> AssociatedPlaysets;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TSet<TObjectPtr<UFortPlaysetPropItemDefinition>> AllPPIDs;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TSet<TObjectPtr<UFortPlaysetPropItemDefinition>> ThumbnailDirtyPPIDs;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TSet<FName> ModifiedPackages;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<FAssetData> AssetsToDelete;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<FName> PPIDRedirectorNames;
#endif

};

