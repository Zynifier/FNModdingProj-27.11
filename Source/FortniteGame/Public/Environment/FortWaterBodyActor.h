// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuoyancyEventInterface.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "WaterBodyActor.h"
#include "WaterBodyTypes.h"
#include "AI/Navigation/AthenaNavRelevantActorInterface.h"
#include "Curie/FortCurieInterface.h"
#include "Environment/WaterSurfaceInfo.h"
#include "FortWaterBodyActor.generated.h"

class AFortAthenaVehicle;
class AFortPlayerPawn;
class AFortWaterBodyActor;
class UDEPRECATED_WaterBodyGenerator;
class UMaterialInterface;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPawnEnterFortWaterBody, AFortWaterBodyActor*, FortWaterBody, AFortPlayerPawn*, Player, bool, bIsFirstBody);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnPawnExitFortWaterBody, AFortWaterBodyActor*, FortWaterBody, AFortPlayerPawn*, Player, bool, bIsLastBody);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleEnterFortWaterBody, AFortWaterBodyActor*, FortWaterBody, AFortAthenaVehicle*, Vehicle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVehicleExitFortWaterBody, AFortWaterBodyActor*, FortWaterBody, AFortAthenaVehicle*, Vehicle);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tags", "Activation", "Cooking", "AssetUserData", "Input"))
class AFortWaterBodyActor : public AWaterBody, public IBuoyancyEventInterface, public IFortCurieInterface, public IAthenaNavRelevantActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="WaterBody", meta=(DeprecatedFunction))
	void GetWaterSurfaceInfo(FVector QueryLocation, FVector& WaterPlaneLocation, FVector& WaterPlaneNormal, FVector& WaterSurfacePosition, float& WaterDepth, int32& WaterBodyIdx, FVector& WaterVelocity, bool bIncludeDepth = true, bool bIncludeWaves = false, bool bSimpleWaves = false) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="WaterBody")
	void GetWaterSurfaceInfoStruct(FWaterSurfaceInfo& OutWaterSurfaceInfo, const FVector& QueryLocation, const bool bIncludeDepth = true, const bool bIncludeWaves = false, bool bSimpleWaves = false) const;

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnPlayerEnteredWaterBody(AFortPlayerPawn* Player, bool bIsFirstBody);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnPlayerExitedWaterBody(AFortPlayerPawn* Player, bool bIsLastBody);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnReceivedBulletImpact(const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnVehicleEnteredWaterBody(AFortAthenaVehicle* Vehicle);

	UFUNCTION(BlueprintImplementableEvent, Category="WaterBody")
	void OnVehicleExitedWaterBody(AFortAthenaVehicle* Vehicle);

	UFUNCTION(BlueprintCallable, Category="WaterBody")
	void SetSwampLocationAndRadius(const FVector& InPosition, float InRadius);

	UFUNCTION(BlueprintCallable, Category="Water")
	void SetWaterBodyType(EWaterBodyType InType);

	UPROPERTY(BlueprintAssignable, Category="Water Body", meta=(DisplayName="OnPawnEnterFortWaterBody"))
	FOnPawnEnterFortWaterBody OnPawnEnterFortWaterBodyDelegate;

	UPROPERTY(BlueprintAssignable, Category="Water Body", meta=(DisplayName="OnPawnExitFortWaterBody"))
	FOnPawnExitFortWaterBody OnPawnExitFortWaterBodyDelegate;

	UPROPERTY(BlueprintAssignable, Category="Water Body", meta=(DisplayName="OnVehicleEnterFortWaterBody"))
	FOnVehicleEnterFortWaterBody OnVehicleEnterFortWaterBodyDelegate;

	UPROPERTY(BlueprintAssignable, Category="Water Body", meta=(DisplayName="OnVehicleExitFortWaterBody"))
	FOnVehicleExitFortWaterBody OnVehicleExitFortWaterBodyDelegate;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Water Body")
	TArray<TObjectPtr<AFortAthenaVehicle>> OverlappingVehicles;

	UPROPERTY(BlueprintReadOnly, Category="Water Body")
	TArray<TObjectPtr<AFortPlayerPawn>> OverlappingPlayers;

	UPROPERTY(EditAnywhere, Category="Water")
	FScalableFloat WaterOverrideMaxCharacterForce;

	UPROPERTY(EditAnywhere, Category="Water")
	int32 WaterPriority;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UDEPRECATED_WaterBodyGenerator> Generator_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UMaterialInterface> RiverToLakeTransitionMat_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UMaterialInterface> RiverToOceanTransitionMat_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FVector OceanCollisionExtents_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bIsSwamp_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FScalableFloat WaterVelocityRemapInputRange_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FScalableFloat WaterVelocityRemapOutputRange_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FScalableFloat WaterVelocityPerpendicularBias_DEPRECATED;
#endif

};

