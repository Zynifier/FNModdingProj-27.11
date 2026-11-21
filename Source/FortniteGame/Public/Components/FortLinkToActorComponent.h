// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Physics/Experimental/ChaosEventType.h"
#include "FortLinkToActorComponent.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;
enum class ELinkToDirection : uint8;

UENUM()
enum class ELinkToDirection : uint8
{
	Up = 0,
	// owners up vector 

	Down = 1,
	// owners -up vector

	Right = 2,
	// owners right vector

	Left = 3,
	// owners -right vector

	Forward = 4,
	// owners forward vector

	Backward = 5,
};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortLinkToActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLinkedActorConnected, AActor*, LinkedActor);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLinkedActorDestroyed, AActor*, DamageCauser);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLinkedActorDisconnected);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLinkedPhysicsObjectWake, AActor*, PhysicsObject);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="LinkToActor Component")
	void GetActorsLinkedTo(TArray<AActor*>& OutArray);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="LinkToActor Component")
	ELinkToDirection GetDirectionForLink() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="LinkToActor Component")
	bool PerformLinkingCheck(const ELinkToDirection InDirection, UPARAM(ref) AActor*& OutActorLinkedTo);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="LinkToActor Component")
	void RegisterWithOwnersProjectileMovementComponent();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="LinkToActor Component")
	void SetPerformLinkingCheckOnBeginPlay(const bool bCheckOnBeginPlay);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="LinkToActor Component")
	void SetRegisterWithOwnerMovementComponent(const bool bRegisterWithMovementComp);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="LinkToActor Component")
	void SetUseActorRotationForDirectionVectors(const bool InbUseActorRotationForDirectionVectors);

	UPROPERTY(BlueprintAssignable)
	FOnLinkedActorDestroyed OnLinkedActorDestroyed;

	UPROPERTY(BlueprintAssignable)
	FOnLinkedActorConnected OnLinkedActorConnected;

	UPROPERTY(BlueprintAssignable)
	FOnLinkedActorDisconnected OnLinkedActorDisconnected;

	UPROPERTY(BlueprintAssignable)
	FOnLinkedPhysicsObjectWake OnLinkedPhysicsObjectWake;

protected:
	UFUNCTION()
	void OnMonitorLinkedActors();

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	uint8 bPerformLinkingCheckOnBeginPlay : 1;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	uint8 bRegisterWithOwnerMovementComponent : 1;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	uint8 bUseActorRotationForDirectionVectors : 1;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	uint8 bMonitorLinkedActorForChanges : 1;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	uint8 bUseActorLocationForLinkingCheck : 1;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	uint8 bOverrideBoxExtentForLinkingCheck : 1;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data", meta=(EditCondition="bOverrideBoxExtentForLinkingCheck"))
	FVector LinkingTraceBoxExtentOverride;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	FVector DirectionTraceStartOffset;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	ELinkToDirection DirectionForLink;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	float DirectionTraceLength;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data")
	FName ActorTag;

	UPROPERTY(EditAnywhere, Category="LinkToActor Data", meta=(ClampMax="5", ClampMin="1"))
	int32 NumActorsToLinkMax;

private:
	UFUNCTION()
	void HandleBuildingActorDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleLinkedActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void HandleLinkedActorEndedPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void HandleLinkedPhysicsObjectAwakeChanged(UPrimitiveComponent* SimulatingComponent, bool bIsAwake);

	UFUNCTION()
	void HandleMovementStopped(const FHitResult& Hit);

	UFUNCTION()
	void HandleSimulatedObjectAwake(UPrimitiveComponent* SimulatingComponent, FName Bone);

	UFUNCTION()
	void OnGeometryCollectionBreak(const FChaosBreakEvent& BreakEvent);

	UFUNCTION()
	void OnGeometryCollectionCrumbling(const FChaosCrumblingEvent& Event);

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> ActorsLinkedTo;

};

