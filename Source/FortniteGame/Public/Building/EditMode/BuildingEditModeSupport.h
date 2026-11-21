// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "UObject/NoExportTypes.h"
#include "BuildingEditModeSupport.generated.h"

class ABuildingSMActor;
class AFortPlayerController;
class UBuildingEditModeMetadata;
class UCurveFloat;
class UMaterialInterface;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FEditPieceDelegate, ABuildingSMActor*, BuildingActor);

USTRUCT()
struct FEditModeState
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSubclassOf<ABuildingSMActor> EditClass;

	UPROPERTY(Transient)
	int32 RotationIterations;

	UPROPERTY(Transient)
	bool bMirrored;

	UPROPERTY(Transient)
	bool bCurrentlyValid;

};

UCLASS(Abstract, Config=Game)
class UBuildingEditModeSupport : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void OnSuccessfulMatchInteractComplete();

	UFUNCTION()
	virtual void OnSuccessfulMatchInteractParamUpdate(float NewInteractParamVal);

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingSMActor> OwnerBuilding;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> EditingController;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata> PreviewMetadata;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata> ScratchpadMetadata;

	UPROPERTY(Transient)
	TSubclassOf<UBuildingEditModeMetadata> ExpectedMetadataClass;

	UPROPERTY(Transient)
	TArray<TSubclassOf<ABuildingSMActor>> PossibleEditClasses;

	UPROPERTY(Transient)
	TSoftObjectPtr<UStaticMesh> EditTileMesh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> EditTileMeshComponents;

	UPROPERTY(Transient)
	TSoftObjectPtr<UMaterialInterface> TileMaterialParent;

	UPROPERTY(Transient)
	TSoftObjectPtr<UMaterialInterface> AlternateTileMaterialParent;

	UPROPERTY(Transient)
	TSoftObjectPtr<UTexture2D> ActiveTileTexture;

	UPROPERTY(Transient)
	TSoftObjectPtr<UTexture2D> InactiveTileTexture;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> LastInteractedComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> LastHighlightedComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> PreviewComponent;

	UPROPERTY(Transient)
	TSoftObjectPtr<UMaterialInterface> PreviewMaterial;

	UPROPERTY(Transient)
	TSoftObjectPtr<UMaterialInterface> AlternatePreviewMaterial;

	UPROPERTY(Transient)
	FEditModeState PreviewEditModeState;

	UPROPERTY(Transient)
	TSoftObjectPtr<UCurveFloat> SuccessfulPatternMatchCurve;

	UPROPERTY(Transient)
	FTimeline SuccessfulMatchInteractTimeline;

	UPROPERTY(Transient)
	uint8 bCanMirrorMetadataToMatch : 1;

	UPROPERTY(Transient)
	uint8 bCanRotateMetadataToMatch : 1;

	UPROPERTY(Transient)
	uint8 bEditActionInProgress : 1;

	UPROPERTY(Transient)
	uint8 bInitializedTimelines : 1;

	UPROPERTY(Transient)
	uint8 bUseAlternateMaterials : 1;

};

