// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Environment/FortWaterBodyActor.h"
#include "FortWaterBodyCubeVolume.generated.h"

class UFortWaterBodyCubeVolumeComponent;
class UMaterialInstanceDynamic;
class UStaticMeshComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tags", "Activation", "Cooking", "AssetUserData", "Input"))
class AFortWaterBodyCubeVolume : public AFortWaterBodyActor
{
	GENERATED_BODY()

public:
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
	FVector GetWaterRatio() const;

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

	UFUNCTION(BlueprintImplementableEvent, Category="Water Cube")
	void SetParametersOnMID(UMaterialInstanceDynamic* MID);

	UFUNCTION(BlueprintImplementableEvent, Category="Water Cube")
	void SetParametersOnUnderwaterPostProcess(UMaterialInstanceDynamic* UnderWaterMID);

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

	UFUNCTION(BlueprintCallable, Category="Water Cube")
	void UpdateParametersOnUnderwaterPostProcess();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Water Body", meta=(EditInline="true"))
	TObjectPtr<UFortWaterBodyCubeVolumeComponent> FortWaterBodyCubeVolumeComponent;

};

