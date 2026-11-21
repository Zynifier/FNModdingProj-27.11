// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoverTypes.h"
#include "KinematicMoverComponent.generated.h"

class AActor;
class APhysicsVolume;
class UActorComponent;
class UBaseMovementMode;
class UMovementModeStateMachine;
class UMoverBlackboard;
class UObject;
class UPrimitiveComponent;
class USceneComponent;

// Fired after the actor hits a surface. Param is FMoverOnImpactParams struct that holds all of the data/params for an impact see @FMoverOnImpactParams for more details of it's properties.

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMover_OnImpact, const FMoverOnImpactParams&, ImpactParams);

// Fired after changing movement modes. First param is the name of the previous movement mode. Second is the name of the new movement mode. 

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMover_OnMovementModeChanged, const FName&, PreviousMovementModeName, const FName&, NewMovementModeName);

// Fired after a rollback. First param is the time step we've rolled back to. Second param is when we rolled back from, and represents a later frame that is no longer valid.

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMover_OnPostSimRollback, const FMoverTimeStep&, CurrentTimeStep, const FMoverTimeStep&, ExpungedTimeStep);

// Fired after a simulation tick, regardless of being a re-simulated frame or not.

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMover_OnPostSimTick, const FMoverTimeStep&, TimeStep);

// Fired just before a simulation tick, regardless of being a re-simulated frame or not.

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMover_OnPreSimTick, const FMoverTimeStep&, TimeStep, const FKinematicMoverInputCmdContext&, InputCmd);

/**
 * 
 */
UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class MOVER_API UKinematicMoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mover", meta=(DeterminesOutputType="MovementMode"))
	UBaseMovementMode* FindMovementMode(TSubclassOf<UBaseMovementMode> MovementMode) const;

	// Get the current acceleration due to gravity (cm/s^2) in worldspace

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Mover")
	FVector GetGravityAcceleration() const;

	// Access the most recently-used inputs. Check @HasValidCachedInputCmd first.

	UFUNCTION(BlueprintPure, Category="Mover")
	const FKinematicMoverInputCmdContext& GetLastInputCmd() const;

	// Get the current movement base. Null if there isn't one.

	UFUNCTION(BlueprintPure, Category="Mover")
	UPrimitiveComponent* GetMovementBase() const;

	// Get the current movement base bone, NAME_None if there isn't one.

	UFUNCTION(BlueprintPure, Category="Mover")
	FName GetMovementBaseBoneName() const;

	// Get the intended movement direction in worldspace with magnitude (range 0-1)

	UFUNCTION(BlueprintPure, Category="Mover")
	FVector GetMovementIntent() const;

	// Get the current movement mode name

	UFUNCTION(BlueprintPure, Category="Mover")
	FName GetMovementModeName() const;

	// Access the most recent captured sync state. Check @HasValidCachedState first.

	UFUNCTION(BlueprintPure, Category="Mover")
	const FKinematicMoverSyncState& GetSyncState() const;

	// Get the orientation that the actor is moving towards

	UFUNCTION(BlueprintPure, Category="Mover")
	FRotator GetTargetOrientation() const;

	// Get the normalized direction considered "up" in worldspace. Typically aligned with gravity, and typically determines the plane an actor tries to move along.

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Mover")
	FVector GetUpDirection() const;

	// Get the current velocity (units per second, worldspace)

	UFUNCTION(BlueprintPure, Category="Mover")
	FVector GetVelocity() const;

	/** Handle a blocking impact.*/
	UFUNCTION(BlueprintCallable, Category="Mover")
	void HandleImpact(FMoverOnImpactParams& ImpactParams);

	// Signals whether we have input data saved yet. If not, input queries will not be meaningful.

	UFUNCTION(BlueprintPure, Category="Mover")
	bool HasValidCachedInputCmd() const;

	// Signals whether we have a sync state saved yet. If not, most queries will not be meaningful.

	UFUNCTION(BlueprintPure, Category="Mover")
	bool HasValidCachedState() const;

	// Is this actor in a airborne state? (e.g. Flying, Falling)

	UFUNCTION(BlueprintPure, Category="Mover")
	virtual bool IsAirborne() const;

	// Is this actor in a falling state? Note that this includes upwards motion induced by jumping.

	UFUNCTION(BlueprintPure, Category="Mover")
	virtual bool IsFalling() const;

	// Is this actor in a grounded state? (e.g. Walking)

	UFUNCTION(BlueprintPure, Category="Mover")
	virtual bool IsOnGround() const;

	/**
	 * Queue a layered move to start during the next simulation frame. This will clone whatever move you pass in, so you'll need to fully set it up before queuing.
	 * @param MoveAsRawData			The move to queue, must be a LayeredMoveBase sub-type. 
	 */
	UFUNCTION(CustomThunk, BlueprintCallable, Category="Mover", meta=(AllowAbstract="false", CustomStructureParam="MoveAsRawData", DisplayName="Queue Layered Move"))
	void K2_QueueLayeredMove(const int32& MoveAsRawData);
	DECLARE_FUNCTION(execK2_QueueLayeredMove);

	// Callbacks

	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Queue a movement mode change to occur during the next simulation frame. If bShouldReenter is true, then a mode change will occur even if already in that mode.

	UFUNCTION(BlueprintCallable, Category="Mover")
	void QueueNextMode(FName DesiredModeName, bool bShouldReenter = false);

	// Set gravity override, as a directional acceleration in worldspace.  Gravity on Earth would be {x=0,y=0,z=-980}

	UFUNCTION(BlueprintCallable, Category="Mover", meta=(CPP_Default_GravityAcceleration))
	void SetGravityOverride(bool bOverrideGravity, FVector GravityAcceleration);

	// Access the most recent floor check hit result.

	UFUNCTION(BlueprintPure, Category="Mover")
	bool TryGetFloorCheckHitResult(FHitResult& OutHitResult) const;

	// Broadcast before each simulation tick

	UPROPERTY(BlueprintAssignable, Category="Mover")
	FMover_OnPreSimTick OnPreSimulationTick;

	// Broadcast after each simulation tick

	UPROPERTY(BlueprintAssignable, Category="Mover")
	FMover_OnPostSimTick OnPostSimulationTick;

	// Broadcast when a rollback has occurred, just before the next simulation tick occurs

	UPROPERTY(BlueprintAssignable, Category="Mover")
	FMover_OnPostSimRollback OnPostSimulationRollback;

	// Broadcast when this actor impacts a surface.

	UPROPERTY(BlueprintAssignable, Category="Mover")
	FMover_OnImpact OnImpact;

	// Broadcast when a MovementMode has changed. Happens during a simulation tick if the mode changed that tick or when SetModeImmediately is used to change modes.

	UPROPERTY(BlueprintAssignable, Category="Mover")
	FMover_OnMovementModeChanged OnMovementModeChanged;

	// Specifies which supporting back end class should drive this Mover actor

	UPROPERTY(EditDefaultsOnly, Category="Mover", meta=(MustImplement="/Script/Mover.MoverBackendLiaisonInterface"))
	TSubclassOf<UActorComponent> BackendClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="Mover", meta=(FullyExpand="TRUE"))
	TMap<FName, TObjectPtr<UBaseMovementMode>> MovementModes;

	// Name of the first mode to start in when simulation begins. Must have a mapping in MovementModes. Only used during initialization.

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FName StartingMovementMode;

protected:
	UFUNCTION()
	virtual void PhysicsVolumeChanged(APhysicsVolume* NewVolume);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> UpdatedComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> UpdatedPrimitive;

private:
	/** Collection of settings objects that are shared between movement modes. This list is automatically managed based on the @MovementModes contents. */
	UPROPERTY(EditDefaultsOnly, EditFixedSize, Instanced, Category="Mover", meta=(MustImplement="/Script/Mover.MovementSettingsInterface", NoResetToDefault))
	TArray<TObjectPtr<UObject>> SharedSettings;

	// Whether or not gravity is overridden on this actor. Otherwise, fall back on world settings. See @SetGravityOverride

	UPROPERTY(EditDefaultsOnly, Category="Mover|Gravity")
	bool bHasGravityOverride;

	// cm/s^2, only meaningful if @bHasGravityOverride is enabled. Set @SetGravityOverride

	UPROPERTY(EditDefaultsOnly, Category="Mover|Gravity", meta=(ForceUnits="cm/s^2"))
	FVector GravityAccelOverride;

	UPROPERTY(Transient)
	TObjectPtr<UMovementModeStateMachine> ModeFSM;

	/** Used to store cached data & computations between decoupled systems, that can be referenced by name */
	UPROPERTY(Transient)
	TObjectPtr<UMoverBlackboard> SimBlackboard;

};

