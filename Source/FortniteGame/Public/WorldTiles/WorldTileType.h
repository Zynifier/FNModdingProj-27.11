// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortTypes.h"
#include "WorldTileType.generated.h"

UCLASS()
class UWorldTileType : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	FString TileID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	TArray<FString> TileGroups;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	int32 TileWeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	TEnumAsByte<EFortTileEdgeType::Type> North;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	TEnumAsByte<EFortTileEdgeType::Type> East;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	TEnumAsByte<EFortTileEdgeType::Type> South;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	TEnumAsByte<EFortTileEdgeType::Type> West;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	TArray<FString> MapNames;

};

