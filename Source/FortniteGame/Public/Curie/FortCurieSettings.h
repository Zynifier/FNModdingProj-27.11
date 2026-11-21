// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScalableFloat.h"
#include "FortCurieSettings.generated.h"

class UFortCurieFXSettings;
class UFortCurieManager;

UCLASS(Config=Game, PerObjectConfig)
class UFortCurieSettings : public UPrimaryDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortCurieSettings", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<UFortCurieManager> CurieManagerClass;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortCurieSettings", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortCurieFXSettings> CurieFXSettings;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieSettings")
	FScalableFloat WaterBodyInteractionMagnitude;

	UPROPERTY(EditAnywhere, Category="FortCurieSettings", meta=(ClampMin="0", Patchable, UIMin="20"))
	int32 ElementOverlapMaximumTestActorsPerFrame;

	UPROPERTY(EditAnywhere, Category="FortCurieSettings", meta=(ClampMin="0.05", Patchable, UIMin="0.05"))
	float ElementOverlapMaximumDelayBetweenChecks;

};

