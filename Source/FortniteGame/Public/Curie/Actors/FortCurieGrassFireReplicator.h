// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Core/FortSpatialGrid.h"
#include "FortStaticReplicatedActor.h"
#include "FortCurieGrassFireReplicator.generated.h"

class UFortPlaysetItemDefinition;

USTRUCT()
struct FFortCuriePackedGrassData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 Data;

};

USTRUCT()
struct FFortCuriePackedGrassDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FFortCuriePackedGrassData> Items;

};

UCLASS(MinimalAPI)
class AFortCurieGrassFireReplicator : public AFortStaticReplicatedActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_GrassGridCellSize();

	UFUNCTION()
	void OnRep_GrassGridOrigin();

	UFUNCTION()
	void OnRep_MaxGrassGridIndex();

	UFUNCTION()
	void OnRep_MinGrassGridIndex();

	UFUNCTION()
	void OnRep_PackedDataArray();

	UPROPERTY(Transient)
	TObjectPtr<UFortPlaysetItemDefinition> PlaysetUsedForGrassFX;

	UPROPERTY(ReplicatedUsing=OnRep_PackedDataArray)
	FFortCuriePackedGrassDataArray PackedDataArray;

	UPROPERTY(ReplicatedUsing=OnRep_MinGrassGridIndex)
	FFortSpatialCellIndex MinGrassGridIndex;

	UPROPERTY(ReplicatedUsing=OnRep_MaxGrassGridIndex)
	FFortSpatialCellIndex MaxGrassGridIndex;

	UPROPERTY(ReplicatedUsing=OnRep_GrassGridOrigin)
	FVector GrassGridOrigin;

	UPROPERTY(ReplicatedUsing=OnRep_GrassGridCellSize)
	FVector GrassGridCellSize;

};

