// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Engine/NetSerialization.h"
#include "Weapons/Projectiles/FortProjectileBase.h"
#include "FortProjectileAthena.generated.h"

class AActor;
class AFortProjectileAthena;
class AFortProjectileBase;
class AFortWaterBodyActor;
class UPrimitiveComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Navigation", "Navigation", "Navigation", "Game|Damage"))
class AFortProjectileAthena : public AFortProjectileBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_FireStart();

	UPROPERTY(ReplicatedUsing=OnRep_FireStart)
	FVector_NetQuantize FireStartLoc;

protected:
	UFUNCTION()
	FORTNITEGAME_API virtual void KillAfterNoPawnHit();

	UFUNCTION()
	FORTNITEGAME_API void OnOwnerDestroyed(AActor* DestroyedOwner);

	UFUNCTION()
	FORTNITEGAME_API virtual void OnRep_PawnHitResult();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void OnSniperTraceWaterHit(const FHitResult& WaterHit, AFortWaterBodyActor* WaterBody);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void ReplacedByRealProjectile(AFortProjectileAthena* RealProjectile);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	FORTNITEGAME_API void ReplacedPredictedProjectile(AFortProjectileBase* PredictedProjectile);

	UFUNCTION(Server, Reliable)
	FORTNITEGAME_API void ServerNotifyAutoKillDistanceExceeded();

	UFUNCTION(Server, Reliable, WithValidation)
	FORTNITEGAME_API void ServerNotifyEndOverlap(AActor* OtherActor, UPrimitiveComponent* OtherComp);

	UFUNCTION(Server, Reliable, WithValidation)
	FORTNITEGAME_API void ServerNotifyPawnHit(FHitResult Hit, const TArray<uint8>& Context);

	UPROPERTY(ReplicatedUsing=OnRep_PawnHitResult)
	FHitResult PawnHitResult;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	uint8 bExplodeOnPawnHit : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	uint8 bNoCollisionForNonOwningClients : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	uint8 bIgnoreActorsAttachedToFiringPawn : 1;

	UPROPERTY(Transient)
	uint8 bProcessLocalHits : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	float TimeToWaitForPawnHitBeforeKillOnServer;

	UPROPERTY(Transient)
	TObjectPtr<AActor> PredictedHitActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> PredictedHitComp;

};

