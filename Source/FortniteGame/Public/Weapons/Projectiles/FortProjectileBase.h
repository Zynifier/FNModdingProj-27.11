// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayCueInterface.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Core/FortManagedTickSubsystem.h"
#include "FortCombatTypes.h"
#include "FortDamageableActorInterface.h"
#include "FortInteractInterface.h"
#include "FortProjectileMovementInterface.h"
#include "Weapons/FortGameplayEffectDeliveryActor.h"
#include "FortProjectileBase.generated.h"

class AActor;
class AFortPlayerController;
class AFortSkyTube;
class AFortWeapon;
class UBulletWhipTrackerComponentBase;
class UCapsuleComponent;
class UFortProjectileMovementComponent;
class UFortWaterInteractionComponent;
class USceneComponent;

UENUM(BlueprintType)
enum class EProjectileWaterHitBehavior : uint8
{
	Overlap = 0,
	StopIfStopSimulatingOnHit = 1,
	StopOnOverlap = 2,
};

USTRUCT(BlueprintType)
struct FFortProjectileCues
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag Spawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag InAirLooping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag HitPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag HitWorld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag HitWater;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	bool bOrientHitGCsToProjectileVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects", meta=(ClampMax="90.0", ClampMin="0.0", EditCondition="bOrientHitGCsToProjectileVelocity", UIMax="90.0", UIMin="0.0"))
	float MaxSurfaceNormalDeviationAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag Bounce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag Explosion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag UnderwaterExplosion;

};

USTRUCT(BlueprintType)
struct FFortProjectileTrajectoryData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	float GravityZ;

	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	float CapsuleRadius;

	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	float CapsuleHalfHeight;

	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	bool bShouldBounce;

	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	float Bounciness;

	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	float Friction;

	UPROPERTY(BlueprintReadOnly, Category="FortProjectileTrajectoryData")
	TEnumAsByte<ECollisionChannel> CollisionObjectType;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Game|Damage"))
class AFortProjectileBase : public AFortGameplayEffectDeliveryActor, public IFortDamageableActorInterface, public IGameplayTagAssetInterface, public IFortInteractInterface, public IFortProjectileMovementInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="GameplayCues")
	FORTNITEGAME_API void AddLoopingGameplayCue(const FGameplayCueTag& GameplayCueTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Tags")
	FORTNITEGAME_API void AddTagToDefaultTags(FGameplayTag TagToAddToProjectileDefaultTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	FORTNITEGAME_API void EnterSkyTube(AFortSkyTube* SkyTube, bool& bIsFirstTube);

	UFUNCTION(BlueprintCallable, Category="GameplayCues")
	FORTNITEGAME_API void ExecuteGameplayCue(const FGameplayCueTag& GameplayCueTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	FORTNITEGAME_API void ExitSkyTube(AFortSkyTube* SkyTube, bool& bIsLastTube);

	UFUNCTION(BlueprintPure, Category="Movement")
	FORTNITEGAME_API float GetDefaultGravityScale() const;

	UFUNCTION(BlueprintPure, Category="Movement")
	FORTNITEGAME_API float GetDefaultSpeed(float InChargePercent = 0.000000f) const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FORTNITEGAME_API bool GetDummyProjectile_DEPRECATED();

	UFUNCTION(BlueprintPure, Category="Projectile")
	FORTNITEGAME_API float GetGravityScale() const;

	UFUNCTION(BlueprintNativeEvent, Category="Projectile")
	FORTNITEGAME_API float GetMaxLifespan();

	UFUNCTION(BlueprintCallable, Category="PlayerInfo")
	FORTNITEGAME_API AFortPlayerController* GetOwnerPlayerController();

	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API FVector GetOwnerVelocity() const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API AFortWeapon* GetOwnerWeapon();

	UFUNCTION(BlueprintPure, Category="Projectile")
	FORTNITEGAME_API AFortSkyTube* GetSkyTube() const;

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnBounce(const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnHitByMelee(const FHitResult& Hit);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_GravityScale();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_ReplicatedMaxSpeed();

	UFUNCTION()
	FORTNITEGAME_API void OnRep_SimulationStoppingHit();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnResumeSimulation();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnShot(const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnShotByProjectile(const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnStop(const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void OnStoppedOnServer();

	UFUNCTION(BlueprintCallable, Category="GameplayCues")
	FORTNITEGAME_API void RemoveLoopingGameplayCue(const FGameplayCueTag& GameplayCueTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	FORTNITEGAME_API void ResumeSimulation();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Projectile")
	FORTNITEGAME_API void SetGravityScale(float InitialGravityScale);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FCurveTableRowHandle VerticleFireOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FCurveTableRowHandle InitialSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FCurveTableRowHandle ChargeUpInitialSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	FCurveTableRowHandle MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Movement")
	FCurveTableRowHandle InitialGravityScaleOverride;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedMaxSpeed)
	float ReplicatedMaxSpeed;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GravityScale)
	float GravityScale;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortProjectileBase")
	TWeakObjectPtr<AActor> OriginalTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortProjectileBase")
	float ChargePercent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MomentumTransfer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bAddOwnerVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	bool bSpawnPointCanBeUsedByOtherPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	float PlayerSpawnOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	bool bRegisterInPerceptionSystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Interaction")
	bool bCanBePickedUpWhenStopped;

	UPROPERTY(BlueprintGetter=GetDummyProjectile_DEPRECATED, Category="Projectile")
	bool bDummyProjectile_DEPRECATED;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bStopSimulatingOnHit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Projectile")
	EProjectileWaterHitBehavior TouchWaterBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Projectile")
	bool bDisableCollisionOnStop;

	UPROPERTY(Transient)
	bool bStoppedSimulatingDueToHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bReplicateStopSimulationLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bReplicateStopSimulationLocationOptimized;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bClientInterpMovement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bClientInterpRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	bool bUseClientsidePrediction;

	UPROPERTY(Transient)
	bool bIsPredictedProjectile;

	UPROPERTY(Transient)
	bool bHasLocalPredictedCounterpart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile", meta=(EditCondition="bClientInterpMovement"))
	bool bAutoSelectAttachedForInterp;

	UPROPERTY(ReplicatedUsing=OnRep_SimulationStoppingHit)
	FHitResult SimulationStoppingHit;

	UPROPERTY(Transient)
	bool bFiredWhileTargeting;

	FORTNITEGAME_API virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UFUNCTION()
	FORTNITEGAME_API virtual void OnBounceCallback(const FHitResult& Hit, const FVector& ImpactVelocity);

	UFUNCTION()
	FORTNITEGAME_API void OnRep_CurrentSkyTube();

	UFUNCTION()
	FORTNITEGAME_API virtual void OnStopCallback(const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Collision", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Movement", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Water", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortWaterInteractionComponent> WaterInteractionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Visual", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UBulletWhipTrackerComponentBase> BulletWhipTrackerComponent;

	UPROPERTY(Replicated)
	uint16 SyncId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EFortBaseWeaponDamage::Type> WeaponResponseType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Tags")
	FGameplayTagContainer DefaultTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FFortProjectileCues ProjectileGameplayCues;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> CachedPassByPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SkyTube")
	float SkyTubeForceMultiplier;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentSkyTube)
	TObjectPtr<AFortSkyTube> CurrentSkyTube;

	UPROPERTY(Transient)
	FHitResult CachedImpactResult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Sound")
	TSubclassOf<UBulletWhipTrackerComponentBase> BulletWhipTrackerComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	bool bResetOverlapRestrictionsOnBounce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float MaxLifespanOnStop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectile")
	float LifespanOnHitDoNotExplode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile")
	uint8 bAutoKillAtDistanceFromInitialLocation : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Projectile")
	float AutoKillDistanceSquaredOverride;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	TArray<FName> ProjectileThrownStatCategoryNames;

private:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_ResumeSimulationCount();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ResumeSimulationCount)
	int32 ResumeSimulationCount;

};

UCLASS(MinimalAPI)
class UFortProjectileTickSubsystem : public UFortManagedActorTickSubsystem
{
	GENERATED_BODY()

};

