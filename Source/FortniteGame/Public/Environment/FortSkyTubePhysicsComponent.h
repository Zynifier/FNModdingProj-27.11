// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Math/MathFwd.h"
#include "Environment/FortSkyTube.h"
#include "FortSkyTubePhysicsComponent.generated.h"

class AFortSkyTube;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSkyTubeStateChanged, AFortSkyTube*, SkyTube);

USTRUCT()
struct FSkyTubeAsyncInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float MaxTubeSpeed;

	UPROPERTY()
	float MaxTubeAcceleration;

	UPROPERTY()
	FSkyTubeSplineComponentData SplineComponentData;

	UPROPERTY()
	uint8 bMagnetized : 1;

	UPROPERTY()
	uint8 bInSkyTube : 1;

};

USTRUCT()
struct FSkyTubeAsyncOutContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSkyTubeMagnetismVelocityDebugData DebugData;

};

UCLASS(Config=Game, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortSkyTubePhysicsComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortSkyTubePhysicsComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="SkyTube")
	void ComputeAccelerations(const float DeltaTime, UPrimitiveComponent* PrimComp, FVector& OutLinearAcceleration, FVector& OutAngularAccelerationRad);

	UFUNCTION(BlueprintCallable, Category="SkyTube")
	void EnterSkyTube(AFortSkyTube* InSkyTube);

	UFUNCTION(BlueprintCallable, Category="SkyTube")
	void ExitSkyTube(AFortSkyTube* InSkyTube);

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsInSkyTube() const;

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsMagnetized() const;

	UFUNCTION(BlueprintPure, Category="SkyTube")
	bool IsSkyTubeForceEnabled() const;

	UFUNCTION(BlueprintCallable, Category="SkyTube")
	void SetMagnetization(const bool bInMagnetized);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortSkyTubePhysicsComponent")
	float MaxTubeSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortSkyTubePhysicsComponent")
	float MaxTubeAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="FortSkyTubePhysicsComponent")
	bool bMagnetizeWhenNotInSkytube;

	UPROPERTY(BlueprintAssignable)
	FOnSkyTubeStateChanged OnEnteredSkyTube;

	UPROPERTY(BlueprintAssignable)
	FOnSkyTubeStateChanged OnChangedSkyTube;

	UPROPERTY(BlueprintAssignable)
	FOnSkyTubeStateChanged OnExitedSkyTube;

protected:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_SkyTube)
	TObjectPtr<AFortSkyTube> SkyTube;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortSkyTube> PrevSkyTube;

private:
	UFUNCTION()
	void OnRep_Magnetized(bool bPreviousMagnetized);

	UFUNCTION()
	void OnRep_SkyTube(AFortSkyTube* PreviousSkyTube);

	UPROPERTY()
	bool bInSkyTube;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Magnetized)
	bool bMagnetized;

	UPROPERTY()
	FSkyTubeSplineComponentData SplineComponentData;

	UPROPERTY()
	FSkyTubeMagnetismVelocityDebugData DebugData;

};

