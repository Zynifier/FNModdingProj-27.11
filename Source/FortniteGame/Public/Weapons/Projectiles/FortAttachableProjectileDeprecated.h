// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortAttachableProjectileDeprecated.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

USTRUCT()
struct FAttachedInfo
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

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Replication", "Navigation", "Navigation", "Game|Damage"))
class AFortAttachableProjectileDeprecated : public AFortProjectileBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Gameplay")
	AActor* GetAttachedToActor();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFinalizeAttachmentSocketLocandRot(FVector InWorldPos, FRotator InWorldRot, FName InSocketName, bool bFoundClosestOnPhysicsAsset, FVector& OutWorldPos, FRotator& OutWorldRot, FName& OutSocketName);

	UFUNCTION()
	virtual void OnRep_ReplicatedAttachedInfo();

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void ServerAttachToActor(const FHitResult& Hit, AActor* AttachToActor, float StickyOffsetFromPhysicsMesh, float StickyOffsetFromBoneCenter, float NarrowPlacementAgainstVelocityThreshold);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedAttachedInfo)
	FAttachedInfo AttachedInfo;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAttachedToDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttachedToEndPlayed(AActor* DamagedActor, EEndPlayReason::Type EndPlayReason);

};

