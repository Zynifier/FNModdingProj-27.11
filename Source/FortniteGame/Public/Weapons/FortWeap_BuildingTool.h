// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "Building/BuildingTypes.h"
#include "Weapons/FortWeap_BuildingToolBase.h"
#include "FortWeap_BuildingTool.generated.h"

class UBuildingEditModeMetadata;
class UCurveFloat;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UTexture2D;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Projectile", "Projectile", "Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeap_BuildingTool : public AFortWeap_BuildingToolBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Visual")
	TObjectPtr<UMaterialInterface> BlueprintPaperMaterial;

	UPROPERTY(EditAnywhere, Category="Visual", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	TObjectPtr<UTexture2D> BlueprintDiffuseTextures[6];

	UPROPERTY(EditAnywhere, Category="Visual", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	TObjectPtr<UTexture2D> BlueprintEmissiveMaskTextures[6];

	UPROPERTY(EditAnywhere, Category="Visual")
	TObjectPtr<UCurveFloat> BlueprintPaperPulseCurve;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DefaultMetadata)
	TObjectPtr<UBuildingEditModeMetadata> DefaultMetadata;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> BlueprintPaperMID;

	UPROPERTY(Transient)
	FTimeline BlueprintPaperPulseTimeline;

	UPROPERTY(Transient)
	TEnumAsByte<EFortResourceType::Type> LastResourceType;

private:
	UFUNCTION()
	void OnBlueprintPaperPulseUpdate(float InCurveVal);

	UFUNCTION()
	void OnRep_DefaultMetadata(UBuildingEditModeMetadata* OldMetadata);

};

