// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/AssetData.h"
#include "Engine/DataAsset.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortCreativeActorCollection.generated.h"

class AActor;
class AFortGameStateAthena;
class UFortCreativeTagFilter;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortCreativeActorCollection : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnAssetUpdated(const FAssetData& InAssetData) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Creative Actor Collection")
	FText CollectionName;

	UPROPERTY(EditAnywhere, Instanced, Category="Creative Actor Collection", meta=(Patchable))
	TObjectPtr<UFortCreativeTagFilter> TagFilter;

	UPROPERTY(EditAnywhere, Category="Creative Actor Collection", meta=(Patchable))
	TSet<TSoftClassPtr<AActor>> AdditionalActors;

	UPROPERTY(EditAnywhere, Category="Creative Actor Collection", meta=(Patchable))
	TSet<TSoftClassPtr<AActor>> RestrictedActors;

	UPROPERTY(EditAnywhere, Category="Creative Actor Collection")
	TSoftClassPtr<AFortGameStateAthena> GameStateToIncludingBuildingActorsFrom;

};

