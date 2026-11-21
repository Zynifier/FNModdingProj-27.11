// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BuoyancyTypes.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Physics/FortPhysicsObjectManager.h"
#include "FortPhysicsObjectComponent.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerPawn;
class UBuoyancyComponent;
class UFortLinkToActorComponent;
class UFortPhysicsObjectBuoyancyData;
class UFortPhysicsObjectCollisionEffectsData;
class UFortPhysicsObjectComponent;
class UFortPhysicsObjectImpactDamageData;
class UFortPhysicsObjectNavigationData;
class UFortPhysicsObjectPreset;
class UMaterialInterface;
class UPhysicalMaterial;
class UPrimitiveComponent;
enum class EFortPhysicsObjectActivationType : uint8;
enum class EFortPhysicsObjectMovementState : uint8;

UENUM()
enum class EFortPhysicsObjectAwakeState : uint8
{
	Invalid = 0,
	Awake = 1,
	Asleep = 2,
};

UENUM()
enum class EFortPhysicsObjectImpactDamageType : uint8
{
	Environment = 0,
	Pawn = 1,
	Vehicle = 2,
	Wildlife = 3,
};

UENUM()
enum class EFortPhysicsObjectMovementState : uint8
{
	None = 0,
	Flying = 1,
	Rolling = 2,
	Sliding = 3,
	Floating = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnComponentHitSignature, UPrimitiveComponent*, HitComponent, AActor*, OtherActor, UPrimitiveComponent*, OtherComp, FVector, NormalImpulse, const FHitResult&, Hit);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPhysicsObjectAwakeChanged, UPrimitiveComponent*, SimulatingComponent, bool, bIsAwake);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRidingPawnAdded, AFortPlayerPawn*, RidingPawn);

USTRUCT(BlueprintType)
struct FFortPhysicsObjectBaseDamageOverrides
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortPhysicsObjectBaseDamageOverrides")
	float PlayerDamageOverride;

	UPROPERTY(BlueprintReadWrite, Category="FortPhysicsObjectBaseDamageOverrides")
	float VehicleDamageOverride;

	UPROPERTY(BlueprintReadWrite, Category="FortPhysicsObjectBaseDamageOverrides")
	float EnvironmentDamageOverride;

	UPROPERTY(BlueprintReadWrite, Category="FortPhysicsObjectBaseDamageOverrides")
	float WildlifeDamageOverride;

};

USTRUCT(BlueprintType)
struct FPhysicsObjectDeactivationSnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FQuat Rotation;

};

USTRUCT()
struct FPhysicsObjectImpactInstigatorData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> ImpactInstigator;

	UPROPERTY()
	float ServerTimeAssigned;

};

USTRUCT(BlueprintType)
struct FPhysicsObjectMovementStateData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Physics Object|Movement State")
	EFortPhysicsObjectMovementState MovementState;

	UPROPERTY(BlueprintReadOnly, Category="Physics Object|Movement State")
	EFortPhysicsObjectMovementState PreviousMovementState;

	UPROPERTY(BlueprintReadOnly, Category="Physics Object|Movement State")
	FHitResult LastMovingHitResult;

	UPROPERTY(BlueprintReadOnly, Category="Physics Object|Movement State")
	float TimeMovementStateUpdated;

	UPROPERTY(BlueprintReadOnly, Category="Physics Object|Movement State")
	float MovingStopTime;

};

USTRUCT()
struct FPhysicsObjectSetupTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PhysicsObjectSetupTags", meta=(Categories="PhysicsObject.Preset"))
	FGameplayTag PhysicsObjectPresetTag;

	UPROPERTY(EditAnywhere, Category="PhysicsObjectSetupTags", meta=(Categories="PhysicsObject.PhysData"))
	FGameplayTag PhysicsObjectPhysicalDataTag;

	UPROPERTY(EditAnywhere, Category="PhysicsObjectSetupTags", meta=(Categories="PhysicsObject.BuoyancyData"))
	FGameplayTag PhysicsObjectBuoyancyDataTag;

	UPROPERTY(EditAnywhere, Category="PhysicsObjectSetupTags", meta=(Categories="PhysicsObject.ImpactDamageData"))
	FGameplayTag PhysicsObjectImpactDamageDataTag;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Activation", "Collision", "ComponentReplication", "Sockets", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPhysicsObjectComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortPhysicsObjectComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Physics Object", meta=(DeprecatedFunction, DeprecationMessage="ActivatePhysicsObject is no longer neccessary, please remove. You can just wake the object up or start applying impulses/etc"))
	static void ActivatePhysicsObject(UFortPhysicsObjectComponent* PhysicsObjectComponent, EFortPhysicsObjectActivationType InActivationType = EFortPhysicsObjectActivationType::Normal);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void AddToIgnoredDamageActors(const AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="Physics Object", meta=(DefaultToSelf="PhysicsObject", DisplayName="HasSetupPhysicsObject"))
	static bool BP_HasSetupPhysicsObject(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void CacheLastPlayerHit(AFortPlayerPawn* Player);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void ClearIgnoredDamageActors();

	UFUNCTION(BlueprintCallable)
	void DecrementNeverSleep();

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	static void DisableMovementStateUpdates(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	static void DisableOverlapEvents(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	static void EnableMovementStateUpdates(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	static void EnableOverlapEvents(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void GetCachedRidingPlayersInfo(int32& NumberOfCachedPlayer, TArray<FVector>& OnBoardLocation, TArray<FVector>& OffBoardLocation, TArray<float>& SessionLength, bool bCleanAfterCopy = true);

	UFUNCTION(BlueprintPure, Category="Physics Object")
	float GetGravity(bool bUseGravityMultiplier = true) const;

	UFUNCTION(BlueprintPure, Category="Physics Object")
	const float GetMaxLinearVelocityOverride() const;

	UFUNCTION(BlueprintPure, Category="Physics Object")
	void GetMovingStateData(AActor*& OutInstigator, FHitResult& OutHitResult, float& OutLinearSpeed, EFortPhysicsObjectMovementState& OutMovementState) const;

	UFUNCTION(BlueprintPure, Category="Physics Object")
	UPrimitiveComponent* GetSimulatingComponent() const;

	UFUNCTION(BlueprintCallable)
	void IgnorePawnForBasing(AFortPawn* Pawn, bool bIgnoreBasing = true, float OptionalIgnoreTime = -1.000000f);

	UFUNCTION(BlueprintCallable)
	void IgnorePawnForCollision(AFortPawn* Pawn, bool bIgnore, bool bIgnoreQueryCollision = true);

	UFUNCTION(BlueprintCallable)
	void IncrementNeverSleep();

	UFUNCTION(BlueprintPure, Category="Physics Object")
	bool IsAwake() const;

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void PutToSleep();

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	static void PutToSleepPhysicsObject(AActor* PhysicsObject);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void RemoveFromIgnoredDamageActors(const AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	static void SetAngularDamping(AActor* PhysicsObject, const TArray<FGameplayTag>& PresetTagsRequired, const bool bUsePresetValue = true, const float InAngularDamping = 1.000000f);

	UFUNCTION(BlueprintCallable)
	void SetBaseDamageOverrides(const FFortPhysicsObjectBaseDamageOverrides& InBaseDamageOverrides);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void SetGravityOverride(const bool bInGravityOverridden, const float InGravityOverride);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void SetLinearDampingOverride(const float InLinearDampingOverride);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void SetMassOverride(const float InMassOverride, const bool bInScaleMassWithObjectScale);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void SetMaxLinearVelocity(const float InMaxLinearVelocityOverride);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Physics Objects")
	static void SetPhysicsObjectPhysicalDataTag(AActor* PhysicsObject, const FGameplayTag& InPhysicsObjectPresetTag);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	void WakeUp(EFortPhysicsObjectActivationType InActivationType = EFortPhysicsObjectActivationType::Normal);

	UFUNCTION(BlueprintCallable, Category="Physics Object")
	static void WakeUpPhysicsObject(AActor* PhysicsObject, EFortPhysicsObjectActivationType InActivationType = EFortPhysicsObjectActivationType::Normal);

	UPROPERTY(BlueprintAssignable, Category="Physics Object")
	FOnPhysicsObjectAwakeChanged OnAwakeChanged;

	UPROPERTY(BlueprintAssignable, Category="Physics Object")
	FOnComponentHitSignature OnReceivedLargeImpulse;

	UPROPERTY(BlueprintAssignable, Category="Physics Object")
	FOnComponentHitSignature OnVehicleHit;

	UPROPERTY(BlueprintAssignable, Category="Physics Object")
	FOnRidingPawnAdded OnRidingPawnAdded;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="Physics Object", meta=(EditInline="true"))
	TObjectPtr<UBuoyancyComponent> BuoyancyComponent;

	UPROPERTY(BlueprintReadWrite, Category="Physics Object")
	FVector PreviousLinearVelocity;

	UPROPERTY(BlueprintReadWrite, Category="Physics Object")
	FVector LinearVelocity;

	UPROPERTY(BlueprintReadWrite, Category="Physics Object")
	float MaxLinearVelocityOverride;

	UPROPERTY(BlueprintReadWrite, Category="Physics Object")
	FVector PreviousAngularVelocity;

	UPROPERTY(BlueprintReadWrite, Category="Physics Object")
	FVector AngularVelocity;

	UPROPERTY(BlueprintReadWrite, Category="Physics Object")
	float CustomGravityMultiplier;

	UPROPERTY(Transient, Replicated)
	float GravityOverride;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Physics Object")
	FPhysicsObjectMovementStateData MovementStateData;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Physics Object|Overrides")
	float MassOverrideKg;
#endif

private:
	UFUNCTION()
	void DeferredSetupPhysicsObject();

	UFUNCTION()
	void HandleBasingChange(AFortPawn* BasedPawn);

	UFUNCTION()
	void HandleBuildingAbilitySystemComponentInitialized();

	UFUNCTION()
	void HandleConnectedActorDestroyed(AActor* DamageCauser);

	UFUNCTION()
	void HandleConnectedPhysicsActorWake(AActor* PhysicsActor);

	UFUNCTION()
	void HandleEnteredWaterBody(const FSphericalPontoon& FXPoint);

	UFUNCTION()
	void HandleLinkedActorDisconnected();

	UFUNCTION()
	void HandlePreAbilitySystemComponentInitialized();

	UFUNCTION()
	void HandleSimulatingComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& InHit);

	UFUNCTION()
	void HandleSimulatingComponentSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);

	UFUNCTION()
	void HandleSimulatingComponentWake(UPrimitiveComponent* WakingComponent, FName BoneName);

	UFUNCTION()
	void OnRep_ActivationType();

	UFUNCTION()
	void OnRep_AwakeState();

	UFUNCTION()
	void OnRep_DeactivationSnapshotData();

	UFUNCTION()
	void OnRep_DisableMovementStateUpdates();

	UFUNCTION()
	void OnRep_DisableOverlapEvents();

	UFUNCTION()
	void OnRep_PhysicsObjectSetupTags(const FPhysicsObjectSetupTags& PrevPhysicsObjectSetupTags);

	UFUNCTION()
	void OnRep_ServerHasSetupPhysicsObject();

	UPROPERTY(ReplicatedUsing=OnRep_PhysicsObjectSetupTags, meta=(Categories="PhysicsObject.Preset"))
	FPhysicsObjectSetupTags PhysicsObjectSetupTags;

	UPROPERTY(VisibleDefaultsOnly, Category="Physics Object|Defaults")
	TObjectPtr<UFortPhysicsObjectPreset> PhysicsPreset;

	UPROPERTY(VisibleDefaultsOnly, Category="Physics Object|Overrides")
	TObjectPtr<UFortPhysicsObjectCollisionEffectsData> EffectsDataOverride;

	UPROPERTY(VisibleDefaultsOnly, Category="Physics Object|Overrides")
	TObjectPtr<UPhysicalMaterial> PhysicalMaterialOverride;

	UPROPERTY(VisibleDefaultsOnly, Category="Physics Object|Overrides")
	TObjectPtr<UFortPhysicsObjectBuoyancyData> BuoyancyAssetOverride;

	UPROPERTY(VisibleDefaultsOnly, Category="Physics Object|Overrides")
	TObjectPtr<UFortPhysicsObjectImpactDamageData> ImpactDamageDataOverride;

	UPROPERTY(VisibleDefaultsOnly, Category="Physics Object|Overrides")
	TObjectPtr<UFortPhysicsObjectNavigationData> NavigationData;

	UPROPERTY()
	FVector PhysicsObjectInitialLocation;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ActivationType)
	EFortPhysicsObjectActivationType ActivationType;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AwakeState)
	EFortPhysicsObjectAwakeState PhysicsObjectAwakeState;

	UPROPERTY(Transient)
	uint8 bHasSetupPhysicsObject : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerHasSetupPhysicsObject)
	uint8 bServerHasSetupPhysicsObject : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bForceStartActiveAndAwake : 1;

	UPROPERTY(Transient)
	uint8 bHasComponentActivated : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DisableOverlapEvents)
	uint8 bDisableOverlapEvents : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DisableMovementStateUpdates)
	uint8 bDisableMovementStateUpdates : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bGravityOverridden : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DeactivationSnapshotData)
	FPhysicsObjectDeactivationSnapshot DeactivationSnapshotData;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> SimulatingComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortLinkToActorComponent> LinkToActorComponent;

	UPROPERTY(Transient)
	FPhysicsObjectImpactInstigatorData ImpactInstigatorData;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> IgnoredActorsForDamage;

	UPROPERTY(Transient, Replicated)
	TArray<TWeakObjectPtr<AFortPawn>> IgnoredPawnsForBasing;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortPawn>> IgnoredPawns;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortPawn>> IgnoredPawnsPendingRemoval;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Category="Physics Object|Debug")
	TSoftObjectPtr<UMaterialInterface> PreviewMaterial;
#endif

};

