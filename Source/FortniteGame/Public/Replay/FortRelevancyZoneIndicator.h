// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Styling/SlateBrush.h"
#include "FortRelevancyZoneIndicator.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
class UStaticMeshComponent;

UCLASS(Abstract, BlueprintType, Blueprintable)
class AFortRelevancyZoneIndicator : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="RelevancyZone", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> RelevancyZoneMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="RelevancyZone", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> CustomDepthMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RelevancyZone")
	float RelevancyZoneToWorldScale;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialInterface> MiniMapNetRelevancyOverlayMaterial;

	UPROPERTY(EditDefaultsOnly, Category="MiniMap")
	TObjectPtr<UMaterialInterface> MiniMapNetRelevancyCircleMaterial;

private:
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MinimapNetRelevancyOverlayMID;

	UPROPERTY(Transient)
	FSlateBrush MinimapNetRelevancyOverlayBrush;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> MinimapNetRelevancyCircleMID;

	UPROPERTY(Transient)
	FSlateBrush MinimapNetRelevancyCircleBrush;

};

