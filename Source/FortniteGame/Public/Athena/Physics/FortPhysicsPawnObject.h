// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/HitResult.h"
#include "GameplayCueInterface.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "Athena/FortAthenaVehicle.h"
#include "Athena/Physics/TimeStampedPhysicsPawnState.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortCombatTypes.h"
#include "FortDamageableActorInterface.h"
#include "FortVehicleInterface.h"
#include "Pawns/FortPhysicsPawn.h"
#include "FortPhysicsPawnObject.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortPawn;
class AFortPhysicsPawnObject;
class APawn;
class APlayerController;
class UBuildingEditModeMetadata;
class UFortAbilitySet;
class UFortAbilitySystemComponent;
class UFortAthenaImpulseResponseSet;
class UFortDamageSet;
class UFortHealthBarIndicator;
class UFortHealthSet;
class UGameplayEffect;
class UObject;
class UPrimitiveComponent;
class UStaticMeshComponent;
class UWeaponHitNotifyAudioBank;

USTRUCT()
struct FHitData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float PingOfHitter;

	UPROPERTY()
	TObjectPtr<APawn> HittingPawn;

	UPROPERTY()
	FVector HitNormal;

	UPROPERTY()
	FTimeStampedPhysicsPawnState ObjectState;

};

USTRUCT(BlueprintType)
struct FPhysicsPawnObjectInitialParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	FVector InitialVelocity;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	float OverrideMassInKG;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	float OverrideAngularDampening;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	float OverrideLinearDampening;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	float PlayerForceMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	float PawnKnockbackMultiplier;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	uint8 bEnableGravity : 1;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	uint8 bEnableGravityOnHit : 1;

	UPROPERTY(BlueprintReadWrite, Category="PhysicsPawnObjectInitialParameters")
	uint8 bShouldKillPawnOnHit : 1;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation"))
class AFortPhysicsPawnObject : public AFortPhysicsPawn, public IFortDamageableActorInterface, public IFortAbilitySystemInterface, public IGameplayCueInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="PhysicsObject")
	void ApplyImpulse(AActor* ImpulseInstigator, const FVector& ImpulseToApply);

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual bool CanCorrectOrientation(AFortPawn* FP) const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual bool CanTeleport() const;

	UFUNCTION(BlueprintCallable, Category="PhysicsObject")
	void DestroyPhysicsObject();

	UFUNCTION(BlueprintCallable)
	virtual void GameplayCue_Damage(EGameplayCueEvent::Type EventType, FGameplayCueParameters Parameters);

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual FString GetDisplayName() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual float GetForwardSpeedKmh() const;

	UFUNCTION(BlueprintPure)
	float GetHealth() const;

	UFUNCTION(BlueprintPure)
	float GetMaxHealth() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	FVector GetPhysicsObjectVelocity() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual float GetPreviousForwardSpeedKmh() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	FVector GetPreviousLinearAcceleration() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	FVector GetPreviousLinearVelocity() const;

	UFUNCTION(BlueprintPure)
	bool HasPermissionToAlterBuildings() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	bool IsAsleep() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual bool IsCorrectingOrientation() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual bool IsInAir() const;

	UFUNCTION(BlueprintPure)
	bool IsInWater() const;

	UFUNCTION(BlueprintPure, Category="PhysicsObject")
	virtual bool IsScrapingSidesOrTop() const;

	UFUNCTION()
	virtual float ModifyIncomingDamage(float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnCollisionHitClient(const FVector& HitLocation, const FVector& VelocityOfHitter, const FVector& HitNormal, AActor* HitActor, EPhysicalSurface HitSurfaceType);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnCollisionHitDamageEffects(float DamageTaken);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnCollisionHitServer(const FVector& HitLocation, const FVector& VelocityOfHitter, const FVector& HitNormal, AActor* HitActor, EPhysicalSurface HitSurfaceType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDamaged(float Damage, const FGameplayTagContainer& DamageTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDamagePlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void OnDeathPlayEffects(float Damage, const FGameplayTagContainer& DamageTags, FVector Momentum, const FHitResult& HitInfo, AFortPawn* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnEnteredWaterVolume(const FVector& WaterSurfacePoint);

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnExitedWaterVolume(const FVector& WaterSurfacePoint);

	UFUNCTION(BlueprintImplementableEvent)
	void OnImpactDamageApplied(const float Damage, const FVector ImpactNormal);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartTick();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStopTick();

	UFUNCTION(BlueprintImplementableEvent)
	void PawnHitByPhysicsObject(AFortPawn* Pawn, const FVector& ImpactPoint, const FVector& ImpactNormal, const FVector LaunchVector);

	UFUNCTION(BlueprintCallable)
	void SetHealthPercent(float Percent);

	UFUNCTION(BlueprintCallable)
	void SetImpulseResponseMultiplier(const float Multiplier);

	UFUNCTION(BlueprintCallable)
	void SetImpulseResponseZBias(const float ZBias);

	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="ActorClass", WorldContext="WorldContextObject"))
	static AFortPhysicsPawnObject* SpawnPhysicsPawnObject(const UObject* WorldContextObject, TSubclassOf<AFortPhysicsPawnObject> ActorClass, const FTransform& Transform, const FPhysicsPawnObjectInitialParameters& InitialParameters);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable)
	void UpdateClientWithPhysicsObjectTestInput(FVector LinearVelocity, FVector AngularVelocity);

	UFUNCTION(BlueprintCallable, Category="PhysicsObject")
	virtual void WakeUp();

	UFUNCTION()
	void WakeUpOnGroundDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EPhysicalSurface> PrimarySurfaceType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageSettings")
	TEnumAsByte<EFortBaseWeaponDamage::Type> WeaponResponseType;

	UPROPERTY(EditDefaultsOnly, Category="FortPhysicsPawnObject")
	bool bShowDamageNumbers;

	UPROPERTY(EditDefaultsOnly, Category="FortPhysicsPawnObject")
	bool bPlayDamageAudio;

	UPROPERTY(EditDefaultsOnly, Category="FortPhysicsPawnObject")
	FGameplayTagContainer IgnoreImpulseTags;

	UPROPERTY(EditDefaultsOnly, Category="PhysicsObject", meta=(Categories="PhysicsObject"))
	FGameplayTagContainer PhysicsObjectTags;

	UPROPERTY(EditAnywhere, BlueprintSetter=SetImpulseResponseMultiplier, Config, Category="Damage")
	float ImpulseResponseMultiplier;

	UPROPERTY(EditAnywhere, BlueprintSetter=SetImpulseResponseZBias, Config, Category="Damage")
	float ImpulseResponseZBias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PhysicsObject")
	FVector TestInitialLinearVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PhysicsObject")
	FVector TestInitialAngularVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhysicsObject")
	FHitResult LookAheadHit;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PhysicsObject")
	float CachedSpeed;

	UPROPERTY(EditDefaultsOnly, Category="HitNotifies")
	TObjectPtr<UWeaponHitNotifyAudioBank> DefaultHitNotifyAudioBank;

	UPROPERTY(BlueprintAssignable, Category="Health")
	FVehicleHealthChanged OnHealthChanged;

	UPROPERTY(EditAnywhere, Transient, Category="FortPhysicsPawnObject")
	float LifespanAfterDeath;

	UPROPERTY(Transient)
	bool bPlayedDying;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Damage")
	float LastDamagedTime;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyImpulseFromPawnHit(const FVector& VelocityOfHitter, const FVector& NormalTowardObject, APawn* HittingPawn);

	UFUNCTION(BlueprintCallable)
	void ApplyPredictedImpulseFromPawnHitClient(const FVector& VelocityOfHitter, const FVector& NormalTowardObject, APawn* HittingPawn);

	UFUNCTION(Client, Reliable)
	void DebugDrawImpactBucket(FVector Location, FVector ImpactVector, FColor Color);

	UFUNCTION()
	void OnPxComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName);

	UFUNCTION()
	void OnRep_SurfaceTypePhysicsObjectOn(EPhysicalSurface PreviousSurfaceOn);

	UFUNCTION(BlueprintImplementableEvent, Category="SurfaceType")
	void OnSurfaceTypePhysicsObjectIsOnChanged(EPhysicalSurface SurfaceTypePhysicsObjectIsOn);

	UFUNCTION(BlueprintCallable, Category="PhysicsObject")
	virtual void SetDyingPhysics();

	UFUNCTION(BlueprintCallable)
	virtual void SetPropDestructionParams(TArray<TSubclassOf<ABuildingActor>> InBuildingPropClassesPhysicsObjectCanDestroy, TArray<UBuildingEditModeMetadata*> InWallsPhysicsObjectCanDestroy);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="StaticMeshActor", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Mesh,Rendering,Physics,Components|StaticMesh"))
	TObjectPtr<UStaticMeshComponent> PhysicsMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="StaticMeshActor", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Mesh,Rendering,Components|StaticMesh"))
	TObjectPtr<UStaticMeshComponent> VisibleMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhysicsPawnObject")
	TSubclassOf<UGameplayEffect> PlayerCollisionGameplayEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameplayTags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UBuildingEditModeMetadata>> WallsPhysicsObjectCanDestroy;

	UPROPERTY(Transient)
	TArray<TSubclassOf<ABuildingActor>> BuildingPropClassesPhysicsObjectCanDestroy;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_SurfaceTypePhysicsObjectOn, Category="Surface Type")
	TEnumAsByte<EPhysicalSurface> SurfaceTypePhysicsObjectOn;

	UPROPERTY(BlueprintAssignable, Category="SurfaceType")
	FOnSurfaceTypeVehicleIsOnChanged OnSurfaceTypePhysicsObjectIsOnChangedDelegate;

	UPROPERTY(EditDefaultsOnly, Category="AbilitySet")
	TObjectPtr<UFortAbilitySet> StartupAbilitySet;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_InitialParameters, Category="FortPhysicsPawnObject")
	FPhysicsPawnObjectInitialParameters InitialParameters;

	UPROPERTY(EditAnywhere, Category="FortPhysicsPawnObject")
	TArray<TSubclassOf<AActor>> ActorsObjectDiesWhenHitting;

private:
	UFUNCTION(NetMulticast, Reliable)
	void DrawServerAndClientBallPosition(const FVector ServerPosition);

	UFUNCTION()
	void OnRep_AbilitySystemComponent();

	UFUNCTION()
	void OnRep_CorrectTargetOrientation();

	UFUNCTION()
	void OnRep_CurrentServerPhysicsState();

	UFUNCTION()
	void OnRep_HealthSet();

	UFUNCTION()
	void OnRep_InitialParameters();

	UFUNCTION()
	void OnRep_LastServerConfirmedHit();

	UFUNCTION()
	void OnRep_PendingDeath();

	UFUNCTION()
	void SendClientStateToServer_Helper();

	UFUNCTION(NetMulticast, Reliable)
	void ServerBroadcastHit(APawn* ImpulseInstigator, const FVector ImpactPoint, const FVector ImpulseValue);

	UFUNCTION(NetMulticast, Reliable)
	void ServerBroadcastHitFromClient(APlayerController* HittingController, APawn* HittingPawn, const FVector& VelocityOfHitter, const FVector& HitNormal, const FTimeStampedPhysicsPawnState& ClientBallState);

	UFUNCTION()
	void TurnOffClientPrediction();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CorrectTargetOrientation)
	FVehicleTargetOrientation CorrectTargetOrientation;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AbilitySystemComponent, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HealthSet, Export, meta=(EditInline="true"))
	TObjectPtr<UFortHealthSet> HealthSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaImpulseResponseSet> ImpulseResponseSet;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortDamageSet> DamageSet;

	UPROPERTY(Transient)
	TObjectPtr<UFortHealthBarIndicator> HealthBarIndicator;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PendingDeath)
	bool bPendingDeath;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentServerPhysicsState)
	FTimeStampedPhysicsPawnState CurrentServerPhysicsState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LastServerConfirmedHit)
	FHitData LastServerConfirmedHit;

};

