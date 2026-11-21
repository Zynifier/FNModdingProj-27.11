// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MLDeformerComponent.h"
#include "FortMLDeformerComponent.generated.h"

class UMLDeformerAsset;
class UMeshDeformer;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Component"), meta=(BlueprintSpawnableComponent))
class UFortMLDeformerComponent : public UMLDeformerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UMLDeformerAsset> RequestedMLDeformerAsset;

	UPROPERTY()
	TObjectPtr<UMeshDeformer> RequestedMeshDeformerAsset;

};

