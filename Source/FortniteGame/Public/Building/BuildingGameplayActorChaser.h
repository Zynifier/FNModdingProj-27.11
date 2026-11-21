// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "BuildingGameplayActorChaser.generated.h"

class AActor;
class AFortPlayerPawn;
class UCapsuleComponent;
class UFortProjectileMoveComp_Chase;
class UObject;

USTRUCT(BlueprintType)
struct FChaserMarkerPosition
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ChaserMarkerPosition")
	float MarkerPosition;

};

USTRUCT()
struct FChaserPatrolTurnData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bPatrolTurning;

	UPROPERTY()
	FVector PatrolTurnStartDirection;

	UPROPERTY()
	FVector PatrolTurnEndDirection;

	UPROPERTY()
	float PatrolMoveSpeed;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorChaser : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AttachedToChaseTarget();

	UFUNCTION(BlueprintCallable)
	void ChaseTargetDamaged();

	UFUNCTION(BlueprintCallable)
	void DetachedFromChaseTarget();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void EndForcedPlayerForwardMovement();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void ForcePlayerForwardMovement(AFortPlayerPawn* Player, float MaxSpeedScale);

	UFUNCTION(BlueprintPure, Category="Targeting")
	AActor* GetChaseTarget();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category="Targeting")
	void SetChaseTarget(AActor* InChaseTarget, bool bInHomeOnChaseTarget = true, float InTargetReachedDistanceOverride = 0.000000f);

	UFUNCTION(BlueprintCallable)
	void SetHealthBarMarkerPosition(float MarkerPosition);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="Targeting", meta=(EditInline="true"))
	TObjectPtr<UFortProjectileMoveComp_Chase> FortProjectileMoveComp_Chase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="Collision", meta=(EditInline="true"))
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Targeting")
	FName TargetSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FName TargetPlayerSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Targeting")
	FName TargetNpcSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	FGameplayTagQuery ValidTargetQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat TargetingRangeMax;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	TArray<TEnumAsByte<EObjectTypeQuery>> TargetObjectTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat TargetingPrioritizePlayersOverNpcs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat ChaseDistanceFromTargetToAttach;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat PatrolTargetHeightAboveGround;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat PatrolNewDirectionMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat PatrolNewDirectionMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat PatrolDriftRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat PatrolMoveSpeedMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat PatrolMoveSpeedMax;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FScalableFloat PatrolGroundFindDistance;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	TArray<TEnumAsByte<EObjectTypeQuery>> PatrolAvoidObjectTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Balance")
	FScalableFloat PatrolTurnSeconds;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PatrolTurnData)
	FChaserPatrolTurnData PatrolTurnData;

protected:
	UFUNCTION(BlueprintPure, Category="Targeting")
	bool IsValidTarget(UObject* PotentialTarget);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Targeting")
	void LookForNewTarget();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, BlueprintAuthorityOnly)
	void MulticastNetCullDistance(float DistanceSquared);

	UFUNCTION()
	void OnRep_PatrolTurnData();

	UFUNCTION(BlueprintImplementableEvent, Category="Targeting")
	void OnTargetAcquired();

	UFUNCTION()
	void PotentialTargetFound(AActor* InDetectedItem);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Targeting")
	void RandomNewPatrolDestination();

	UFUNCTION()
	void ShouldCancelTargetSearch(bool& bShouldCancel);

	UFUNCTION(BlueprintCallable, Category="Movement")
	void StayAboveWater();

	UFUNCTION()
	void TargetSearchComplete(bool WasCancelled);

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> ForcedMovementTarget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FEventMessageTag AttachedMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> AttachedMessageType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FEventMessageTag DetachedMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> DetachedMessageType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FEventMessageTag SetMarkerPositionMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> SetMarkerPositionMessageType;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FName SetMarkerPositionMessageFloatPropertyName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	FEventMessageTag TargetDamagedMessageTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TObjectPtr<UObject> TargetDamagedMessageType;

	UPROPERTY(Transient)
	TObjectPtr<AActor> ChaseTarget;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> PotentialTargets;

	UPROPERTY(BlueprintReadOnly, Category="Replication")
	float DetachedNetCullDistanceSquared;

};

