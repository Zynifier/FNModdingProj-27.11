// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/EditMode/BuildingEditModeMetadata_BinaryToggle.h"
#include "BuildingEditModeMetadata_Roof.generated.h"

class UStaticMesh;
class UTexture2D;

USTRUCT(BlueprintType)
struct FAuxiliaryEditTileMeshData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh")
	TObjectPtr<UStaticMesh> TileMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh")
	TObjectPtr<UTexture2D> TileTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mesh")
	FRotator RelativeRot;

};

UCLASS(MinimalAPI)
class UBuildingEditModeMetadata_Roof : public UBuildingEditModeMetadata_BinaryToggle
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileData")
	TArray<FAuxiliaryEditTileMeshData> AuxEditTileMeshData;

};

