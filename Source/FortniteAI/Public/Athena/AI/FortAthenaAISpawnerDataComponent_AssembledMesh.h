// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_CosmeticBase.h"
#include "FortAthenaAISpawnerDataComponent_AssembledMesh.generated.h"

class UAssembledMeshSchema;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AssembledMesh : public UFortAthenaAISpawnerDataComponent_CosmeticBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UAssembledMeshSchema> AssembledMeshSchema;

};

