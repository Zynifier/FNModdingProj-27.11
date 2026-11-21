// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Types/TargetingSystemTypes.h"
#include "FortPhysicsMagneticForceComponent.generated.h"

class AActor;
class UTargetingPreset;

USTRUCT()
struct FPhysicsMagneticForceAsyncInPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FPhysicsMagneticForceAsyncOutContinuous
{
	GENERATED_BODY()

};

USTRUCT()
struct FPhysicsMagneticForceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Magnitude;

	UPROPERTY()
	float FallOffBias;

	UPROPERTY()
	float FallOffExponent;

	UPROPERTY()
	FVector_NetQuantize Location;

	UPROPERTY()
	uint8 bShouldAffectOwner : 1;

	UPROPERTY()
	uint8 bAtLocation : 1;

	UPROPERTY()
	uint8 bLocationIsRelative : 1;

	UPROPERTY(NotReplicated)
	TObjectPtr<UTargetingPreset> TargetingPreset;

	UPROPERTY(NotReplicated)
	FTargetingRequestHandle TargetingHandle;

	UPROPERTY()
	TArray<TWeakObjectPtr<AActor>> TargetActors;

};

USTRUCT(BlueprintType)
struct FPhysicsMagneticForceHandle
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPhysicsMagneticForceComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortPhysicsMagneticForceComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void BeginMagneticForce(const float Magnitude, const float DistanceFallOffBias, const float DistanceFallOffExponent, const bool bShouldAffectOwner, const bool bAtLocation, const FVector Location, const bool bLocationIsRelative, const UTargetingPreset* TargetingPreset, UPARAM(DisplayName="Handle") FPhysicsMagneticForceHandle& OutHandle);

	UFUNCTION(BlueprintCallable)
	void EndAllMagneticForces();

	UFUNCTION(BlueprintCallable)
	void EndMagneticForce(UPARAM(ref) FPhysicsMagneticForceHandle& Handle);

private:
	UPROPERTY(Transient, Replicated)
	TArray<FPhysicsMagneticForceData> ForcesToApply;

};

