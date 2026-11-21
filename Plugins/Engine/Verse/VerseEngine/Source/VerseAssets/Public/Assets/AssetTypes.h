// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VerseAsset.h"
#include "AssetTypes.generated.h"

class UObject;

UCLASS()
class VERSEASSETS_API UVerseAssetPtr : public UVerseAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, SaveGame, Category="Asset")
	TSoftObjectPtr<UObject> AssetForEditor;

protected:
	UFUNCTION()
	void OnRep_AssetPathName();

	UPROPERTY(ReplicatedUsing=OnRep_AssetPathName)
	FName AssetPathName;

	UPROPERTY()
	TObjectPtr<UObject> Object;

};

