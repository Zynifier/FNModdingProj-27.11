// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingSMActor.h"
#include "Building/BuildingTypes.h"
#include "Weapons/Data/FortWeaponItemDefinition.h"
#include "FortDecoItemDefinition.generated.h"

class ABuildingActor;
class AFortDecoPreview;
class AFortPlayerController;
class UBuildingEditModeMetadata;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Damage", "Effects"))
class UFortDecoItemDefinition : public UFortWeaponItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	TSubclassOf<ABuildingActor> GetBlueprintClass() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	float GetGridPlacementOffset() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	float GetGridSnapSizeOverride() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	int32 GetMaxPlacementDistance() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	TSubclassOf<AFortDecoPreview> GetPlacementPreviewClass() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	EPlacementType::Type GetPlacementTypeOverride() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	float GetRotationAngleIncrement() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool RequiresPermissionToEditWorld() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool RequiresPlayerPlaceableAttachmentActors() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldAllowAnyFloorPlacement() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldAllowPlacementOnBuildings() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldAllowPlacementOnWorldGeometry() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldAllowStairsWhenAttachingToFloors() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldAttachWhenPlacing() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldCancelAbilityOnUnequip() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldCancelToolWhenPlaced() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldConsumeWhenPlaced(const AFortPlayerController* PlayerController = nullptr) const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldDestroySmallObjectsWhenPlaced() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldDisableLocationLerpWhilePlacing() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldDisableRotationLerpWhilePlacing() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldDisableScaleLerpWhilePlacing() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldForceIgnoreBuildingOverlaps() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldForceIgnoreOverlapTest() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldIgnoreCollisionWithCriticalActors() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldIgnoreCollisionWithFortStaticMeshActors() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldIgnoreCollisionWithPlayers() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldIgnoreCollisionWithStructuralGridActors() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldIgnoreCollisionWithVehicles() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldSnapYawToHorizontalAxes() const;

	UFUNCTION(BlueprintPure, Category="DecoItemDefinition")
	bool ShouldUseRelativeCameraRotation() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	bool bReplacesEditedSurfaces;

protected:
	UPROPERTY(EditDefaultsOnly, Category="BuildingActor", meta=(AssetBundles="ItemsInInventoryInZone,Equipped,ClientAthenaPreload"))
	TSoftClassPtr<ABuildingActor> BlueprintClass;

	UPROPERTY(EditDefaultsOnly, Category="BuildingActor", meta=(AssetBundles="ItemsInInventoryInZone,Equipped,ClientAthenaPreload"))
	TSoftClassPtr<AFortDecoPreview> PlacementPreviewClass;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bCanBePlacedOnEnemyBuildings : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	float GridSnapSizeOverride;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	float RotationAngleIncrement;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	float GridPlacementOffset;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	TEnumAsByte<EPlacementType::Type> PlacementTypeOverride;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bForceIgnoreOverlapTest : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bIgnoreCollisionWithVehicles : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bForceIgnoreBuildingOverlaps : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bIgnoreCollisionWithCriticalActors : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bIgnoreCollisionWithStructuralGridActors : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bIgnoreCollisionWithFortStaticMeshActors : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bIgnoreCollisionWithPlayers : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bDisableLocationLerpWhilePlacing : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bDisableRotationLerpWhilePlacing : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bDisableScaleLerpWhilePlacing : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bAttachWhenPlacing : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bAllowPlacementOnWorldGeometry : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bAllowPlacementOnBuildings : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bDestroySmallObjectsWhenPlaced : 1;

	UPROPERTY(EditDefaultsOnly, Category="Functionality")
	uint8 bSetOwningPlayerForSpawnedDeco : 1;

	UPROPERTY(EditDefaultsOnly, Category="Functionality")
	bool bSetSpawnedDecoOnPlayerTeam;

	UPROPERTY(EditDefaultsOnly, Category="Functionality")
	uint8 bConsumeWhenPlaced : 1;

	UPROPERTY(EditDefaultsOnly, Category="Functionality")
	uint8 bCancelToolWhenPlaced : 1;

	UPROPERTY(EditDefaultsOnly, Category="Functionality")
	uint8 bCancelAbilityOnUnequip : 1;

	UPROPERTY(EditDefaultsOnly, Category="Attachment")
	uint8 bRequiresPlayerPlaceableAttachmentActors : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bUseRelativeCameraRotation : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bAllowStairsWhenAttachingToFloors : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bSnapYawToHorizontalAxes : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bAllowAnyFloorPlacement : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bRequiresPermissionToEditWorld : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bAutoCreateAttachmentBuilding : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo", meta=(EditCondition="bAutoCreateAttachmentBuilding"))
	uint8 bAllowAutoCreateExtraPiece : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo", meta=(EditCondition="bAllowAutoCreateExtraPiece"))
	uint8 bGiveFreeDecoOnUndergroundPiece : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Trap")
	uint8 bReplacesDecoOnAttachment : 1;

	UPROPERTY(EditDefaultsOnly, Category="Trap")
	uint8 bReplacesBuildingWhenPlaced : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bShowPreviewOnPressHeld : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	uint8 bServerValidateCollision : 1;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo", meta=(EditCondition="bAutoCreateAttachmentBuilding"))
	TEnumAsByte<EFortResourceType::Type> AutoCreateAttachmentBuildingResourceType;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo")
	int32 MaxPlacementDistance;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo", meta=(AssetBundles="ClientAthenaPreload"))
	TArray<TSoftObjectPtr<UBuildingEditModeMetadata>> AutoCreateAttachmentBuildingShapes;

	UPROPERTY(EditDefaultsOnly, Category="Attachment", meta=(AssetBundles="ClientAthenaPreload"))
	TArray<TSoftObjectPtr<UBuildingEditModeMetadata>> AllowedShapes;

	UPROPERTY(EditDefaultsOnly, Category="Attachment", meta=(AssetBundles="ClientAthenaPreload"))
	TArray<TSoftObjectPtr<UBuildingEditModeMetadata>> AllowedPlayerBuiltShapes;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo", meta=(EditCondition="bServerValidateCollision", EditConditionHides))
	FVector CollisionBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="PlacementInfo", meta=(EditCondition="bServerValidateCollision", EditConditionHides))
	FVector CollisionBoxOffset;

};

