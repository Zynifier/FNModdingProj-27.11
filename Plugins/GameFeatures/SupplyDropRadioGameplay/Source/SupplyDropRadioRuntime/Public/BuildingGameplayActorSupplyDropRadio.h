// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorSupplyDropRadio.generated.h"

class AActor;
class UBoxComponent;
enum class ESupplyDropRadioBalloonState : uint8;

UENUM(BlueprintType)
enum class ESupplyDropRadioBalloonState : uint8
{
	/** Invalid state. */
	Invalid = 0,
	/** The balloon is closed and has the potential to be 
	*	opened up when at a certain distance from the ground. 
	*	The actor incorporates the gravity acceleration in its falling movement. */
	Closed = 1,
	/** The balloon is open. It ignores the gravity acceleration and falls 
	*	to the ground at a constant speed. */
	Opened = 2,
	/** The balloon is destroyed and the actor incorporates the gravity 
	*	acceleration in its falling movement. */
	Destroyed = 3,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorSupplyDropRadio : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Supply Drop Radio")
	ESupplyDropRadioBalloonState GetBalloonState() const;

	UFUNCTION(BlueprintPure, Category="Supply Drop Radio")
	float GetGravityZ() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Supply Drop Radio")
	AActor* GetHighestAttachParent(const AActor* InActor) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure, Category="Supply Drop Radio")
	UBoxComponent* GetRootCollisionComponent() const;

	UFUNCTION()
	void HandleMoveIgnoredActorEndPlay(AActor* EndPlayActor, EEndPlayReason::Type Reason);

	UFUNCTION(BlueprintImplementableEvent, Category="Supply Drop Radio")
	bool IsGrounded() const;

	UFUNCTION(BlueprintPure, Category="Supply Drop Radio")
	bool IsMoving() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Supply Drop Radio")
	void OnRep_BalloonState();

	UFUNCTION(BlueprintImplementableEvent, Category="Supply Drop Radio")
	void OnRep_DistanceFromOriginalSpawnLocForBalloonOpen();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintAuthorityOnly, Category="Supply Drop Radio")
	void OpenSupplyDrop();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Supply Drop Radio")
	void SetBalloonState(const ESupplyDropRadioBalloonState InBalloonState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Supply Drop Radio")
	void SetGravityMultiplier(const float InGravityMultiplier);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Supply Drop Radio")
	void UpdateGroundInfo(const bool bValidBlock, const FHitResult& MovementHitResult);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Supply Drop Radio")
	float MinimumMovingSpeedThresholdSq;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Supply Drop Radio")
	float BalloonClosedGroundedFallSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Supply Drop Radio")
	bool bAutoOpen;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Supply Drop Radio")
	FGameplayTagContainer ForceOpenActorTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Supply Drop Radio")
	FGameplayTagQuery IgnoreMovingCollisionWithActorTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Supply Drop Radio")
	float InterpRateToBalloonOpenedFallSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_DistanceFromOriginalSpawnLocForBalloonOpen, Category="Supply Drop Radio")
	float DistanceFromOriginalSpawnLocForBalloonOpen;

	UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_BalloonState, Category="Supply Drop Radio")
	ESupplyDropRadioBalloonState BalloonState;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Supply Drop Radio")
	FHitResult WaterHitResult;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Supply Drop Radio")
	bool bMoving;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Supply Drop Radio")
	float FallSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Supply Drop Radio")
	float BalloonOpenedFallSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Supply Drop Radio")
	float GravityMultiplier;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Supply Drop Radio")
	FVector ServerLocation;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Supply Drop Radio")
	float ClientLocationCorrectionMaxDistSqWhenBalloonDisabled;

	UPROPERTY(BlueprintReadWrite, Transient, Replicated, Category="Supply Drop Radio")
	float ClientLocationCorrectionMaxDistSqWhenBalloonEnabled;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Supply Drop Radio")
	FVector Velocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Supply Drop Radio")
	FVector PreviousFrameVelocity;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Supply Drop Radio")
	FVector OriginalServerSpawnLocation;

};

