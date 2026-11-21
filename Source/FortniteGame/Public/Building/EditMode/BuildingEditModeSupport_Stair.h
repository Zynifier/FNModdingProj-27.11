// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/EditMode/BuildingEditModeSupport.h"
#include "BuildingEditModeSupport_Stair.generated.h"

class UBuildingEditModeMetadata_Stair;
class UMaterialInterface;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;

UENUM()
enum EAuxIndicatorStates
{
	// Auxiliary component is providing a directional arrow to a valid move the user can make

	AIS_GuidingArrow = 0,
	// Auxiliary component is showing a directional arrow of a confirmed move the user already made

	AIS_ConfirmedArrow = 1,
	// Auxiliary component is inactive and hasn't been touched by the user

	AIS_Inactive = 2,
	// Auxiliary component has been touched by the user

	AIS_Active = 3,
};

UCLASS()
class UBuildingEditModeSupport_Stair : public UBuildingEditModeSupport
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata_Stair> StairPreviewMetadata;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata_Stair> LastValidMetadataConfiguration;

	UPROPERTY(Transient)
	TSoftObjectPtr<UStaticMesh> AuxiliaryIndicatorMesh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> AuxiliaryIndicatorComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ActivatedAuxIndicatorComponent;

	UPROPERTY(Transient)
	TSoftObjectPtr<UMaterialInterface> AuxIndicatorComponentParentMaterial;

	UPROPERTY(Transient)
	TSoftObjectPtr<UTexture2D> AuxIndicatorArrowTexture;

	UPROPERTY(Transient)
	TSoftObjectPtr<UTexture2D> AuxIndicatorGridTexture;

};

