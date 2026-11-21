// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/DataTable.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Types/TargetingSystemTypes.h"
#include "Physics/FortPhysicsObjectPreset.h"
#include "Physics/FortPhysicsSimSize.h"
#include "TornadoForcesComponent.generated.h"

class AActor;
class AFortAthenaVehicle;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class UCurveFloat;
class UGameplayEffect;
class UTargetingPreset;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAffectedActorEvent, AActor*, AffectedActor);

USTRUCT()
struct FTornadoActorInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FTornadoSimulationData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> Actor;

	UPROPERTY()
	EFortPhysicsObjectType ObjectType;

	UPROPERTY()
	float TangentVelocity;

	UPROPERTY()
	float TangentAccel;

	UPROPERTY()
	float HeightVelocity;

	UPROPERTY()
	float HeightAccel;

	UPROPERTY()
	FVector Torque;

};

USTRUCT()
struct FTornadoClientSimulationArray : public FFastArraySerializer
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FTornadoSimulationData> ActorsToSimulateArray;

};

USTRUCT(BlueprintType)
struct FTornadoObjectForceModifiers
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="TornadoObjectForceModifiers")
	float TangentVelocityMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="TornadoObjectForceModifiers")
	float HeightVelocityMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="TornadoObjectForceModifiers")
	float DragMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="TornadoObjectForceModifiers")
	float TorqueMultiplier;

};

USTRUCT()
struct FTornadoConfigEntry : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="TornadoConfigEntry")
	float EyeBufferDistance;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	TObjectPtr<UCurveFloat> TargetOrbitRadiusCurve;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TargetOrbitRadius;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float OrbitStrength;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TargetTangentVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TangentVelocityVariance;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TangentAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TangentAccelerationVariance;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TangentAngleOffset;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TargetHeightVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float HeightVelocityVariance;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float HeightAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float HeightAccelerationVariance;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TorqueStrength;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TorqueVariance;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float TimeToForceEject;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float HeightToForceEject;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float DepthToForceEject;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float DistanceToForceEject;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float EjectionBoost;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float MaxDragVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float DragCoefficient1;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	float DragCoefficient2;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	TMap<EFortPhysicsSimSize, FTornadoObjectForceModifiers> SizeForceModifiers;

	UPROPERTY(EditDefaultsOnly, Category="Forces")
	TMap<EFortPhysicsObjectType, FTornadoObjectForceModifiers> ObjectTypeForceModifiers;

	UPROPERTY(EditDefaultsOnly, Category="Player Vortex")
	float PlayerGravityFloorOffset;

	UPROPERTY(EditDefaultsOnly, Category="Player Vortex")
	float PlayerGravityFloorWidth;

	UPROPERTY(EditDefaultsOnly, Category="Player Vortex")
	float PlayerGravityFloorGravityScalar;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	float PeriodicDamageToPawns;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	float PeriodicDamageToProps;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	float BurstDamageToStaticActors;

	UPROPERTY(EditDefaultsOnly, Category="Damage")
	float ChancePerSecondToApplyBurstDamage;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bAllowPickupPlayers;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bAllowPickupPawns;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bAllowPickupVehicles;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bAllowPickupProjectiles;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bAffectStaticObjects;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	EFortPhysicsSimSize MaxAllowedPhysicsObjectSize;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	EFortPhysicsSimSize MinAllowedPhysicsObjectSize;

};

USTRUCT()
struct FTornadoTelemetryStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<EFortPhysicsObjectType, int32> NumActorsEnteredByType;

	UPROPERTY()
	TSet<FUniqueNetIdRepl> EnteredPlayerAccountIds;

	UPROPERTY()
	int32 NumPreBuiltStructuresDestroyed;

	UPROPERTY()
	int32 NumPlayerBuiltStructuresDestroyed;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "Collision", "ComponentReplication", "Sockets", "Tags", "AssetUserData", "Cooking", "ComponentTick", "Trigger", "PhysicsVolume"), ClassGroup=("Tempest"), meta=(BlueprintSpawnableComponent))
class UTempestTornadoForcesComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UTempestTornadoForcesComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure)
	bool IsActorInTornado(AActor* Actor) const;

	UPROPERTY(BlueprintAssignable, Category="Affected Actors")
	FAffectedActorEvent OnActorAddedToTornadoForces;

	UPROPERTY(BlueprintAssignable, Category="Affected Actors")
	FAffectedActorEvent OnActorRemovedFromTornadoForces;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Config", meta=(RowType="/Script/SuperstormRuntime.TornadoConfigEntry"))
	FDataTableRowHandle ConfigHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Forces Data|Config")
	TArray<FGameplayTag> PhysicsPresetTagsAngularDampingToOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Forces Data|Config")
	FScalableFloat AngularDampingOverride;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Config")
	TSubclassOf<UGameplayEffect> PawnInGE;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Targeting")
	TMap<EFortPhysicsObjectType, FScalableFloat> ObjectTypeToMaxCapCount;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Targeting")
	FGameplayTagContainer TagsToIgnore;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Targeting")
	TSubclassOf<UGameplayEffect> RecentlyRemovedGE;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Targeting")
	TObjectPtr<UTargetingPreset> TargetingPreset;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Damaging", meta=(Categories="SetByCaller"))
	FGameplayTag DamageSetByCallerTag;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Damaging")
	TSubclassOf<UGameplayEffect> PeriodicDamageGE;

	UPROPERTY(EditDefaultsOnly, Category="Forces Data|Damaging")
	TSubclassOf<UGameplayEffect> BurstDamageGE;

	UPROPERTY(EditAnywhere, Category="Tornado | Gameplay Cues", meta=(Categories="GameplayCue"))
	FGameplayTag TornadoActiveCue;

	UPROPERTY(EditAnywhere, Category="Tornado | Gameplay Cues", meta=(Categories="GameplayCue"))
	FGameplayTag PlayerNearCue;

	UPROPERTY(EditAnywhere, Category="Tornado | Gameplay Cues", meta=(Categories="GameplayCue"))
	FGameplayTag PawnInCue;

	UPROPERTY(EditAnywhere, Category="Tornado | Gameplay Cues", meta=(Categories="GameplayCue"))
	FScalableFloat PlayerNearRange;

	UPROPERTY(EditAnywhere, Category="Player")
	FGameplayTagContainer BlockAbilitiesWithTag;

private:
	UFUNCTION()
	void OnVehicleInTornadoPlayerExit(const AFortPlayerControllerAthena* PlayerController, AFortAthenaVehicle* Vehicle);

	UPROPERTY(Transient, Replicated)
	FTornadoClientSimulationArray ActorsToClientSimulate;

	UPROPERTY(Transient)
	FTargetingRequestHandle AsyncTargetingHandle;

	UPROPERTY(Transient)
	TSet<TObjectPtr<AFortPlayerPawn>> PreviouslyNearPlayers;

};

