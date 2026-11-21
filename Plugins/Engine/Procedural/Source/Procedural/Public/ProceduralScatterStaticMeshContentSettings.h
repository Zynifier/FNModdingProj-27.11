// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralScatterContentSettings.h"
#include "ProceduralScatterStaticMeshContentSettings.generated.h"

class AActor;
class UFoliageInstancedStaticMeshComponent;
class UHISMBuilderSettings;
class UMaterialInterface;
class UStaticMesh;

UENUM(BlueprintType)
enum class EProceduralScatterStaticMeshMode : uint8
{
	FromStaticMesh = 0,
	FromActor = 1,
};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object", "Object"))
class UProceduralScatterStaticMeshContentSettings : public UProceduralScatterContentSettings
{
	GENERATED_BODY()

public:
	/** The component class to use for instances.
	  * You can make a Blueprint subclass of FoliageInstancedStaticMeshComponent to implement custom behavior and assign that class here. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Component")
	TSubclassOf<UFoliageInstancedStaticMeshComponent> ComponentClass;

	/** The name of the tag to set on generated components. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Component")
	FName ComponentTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, NoClear, Instanced, Category="HISMSettings")
	TObjectPtr<UHISMBuilderSettings> VariationsInstancingSettings;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"))
class UProceduralScatterStaticMeshContentVariation : public UProceduralScatterContentVariation
{
	GENERATED_BODY()

public:
	/** Describes where to take the static mesh(es) from. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variation")
	EProceduralScatterStaticMeshMode StaticMeshMode;

	/** The single static mesh to use for instances. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variation", meta=(DisplayThumbnail="true", EditCondition="StaticMeshMode == EProceduralScatterStaticMeshMode::FromStaticMesh"))
	TObjectPtr<UStaticMesh> Mesh;

	/** The actor class to inspect in order to extract a cluster of static meshes to use for instances. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variation", meta=(EditCondition="StaticMeshMode == EProceduralScatterStaticMeshMode::FromActor"))
	TSubclassOf<AActor> ActorClass;

	/** Material overrides for instances. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Variation", meta=(EditCondition="StaticMeshMode == EProceduralScatterStaticMeshMode::FromStaticMesh"))
	TArray<TObjectPtr<UMaterialInterface>> OverrideMaterials;

	/** Overrides default variations instancing settings. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Instanced, Category="Variation")
	TObjectPtr<UHISMBuilderSettings> OverrideInstancingSettings;

};

