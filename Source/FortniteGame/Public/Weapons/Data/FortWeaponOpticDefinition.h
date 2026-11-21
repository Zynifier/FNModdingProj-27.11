// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/Scene.h"
#include "InstancedStruct.h"
#include "FortWeaponOpticDefinition.generated.h"

class UStreamableRenderAsset;

USTRUCT()
struct FFortLocator
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSocketLocator : public FFortLocator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSocketLocator")
	FName SocketName;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortWeaponOpticDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Optic", meta=(AllowedClasses="/Script/Engine.SkeletalMesh,/Script/Engine.StaticMesh"))
	TSoftObjectPtr<UStreamableRenderAsset> Mesh;

	UPROPERTY(EditAnywhere, NoClear, Category="Optic", meta=(BaseStruct="/Script/FortniteGame.FortLocator", ExcludeBaseStruct))
	FInstancedStruct EyePoint;

	UPROPERTY(EditAnywhere, NoClear, Category="Optic", meta=(BaseStruct="/Script/FortniteGame.FortLocator", ExcludeBaseStruct))
	FInstancedStruct TargetPoint;

	UPROPERTY(EditAnywhere, NoClear, Category="Optic", meta=(BaseStruct="/Script/FortniteGame.FortLocator", ExcludeBaseStruct))
	FInstancedStruct RadiusPoint;

	UPROPERTY(EditAnywhere, Category="Optic")
	float EyeRelief;

	UPROPERTY(EditAnywhere, Category="Optic")
	float FieldOfView;

	UPROPERTY(EditAnywhere, Category="Optic")
	bool bUsesFirstPersonAiming;

	UPROPERTY(EditAnywhere, Category="Optic|Material")
	TArray<FWeightedBlendable> PostProcessMaterial;

};

