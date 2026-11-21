// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortVehiclePhysicsCollisionDamageComponent.generated.h"

class AActor;
class ABuildingActor;
class AFortAthenaVehicle;
class UFortPhysicsVehicleConfigs;
class UGameplayEffect;
class UPrimitiveComponent;

USTRUCT()
struct FHitBuildingDamageOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HitBuildingDamageOverride")
	FGameplayTagQuery VehicleDriverTagQuery;

	UPROPERTY(EditAnywhere, Category="HitBuildingDamageOverride")
	float DestructionAngle;

	UPROPERTY(EditAnywhere, Category="HitBuildingDamageOverride")
	float MinDestructionSpeedKmh;

	UPROPERTY(EditAnywhere, Category="HitBuildingDamageOverride")
	TSubclassOf<UGameplayEffect> DamageGE;

};

USTRUCT()
struct FPotentiallyDestroyedBuilding
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<ABuildingActor> BuildingActor;

	UPROPERTY()
	float TimeSinceCollision;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent, DisplayName="Physics Collision Damage Component"))
class UFortVehiclePhysicsCollisionDamageComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	bool bAllowHitPawns;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	bool bAllowHitBuildingPieces;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	bool bDoMultiSweep;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	bool bOnlyAffectBuildingsIfKillingDamage;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	float ClientIgnoreBuildingActorsTime;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	bool bUpdateTimeoutIgnoreBuildingActors;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	bool bAlignLookAheadDirectionWithVehicleYAxis;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings")
	bool bAlignLookAheadDirectionWithVehicleZAxis;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings|Trace")
	FName BoxTraceSingleName;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings|Trace")
	FName DestructionTraceSocket;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings|Trace")
	FName DestructionTraceSocketRear;

	UPROPERTY(EditAnywhere, Category="Deprecated|Imminent Collision|Settings|Trace")
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(EditAnywhere, Category="Physics Collision|Damage")
	float MaxDestructionAngle;

	UPROPERTY(EditAnywhere, Category="Physics Collision|Damage")
	float MinDestructionSpeedKmh;

	UPROPERTY(EditAnywhere, Category="Physics Collision|Damage")
	TSubclassOf<UGameplayEffect> DamageGE;

	UPROPERTY(EditAnywhere, Category="Physics Collision|Damage")
	TArray<FHitBuildingDamageOverride> OverriddenDamageData;

private:
	UFUNCTION()
	void HandleOnSKComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(Transient)
	TArray<FPotentiallyDestroyedBuilding> PotentiallyDestroyedBuildings;

	UPROPERTY(Transient)
	float VehicleApproxHalfLength;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaVehicle> CachedOwnerVehicle;

	UPROPERTY(Transient)
	TObjectPtr<UFortPhysicsVehicleConfigs> CachedVehicleConfigs;

	UPROPERTY(Transient)
	float LastOnSKComponentHitTime;

};

