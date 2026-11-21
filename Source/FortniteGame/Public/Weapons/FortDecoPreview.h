// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Building/BuildingSMActor.h"
#include "Building/BuildingTypes.h"
#include "FortDecoPreview.generated.h"

class ABuildingActor;
class AFortDecoHelper;
class UCurveFloat;
class UFortDecoItemDefinition;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMeshComponent;
class UTexture;

UCLASS(Abstract, BlueprintType, Blueprintable)
class AFortDecoPreview : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="PlacementVisuals")
	UMaterialInstanceDynamic* CreatePreviewMID(UMaterialInterface* OverrideParentMaterial = nullptr);

	UFUNCTION(BlueprintCallable, Category="PlacementVisuals")
	UTexture* GetTextureParameterValueFromMeshComponent(UMeshComponent* MeshComp, int32 ElementIdx, FName ParamName);

	UFUNCTION(BlueprintNativeEvent, Category="PlacementVisuals")
	void OnBounceMotionUpdate(float VectorScale);

	UFUNCTION(BlueprintNativeEvent, Category="PlacementVisuals")
	void OnInitializeDecoPreview(const ABuildingActor* NewBuildingActor, const UFortDecoItemDefinition* NewDecoItemDefinition);

	UFUNCTION(BlueprintNativeEvent, Category="PlacementVisuals")
	void OnUpdateScale(float Scale, const FVector& InWorldSpacePivot);

	UFUNCTION(BlueprintNativeEvent, Category="PlacementVisuals")
	void OnUpdateVisuals(float DeltaSeconds, bool bSafeToPlace);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="PlacementVisuals")
	void SetScalarParameterValueOnAllPreviewMIDs(FName ParamName, float ParamValue);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="PlacementVisuals")
	void SetVectorParameterValueOnAllPreviewMIDs(FName ParamName, const FLinearColor& ParamValue);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Placement")
	TEnumAsByte<EBuildingAttachmentType> FallbackAttachmentType;

	UPROPERTY(EditDefaultsOnly, Category="Placement")
	TEnumAsByte<EPlacementType::Type> FallbackPlacementType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	TSoftObjectPtr<UMaterialInterface> PreviewPlacementMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	TSoftObjectPtr<UCurveFloat> MotionBounceCurve;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	FName CanBePlacedMaterialScalarParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	float ValidPlacementScalarParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	float InvalidPlacementScalarParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	FName InverseMovementVectorMaterialParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	float MovementEffectScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	FName InverseOuterScaleVectorParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	FName InverseInnerScaleVectorParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	FName WorldSpacePivotVectorParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlacementVisuals")
	FName DiffuseTextureParam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Placement")
	float FreePlacementOffset;

	UPROPERTY()
	FTimeline BounceTimeline;

	UPROPERTY()
	TArray<TObjectPtr<UMaterialInstanceDynamic>> PreviewMIDs;

	UPROPERTY(BlueprintReadOnly, Category="PlacementVisuals")
	FVector DirectionChange;

	UPROPERTY(BlueprintReadOnly, Category="PlacementVisuals")
	FVector WorldSpacePivot;

	UPROPERTY()
	TObjectPtr<AFortDecoHelper> ParentDecoHelper;

};

