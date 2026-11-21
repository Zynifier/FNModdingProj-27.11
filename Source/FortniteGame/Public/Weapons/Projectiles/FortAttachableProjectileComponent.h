// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "GameplayCueInterface.h"
#include "Math/MathFwd.h"
#include "FortAttachableProjectileComponent.generated.h"

class AActor;
class AController;
class AFortProjectileBase;
class UPrimitiveComponent;
class UProjectileMovementComponent;
enum class EFortProjectileDetachReason : uint8;

UENUM(BlueprintType)
enum class EFortProjectileDetachReason : uint8
{
	//----------------------------------------------------------------------------------------------------------------------

	HostDied = 0,
	//----------------------------------------------------------------------------------------------------------------------

	HostEndedPlay = 1,
	//----------------------------------------------------------------------------------------------------------------------

	Ejected = 2,
};

USTRUCT()
struct FFinalizedAttachmentParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector WorldLocation;

	UPROPERTY()
	FRotator WorldRotation;

	UPROPERTY()
	FName SocketName;

};

USTRUCT()
struct FReplicatedAttachParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FHitResult Hit;

	UPROPERTY()
	TObjectPtr<AActor> AttachedToActor;

	UPROPERTY()
	FVector_NetQuantize10 AttachOffset;

	UPROPERTY()
	FVector_NetQuantizeNormal VelocityNormalized;

	UPROPERTY()
	float NarrowPlacementAgainstVelocityThreshold;

	UPROPERTY()
	float StickyOffsetFromPhysicsMesh;

	UPROPERTY()
	float StickyOffsetFromBoneCenter;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAttachableProjectileComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFinalizeAttachmentDelegate, const FVector&, WorldLocation, const FRotator&, WorldRotation, const FName&, SocketName);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnProjectileAttached, AActor*, ActorAttachedTo, const FVector&, WorldLocation, const FVector&, AttachmentNormal);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProjectileDetached, AActor*, HostActor, EFortProjectileDetachReason, DetachReason);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Gameplay")
	void AuthorityAttachToActor(const FHitResult& Hit, const AActor* AttachToActor, const float StickyOffsetFromPhysicsMesh, const float StickyOffsetFromBoneCenter, const float NarrowPlacementAgainstVelocityThreshold);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void EjectFromAttachedToActor();

	UFUNCTION(BlueprintPure, Category="Gameplay")
	AActor* GetAttachedToActor() const;

	UFUNCTION()
	virtual void OnRep_AttachParams();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void OverrideFinalizedAttachmentParams(const FVector& WorldLocation, const FRotator& WorldRotation, const FName& SocketName);

	UPROPERTY(BlueprintAssignable, Category="Gameplay")
	FOnProjectileDetached OnProjectileDetached;

	UPROPERTY(BlueprintAssignable, Category="Gameplay")
	FOnFinalizeAttachmentDelegate OnFinalizeAttachment;

	UPROPERTY(BlueprintAssignable, Category="Gameplay")
	FOnProjectileAttached OnProjectileAttached;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortProjectileBase> Projectile;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AttachParams)
	FReplicatedAttachParams AttachParams;

	UPROPERTY(EditDefaultsOnly, Category="FortAttachableProjectileComponent")
	bool bDisableCollisionWhileAttached;

	UPROPERTY(EditDefaultsOnly, Category="FortAttachableProjectileComponent")
	bool bAttachAtImpactPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag OnAttachCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag WhileAttachedCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag OnDetachCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileEffects")
	FGameplayCueTag WhileDetachedCue;

protected:
	UFUNCTION()
	void HandleAttachedToDied(const AActor* DamagedActor, const float Damage, const AController* InstigatedBy, const AActor* DamageCauser, const FVector HitLocation, const UPrimitiveComponent* HitComponent, const FName BoneName, const FVector Momentum);

	UFUNCTION()
	void HandleAttachedToEndedPlay(const AActor* DamagedActor, const EEndPlayReason::Type EndPlayReason);

	UPROPERTY(Transient)
	FFinalizedAttachmentParams FinalizedAttachmentParams;

};

