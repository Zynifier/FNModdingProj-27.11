// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "ScoutDroneTypes.h"
#include "FortScoutDronePickupManager.generated.h"

class AActor;
class AController;
class AFortPawn;
class UPrimitiveComponent;

USTRUCT()
struct FScoutDroneCapsuleSizeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneCapsuleSizeData")
	FScalableFloat CapsuleHalfHeight;

	UPROPERTY(EditDefaultsOnly, Category="ScoutDroneCapsuleSizeData")
	FScalableFloat CapsuleRadius;

};

UCLASS(BlueprintType, HideCategories=("Trigger", "PhysicsVolume"))
class UFortScoutDronePickupManager : public UPawnComponent
{
	GENERATED_BODY()

public:
	UFortScoutDronePickupManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="PickUp")
	bool HasAnyAttachedActors() const;

	UFUNCTION(BlueprintPure, Category="PickUp")
	bool HasAPawnAtached() const;

	UFUNCTION(Server, Reliable)
	void ServerDropAttachedActors();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Cosmetic Events", meta=(DisplayName="OnActorsAttached"))
	void BP_OnActorsAttached();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Cosmetic Events", meta=(DisplayName="OnActorsDetached"))
	void BP_OnActorsDetached();

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_AttachedTargets, Category="FortScoutDronePickupManager")
	FScoutDronePickupTargets AttachedTargets;

private:
	UFUNCTION()
	void OnAttachedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnPawnDBNOStateChanged(AFortPawn* Pawn, bool bIsDBNO);

	UFUNCTION()
	void OnRep_AttachedTargets();

	UFUNCTION(Server, Reliable)
	void ServerUpdateItemAttachment(FVector CalculatedItemOffset);

	UPROPERTY(EditDefaultsOnly, Category="FortScoutDronePickupManager")
	FName AttachPointSocketName;

	UPROPERTY(Transient)
	FScoutDronePickupTargets PreviouslyAttachedTargets;

	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	FVector ItemOffset;

	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	FVector DBNOPawnOffset;

	UPROPERTY(Transient)
	float CurrentlyAppliedCameraOffset;

	UPROPERTY(EditDefaultsOnly, Category="Collision")
	FScoutDroneCapsuleSizeData MaxExtraCapsuleDimensions;

	UPROPERTY(EditDefaultsOnly, Category="Tossing", meta=(ClampMax="90", ClampMin="0", ForceUnits="deg", UIMax="90", UIMin="0"))
	FScalableFloat MaxPickupSpread;

	UPROPERTY(EditDefaultsOnly, Category="Tossing")
	FScalableFloat PickupTossSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Mobile Data")
	FGameplayTagContainer ItemsPickupTags;

};

