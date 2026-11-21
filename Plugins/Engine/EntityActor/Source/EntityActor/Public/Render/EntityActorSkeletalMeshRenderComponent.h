// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "EntityComponent.h"
#include "EntityActorSkeletalMeshRenderComponent.generated.h"

class USkeletalMesh;

//class VAnimationInstance;

UENUM()
namespace EDefaultAnimationMode
{
	enum Type
	{
		UseAnimationBlueprint = 0,
		UseAnimationAsset = 1,
		UseCustomMode = 2,
	};
}

UCLASS(ClassGroup=("Entity"), meta=(DisplayName="Skeletal Mesh Component"))
class ENTITYACTOR_API UEntityActorSkeletalMeshRenderComponent : public UEntityComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool bAddedMeshRenderComponent;

	UPROPERTY(EditAnywhere, Category="SkeletalMesh", meta=(DisplayName="SkeletalMesh"))
	TObjectPtr<USkeletalMesh> ShadowVar_SkeletalMesh;

	UPROPERTY(EditAnywhere, Category="SkeletalMesh", meta=(DisplayName="Enable Collision"))
	TEnumAsByte<ECollisionEnabled::Type> ShadowVar_EnableCollision;

};

