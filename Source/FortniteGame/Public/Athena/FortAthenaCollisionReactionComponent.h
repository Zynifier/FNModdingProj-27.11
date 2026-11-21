// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Physics/FortPhysicsSimSize.h"
#include "FortAthenaCollisionReactionComponent.generated.h"

class AActor;
class ABuildingActor;
class UFortLandscapeClampingHelper;
class UGameplayEffect;
class UPrimitiveComponent;
enum class FCollisionReactionType : uint8;

UENUM()
enum class ETypeOfBuildingActor : int32
{
	// Any kind of Building actor would be handled

	Anything = 0,
	// Only player built building actors (that have a valid BuildingType) 

	PlayerBuilt = 1,
	// Only non-player built building actors (or player built that have an invalid BuildingType)

	NonPlayerBuilt = 2,
};

UENUM(BlueprintType)
enum class FCollisionReactionType : uint8
{
	Nothing = 0,
	Pawn = 1,
	Vehicle = 2,
	PhysicsObject = 3,
	BuildingActor = 4,
};

UENUM()
enum class FCollisionWithBuildingActorReactionTypes : int32
{
	DoNothing = 0,
	PlayAttackAbility = 1,
	Destroy = 2,
	ApplyGameplayEffect = 3,
};

UENUM()
enum class FCollisionWithLaunchableReactionTypes : int32
{
	DoNothing = 0,
	Launch = 1,
	// Won't do anything but will still get used internally to override other behaviours
// ex. if you set the PhysicsObjectReaction to OverrideOther, it will stop a building actor physics object to trigger a reaction

	OverrideOther = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FCollisionReactionComponentOnReaction, const AActor*, HitActor, const bool, bFromAsyncSweepBox, FCollisionReactionType, CollisionReactionType, const bool, bIsFirstContinuousReactionOnDelayableActor, const FHitResult&, HitResult);

USTRUCT()
struct FCollisionReactionConfigurationPerPhysicsObjectSize
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CollisionReactionConfigurationPerPhysicsObjectSize")
	FVector LaunchVelocity;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfigurationPerPhysicsObjectSize")
	FVector LaunchAngularVelocity;

};

USTRUCT()
struct FCollisionReactionForcedLaunchDirection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CollisionReactionForcedLaunchDirection")
	FVector2D LaunchDirection;

};

USTRUCT(BlueprintType)
struct FCollisionReactionConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	bool bEnabled;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	bool bAutoRun;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	bool bAutomaticallyRegisterCapsule;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	bool bAutomaticallyRegisterMesh;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	bool bBoxSweepEnabled;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bBoxSweepEnabled"))
	float OverriddenSweepBoxDelay;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bBoxSweepEnabled"))
	TArray<TEnumAsByte<EObjectTypeQuery>> BoxSweepTypes;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bBoxSweepEnabled"))
	FVector BoxSweepOffset;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(ClampMax="360", ClampMin="-360", EditCondition="bBoxSweepEnabled"))
	FRotator BoxSweepRotation;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bBoxSweepEnabled"))
	bool bProjectBoxSweepRotationOnTheFloor;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bBoxSweepEnabled"))
	FVector BoxSweepExtent;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bBoxSweepEnabled"))
	FName BoxSweepFollowBone;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bBoxSweepEnabled"))
	float BoxSweepVelocityMultiplier;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="bTeleportPawnOnSweepBoxExtremePenetration"))
	float ExtremePenetrationThreshold;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	bool bUseImpactNormal;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float BehindCollisionLaunchVelocityMultiplier;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float AheadCollisionLaunchVelocityMultiplier;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float MinimumMovementVelocityForLaunchVelocityMultiplier;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float MaximumMovementVelocityForLaunchVelocityMultiplier;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float LaunchVelocityMultiplierAtMinimumMovementVelocity;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float LaunchVelocityMultiplierAtMaximumMovementVelocity;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float LaunchVelocityMultiplierWhenAboveSweep;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float AboveSweepThresholdForLaunchVelocityMultiplier;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float LaunchVelocityMaximumMultiplier;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	TArray<FCollisionReactionForcedLaunchDirection> ForcedLaunchDirections;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	TArray<TSubclassOf<UGameplayEffect>> BuildingActorGameplayEffectClasses;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	FCollisionWithBuildingActorReactionTypes BuildingActorReaction;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	float BuildingActorImmunityDuration;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="BuildingActorReaction != FCollisionWithBuildingActorReactionTypes::DoNothing"))
	ETypeOfBuildingActor TypeOfBuildingActor;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="BuildingActorReaction != FCollisionWithBuildingActorReactionTypes::DoNothing"))
	FGameplayTagContainer BuildingActorBlacklistTags;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	FCollisionWithLaunchableReactionTypes PawnReaction;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="PawnReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	FGameplayTagContainer PawnBlacklistTags;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="PawnReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	float TeleportPawnOnSweepBoxExtremePenetrationForSeconds;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="TeleportPawnOnSweepBoxExtremePenetrationForSeconds > 0 && PawnReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	float ExtraSpacingWhenTeleportingOutsideOfSweepBox;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="PawnReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	FVector PawnReactionLaunchVelocity;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="PawnReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	float PawnReactionDelayPerActor;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	FCollisionWithLaunchableReactionTypes VehicleReaction;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="VehicleReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	FVector VehicleReactionLaunchVelocity;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="VehicleReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	float VehicleReactionDelayPerActor;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="PhysicsObjectReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	ETypeOfBuildingActor TypeOfBuildingActorOnPhysicsObject;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration")
	FCollisionWithLaunchableReactionTypes PhysicsObjectReaction;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="PhysicsObjectReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	TMap<EFortPhysicsSimSize, FCollisionReactionConfigurationPerPhysicsObjectSize> PhysicsObjectReactionPerPhysicsObjectSize;

	UPROPERTY(EditAnywhere, Category="CollisionReactionConfiguration", meta=(EditCondition="PhysicsObjectReaction != FCollisionWithLaunchableReactionTypes::DoNothing"))
	float PhysicsObjectReactionDelayPerActor;

};

UCLASS(Config=Game, ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UFortAthenaCollisionReactionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CollisionReactions")
	bool K2_IsBuildingActorValidForReaction(const ABuildingActor* BuildingActor) const;

	UFUNCTION(BlueprintCallable, Category="CollisionReactions")
	void RegisterPrimitiveForCollisionsReaction(const UPrimitiveComponent* PrimitiveComponentToRegister);

	UFUNCTION(BlueprintCallable, Category="CollisionReactions")
	void RegisterPrimitiveForOverlapReaction(const UPrimitiveComponent* PrimitiveComponentToRegister);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CollisionReactions")
	bool Run();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CollisionReactions")
	void Stop();

protected:
	UFUNCTION()
	void HandleImpactForCollisionReaction(const UPrimitiveComponent* HitComponent, const AActor* OtherActor, const UPrimitiveComponent* OtherComp, const FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void HandleOverlapForCollisionReaction(const UPrimitiveComponent* OverlappedComponent, const AActor* OtherActor, const UPrimitiveComponent* OtherComp, const int32 OtherBodyIndex, const bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(BlueprintAssignable, Category="Interaction")
	FCollisionReactionComponentOnReaction OnReaction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HitReacts")
	FCollisionReactionConfiguration CollisionReactionConfiguration;

	UPROPERTY(Transient)
	TObjectPtr<UFortLandscapeClampingHelper> LandscapeClampingHelper;

};

