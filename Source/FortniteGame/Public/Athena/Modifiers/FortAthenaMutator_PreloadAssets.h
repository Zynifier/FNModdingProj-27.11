// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_PreloadAssets.generated.h"

class AActor;
class UAnimInstance;
class UDataAsset;
class UMaterialInstance;
class USkeletalMesh;
class UStaticMesh;

UCLASS(BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PreloadAssets : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PreloadAssets")
	TArray<TObjectPtr<UMaterialInstance>> MaterialInstances;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PreloadAssets")
	TArray<TObjectPtr<USkeletalMesh>> SkeletalMeshes;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PreloadAssets")
	TArray<TObjectPtr<UStaticMesh>> StaticMeshes;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PreloadAssets")
	TArray<TObjectPtr<UDataAsset>> DataAssets;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PreloadAssets")
	TArray<TSubclassOf<UAnimInstance>> AnimBlueprints;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PreloadAssets")
	TArray<TSubclassOf<AActor>> ActorBlueprints;

};

