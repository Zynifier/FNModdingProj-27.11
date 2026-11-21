// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "EntityActorComponent.h"
#include "EntityActorStaticMeshRenderComponent.generated.h"

class UMaterialInterface;

UENUM()
namespace EDefaultStaticMesh
{
	enum Type
	{
		Cube = 0,
		Sphere = 1,
		Cylinder = 2,
		Cone = 3,
		Plane = 4,
	};
}

UCLASS(ClassGroup=("Entity"), meta=(DisplayName="Static Mesh Component"))
class ENTITYACTOR_API UEntityActorStaticMeshRenderComponent : public UEntityActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_EnableCollision();

	UFUNCTION()
	void OnRep_MaxDrawDistance();

	UFUNCTION()
	void OnRep_MeshMaterials();

	UPROPERTY(ReplicatedUsing=OnRep_MeshMaterials)
	TArray<TObjectPtr<UMaterialInterface>> ShadowVar_MeshMaterials;

	UPROPERTY(ReplicatedUsing=OnRep_EnableCollision)
	TEnumAsByte<ECollisionEnabled::Type> ShadowVar_EnableCollision;

	UPROPERTY(ReplicatedUsing=OnRep_MaxDrawDistance)
	float ShadowVar_MaxDrawDistance;

};

