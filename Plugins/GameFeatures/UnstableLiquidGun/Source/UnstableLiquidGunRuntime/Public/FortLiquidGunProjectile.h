// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortLiquidGunProjectile.generated.h"

class ALiquidRibbonManager;
class USceneComponent;
enum class ELiquidRibbonDetachmentReason : uint8;

UENUM(BlueprintType)
enum class ELiquidRibbonDetachmentReason : uint8
{
	/** No detachment*/
	NotDetached = 0,
	/** Detached due to the distance between projectiles */
	ByDistance = 1,
	/** Detached due to the angle between projectiles */
	ByAngle = 2,
};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Game|Damage"))
class UNSTABLELIQUIDGUNRUNTIME_API AFortLiquidGunProjectile : public AFortProjectileBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	ELiquidRibbonDetachmentReason GetDetachmentReason() const;

	UFUNCTION(BlueprintCallable)
	void SetDetachmentReason(ELiquidRibbonDetachmentReason InDetachmentReason);

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="Attach On Hit", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> AttachComponent;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Attach On Hit")
	FVector AttachOffset;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortLiquidGunProjectile")
	int32 ProjectileIndex;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortLiquidGunProjectile")
	FVector StopNormal;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortLiquidGunProjectile")
	TObjectPtr<ALiquidRibbonManager> RibbonManager;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	FScalableFloat MinDistBetweenProjectilesForSplineCollisionTest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	FScalableFloat MinDistBetweenInLineProjectilesForSplineCollisionTest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	FScalableFloat MinProjectileVelocityAngleToBeInLine;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	TEnumAsByte<ECollisionChannel> BroadSphereOverlapTraceChannel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	FName CapsuleTraceProfileName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	bool bCapsuleTraceComplex;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Detachment")
	FVector_NetQuantize RandomDetachmentAngleFirstHalf;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Detachment")
	FVector_NetQuantize RandomDetachmentAngleSecondHalf;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleSplineHit(const FHitResult& Hit);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	bool bDrawDebugCollision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Collision")
	bool bDrawDebugCollisionOnlyCapsuleTraceHits;

	UPROPERTY(Transient, Replicated)
	ELiquidRibbonDetachmentReason DetachmentReason;

};

