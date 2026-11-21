// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortCharacterMovementMutator.generated.h"

class AActor;
class ACharacter;
class AFortPawn;
class UFortCharacterMovementMutatorComponent;
class UFortMovementComp_CharacterAthena;

UENUM(BlueprintType)
enum class EMutatorMovementMode : uint8
{
	/** Not in a mutator movement mode */
	None = 0,
	/** Buffet event - bubbles phase.  Air controls within a box that is locked to a follow actor. */
	BuffetBubbles = 25,
	/** Buffet event - transition from reflect to bubbles phase, moving toward a target location */
	BuffetBubblesIntro = 26,
	/** Buffet event - llama phase.  Yaw and pitch steering, no gravity.  Collisions trigger BuffetFlyingRicochet mode. */
	BuffetFlying = 27,
	/** Buffet event - llama phase.  The flying character bounced off of collision.  Rotates toward new Velocity, no controls. */
	BuffetFlyingRicochet = 28,
	/** Moves backward through recorded movement history, without player input */
	Rewind = 29,
};

USTRUCT()
struct FBuffetBubblesDebugData
{
	GENERATED_BODY()

};

USTRUCT()
struct FBuffetBubblesReplicatedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FTransform RelativeTransform;

	UPROPERTY()
	FVector RelativeVelocity;

};

USTRUCT()
struct FBuffetFlyingRicochetReplicatedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float StartTime;

	UPROPERTY()
	FVector Velocity;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Cooking", "LOD", "Mutator", "Replication", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortCharacterMovementMutator : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnFortPawnChanged(AFortPawn* NewPawn);

	UPROPERTY(EditDefaultsOnly, Category="FortCharacterMovementMutator")
	TSubclassOf<UFortCharacterMovementMutatorComponent> MovementMutatorComponentClass;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "AssetUserData", "Collision", "ComponentTick", "ComponentReplication", "Cooking", "Tags", "Variable"))
class UFortCharacterMovementMutatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetBuffetBubblesIntroTargetTransform(const FTransform& Transform);

protected:
	UFUNCTION()
	void OnRep_BuffetBubblesFollowActor();

	UFUNCTION(BlueprintCallable)
	void OverrideBuffetFlyingMaxSpeed(const float Value = -1.000000f, const bool bAsMultiplier = false, const float InterpSpeed = 2.000000f);

	UFUNCTION(BlueprintCallable)
	void OverrideBuffetFlyingVelocityDirectionInterpSpeed(const float Value, const bool bAsMultiplier = false);

	UFUNCTION(BlueprintCallable)
	void SetBuffetBubblesFollowActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void SetBuffetBubblesInitialFollowBoxOffsetPercent(const FVector BoxOffsetPercent);

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMoveToBoxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesRelativeVelocityInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesLocationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesRotationInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMinRelativeX;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMaxRelativeX;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMinRelativeY;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMaxRelativeY;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMinRelativeZ;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMaxRelativeZ;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FRotator BuffetBubblesRotationRate;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMaxAcceleration;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesMaxRelativeSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesRelativeDeceleration;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubbles")
	FScalableFloat BuffetBubblesSphereRadius;

	UPROPERTY(ReplicatedUsing=OnRep_BuffetBubblesFollowActor)
	TObjectPtr<AActor> BuffetBubblesFollowActor;

	UPROPERTY(ReplicatedUsing=OnRep_BuffetBubblesFollowActor)
	FVector BuffetBubblesInitialFollowBoxOffsetPercent;

	UPROPERTY(Replicated)
	FBuffetBubblesReplicatedData BuffetBubblesReplicatedData;

	UPROPERTY(EditDefaultsOnly, Category="BuffetBubblesIntro")
	FScalableFloat BuffetBubblesIntroSpeed;

	UPROPERTY(Replicated)
	FTransform BuffetBubblesIntroTargetTransform;

	UPROPERTY(EditDefaultsOnly, Category="BuffetFlying")
	FScalableFloat BuffetFlyingMaxPitchDegrees;

	UPROPERTY(EditDefaultsOnly, Category="BuffetFlying")
	FScalableFloat BuffetFlyingMaxSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BuffetFlying")
	FScalableFloat BuffetFlyingVelocityDirectionInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BuffetFlying")
	FRotator BuffetFlyingRotationRate;

	UPROPERTY(EditDefaultsOnly, Category="BuffetFlyingRicochet")
	FScalableFloat BuffetFlyingRicochetSphereSize;

	UPROPERTY(EditDefaultsOnly, Category="BuffetFlyingRicochet")
	FScalableFloat BuffetFlyingRicochetRotationDuration;

	UPROPERTY(EditDefaultsOnly, Category="BuffetFlyingRicochet")
	FScalableFloat BuffetFlyingRicochetControlRotationInterpSpeed;

private:
	UFUNCTION()
	void OnMovementModeChanged(ACharacter* Character, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void OnRep_BuffetFlyingRicochetReplicatedData();

	UPROPERTY()
	TObjectPtr<ACharacter> CharacterOwner;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMovementComp_CharacterAthena> MovementComponent;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMovementComp_CharacterAthena> CDOMovementComponent;

	UPROPERTY(Replicated)
	float BuffetFlyingMaxSpeedOverride;

	UPROPERTY(Replicated)
	float BuffetFlyingMaxSpeedInterpSpeed;

	UPROPERTY(Replicated)
	float BuffetFlyingVelocityDirectionInterpSpeedOverride;

	UPROPERTY(ReplicatedUsing=OnRep_BuffetFlyingRicochetReplicatedData)
	FBuffetFlyingRicochetReplicatedData BuffetFlyingRicochetReplicatedData;

};

