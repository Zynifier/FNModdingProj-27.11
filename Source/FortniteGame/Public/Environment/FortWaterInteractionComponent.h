// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortWaterInteractionComponent.generated.h"

class AFortWaterBodyActor;
class UFortWaterInteractionComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FWaterInteractionOnEnterWater, AFortWaterBodyActor*, WaterBody, UFortWaterInteractionComponent*, WaterInteractionComponent, bool, bIsFirstBody);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FWaterInteractionOnExitWater, AFortWaterBodyActor*, WaterBody, UFortWaterInteractionComponent*, WaterInteractionComponent, bool, bIsLastBody);

UCLASS(Config=Game, BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortWaterInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Water")
	AFortWaterBodyActor* GetCurrentWaterBody() const;

	UFUNCTION(BlueprintPure, Category="FX")
	void GetLastWaterSurfaceInfo(FVector& WaterPlaneLocation, FVector& WaterPlaneNormal, FVector& WaterSurfacePosition, float& WaterDepth, int32& WaterBodyIdx, FVector& WaterVelocity);

	UFUNCTION(BlueprintPure, Category="Water", meta=(ScriptName="IsComponentEnabled"))
	bool IsEnabled() const;

	UFUNCTION(BlueprintPure, Category="Water")
	bool IsInWater() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Water")
	void OnEnteredWaterBody(AFortWaterBodyActor* WaterBody, bool bIsFirstBody);

	UFUNCTION(BlueprintImplementableEvent, Category="Water")
	void OnExitedWaterBody(AFortWaterBodyActor* WaterBody, bool bIsLastBody);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water")
	uint8 bIsEnabled : 1;

	UPROPERTY(EditAnywhere, Category="Water")
	uint8 bTickComponentForces : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water")
	uint8 bIncludeWaves : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water")
	uint8 bAllowCachedDataInLargeBodies : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float WaterVelocityForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float WaterVelocityShallowDepth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float WaterVelocityShallowMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float WaterVelocityShoreBias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float BuoyancyFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float UpBuoyancyDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float UpBuoyancyDrag2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float DownBuoyancyDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float DownBuoyancyDrag2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float HorizontalDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Water", meta=(ClampMin="0", UIMin="0"))
	float HorizontalDrag2;

	UPROPERTY(BlueprintAssignable, Category="Water")
	FWaterInteractionOnEnterWater OnEnterWaterEvent;

	UPROPERTY(BlueprintAssignable, Category="Water")
	FWaterInteractionOnExitWater OnExitWaterEvent;

};

