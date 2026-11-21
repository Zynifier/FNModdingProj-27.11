// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Environment/FortWaterBodyCustomComponent.h"
#include "FortWaterBodyCubeVolumeComponent.generated.h"

class AFortWaterBodyCubeVolume;
class UMaterialInstanceDynamic;
class UStaticMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tags", "Activation", "Cooking", "Physics", "Replication", "Input", "AssetUserData", "Mesh", "Mobility", "VirtualTexture", "Trigger"))
class UFortWaterBodyCubeVolumeComponent : public UFortWaterBodyCustomComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Water Cube")
	AFortWaterBodyCubeVolume* GetFortWaterBodyCubeVolume() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	void GetVolumeBounds(FVector& Min, FVector& Max) const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeCenter() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeExtent() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeExtentFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeExtentScaled() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeExtentScaledFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeMax() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeMin() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeSize() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeSizeFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeSizeScaled() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetVolumeSizeScaledFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	void GetWaterCubeBounds(FVector& Min, FVector& Max) const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeCenter() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeExtent() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeExtentFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeExtentScaled() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeExtentScaledFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeMax() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	UStaticMeshComponent* GetWaterCubeMesh() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeMin() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeSize() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeSizeFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeSizeScaled() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterCubeSizeScaledFortCell() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterMeshCubeRescaleToUnitCube() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	FVector GetWaterRatio() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	bool IsNullExtent() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	bool IsVolumeEmptied() const;

	UFUNCTION(BlueprintPure, Category="Water Cube")
	bool IsVolumeFilled() const;

	UFUNCTION(BlueprintPure, Category="Collision")
	bool IsWaterCollisionEnabled() const;

	UFUNCTION(BlueprintPure, Category="Rendering")
	bool IsWaterVisibilityEnabled() const;

	UFUNCTION(BlueprintPure, Category="Rendering")
	bool IsWaterVisible() const;

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void SetVolumeExtent(const FVector& NewExtent);

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void SetVolumeExtentByFortCell(const FVector& NewFortCellExtent);

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void SetVolumeSize(const FVector& NewSize);

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void SetVolumeSizeByFortCell(const FVector& NewFortCellSize);

	UFUNCTION(BlueprintCallable, Category="Collision")
	void SetWaterCollisionEnabled(bool bNewIsCollisionEnabled);

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void SetWaterRatio(const FVector& NewWaterRatio);

	UFUNCTION(BlueprintCallable, Category="Rendering")
	void SetWaterVisibiltyEnabled(bool bNewIsWaterVisibilityEnabled);

	UFUNCTION(BlueprintPure, Category="Rendering")
	bool ShouldWaterBeVisible() const;

	UFUNCTION(BlueprintPure, Category="Rendering")
	bool ShouldWaterCollide() const;

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void UpdateParametersOnUnderwaterPostProcess();

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void UpdateWaterMeshCube();

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void UpdateWaterSpline();

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Water Cube")
	void OnVolumeExtentChanged(const FVector& LastVolumeExtent);

	UFUNCTION(BlueprintNativeEvent, Category="Water Cube")
	void OnWaterRatioChanged(const FVector& LastWaterRatio);

	UFUNCTION(BlueprintImplementableEvent, Category="Water Cube")
	void SetParametersOnMID(UMaterialInstanceDynamic* MID);

	UFUNCTION(BlueprintImplementableEvent, Category="Water Cube")
	void SetParametersOnUnderwaterPostProcess(UMaterialInstanceDynamic* MID);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Water Cube")
	FVector VolumeExtent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Water Cube", meta=(ClampMax="1.0", ClampMin="0.0"))
	FVector WaterRatio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Water Cube", meta=(ClampMax="1.0", ClampMin="-1.0"))
	FVector WaterOffsetRatio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rendering")
	FVector WaterMeshCubeDefaultExtent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rendering")
	FVector WaterMeshCubeDefaultOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rendering")
	FVector WaterMeshCubeDefaultScale;

	UPROPERTY(BlueprintReadOnly, Category="Rendering")
	bool bIsWaterVisibiltyEnabled;

	UPROPERTY(BlueprintReadOnly, Category="Rendering")
	bool bIsWaterCollisionEnabled;

};

