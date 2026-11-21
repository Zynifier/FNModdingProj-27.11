// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "LayeredMove.h"
#include "MoverTypes.h"
#include "MoverDataModelTypes.generated.h"

class UPrimitiveComponent;

// Used to identify how to interpret a movement input vector's values

UENUM()
enum class EMoveInputType : uint8
{
	Invalid = 0,
	DirectionalIntent = 1,
	// Move with intent, as a per-axis magnitude [-1,1] (E.g., "move straight forward as fast as possible" would be (1, 0, 0) and "move straight left at half speed" would be (0, -0.5, 0) regardless of frame time). Zero vector indicates intent to stop.

	Velocity = 2,
};

// Data block containing all inputs that need to be authored and consumed for the kinematic Mover simulation

USTRUCT(BlueprintType)
struct MOVER_API FKinematicDefaultInputs : public FMoverDataStructBase
{
	GENERATED_BODY()

public:
	// Facing direction intent, as a normalized forward-facing direction. A zero vector indicates no intent to change facing direction. Relative to MovementBase if set, world space otherwise.

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FVector OrientationIntent;

	// World space orientation that the controls were based on. This is commonly a player's camera rotation.

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FRotator ControlRotation;

	// Used to force the Mover actor into a different movement mode

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FName SuggestedMovementMode;

	// Specifies whether we are using a movement base, which will affect how move inputs are interpreted

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	bool bUsingMovementBase;

	// Optional: when moving on a base, input may be relative to this object

	UPROPERTY(BlueprintReadOnly, Export, Category="Mover", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> MovementBase;

	// Optional: for movement bases that are skeletal meshes, this is the bone we're based on. Only valid if MovementBase is set.

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FName MovementBaseBoneName;

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	bool bIsJumpJustPressed;

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	bool bIsJumpPressed;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Mover")
	EMoveInputType MoveInputType;

	// Representing the directional move input for this frame. Must be interpreted according to MoveInputType. Relative to MovementBase if set, world space otherwise. Will be truncated to match network serialization precision.

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FVector MoveInput;

};

// Data block containing basic sync state information

USTRUCT(BlueprintType)
struct MOVER_API FMoverDefaultSyncState : public FMoverDataStructBase
{
	GENERATED_BODY()

public:
	// Movement intent direction relative to MovementBase if set, world space otherwise. Magnitude of range (0-1)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FVector MoveDirectionIntent;

	// The mode we ended up in from the prior frame, and which we'll start in during the next frame

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FName MovementMode;

	// Additional moves influencing our proposed motion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FLayeredMoveGroup LayeredMoves;

protected:
	// Position relative to MovementBase if set, world space otherwise

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FVector Location;

	// Forward-facing rotation relative to MovementBase if set, world space otherwise.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FRotator Orientation;

	// Linear velocity, units per second, relative to MovementBase if set, world space otherwise.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FVector Velocity;

	// Optional: when moving on a base, input may be relative to this object

	UPROPERTY(BlueprintReadOnly, Export, Category="Mover", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> MovementBase;

	// Optional: for movement bases that are skeletal meshes, this is the bone we're based on. Only valid if MovementBase is set.

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FName MovementBaseBoneName;

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FVector MovementBasePos;

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FQuat MovementBaseQuat;

};

/**
 * Blueprint function library to make it easier to work with Mover data structs, since we can't add UFUNCTIONs to structs
 */
UCLASS()
class MOVER_API UMoverDataModelBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** Returns the location in world space */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector GetLocationFromSyncState(const FMoverDefaultSyncState& SyncState);

	/** Returns the move direction intent, if any, in world space */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector GetMoveDirectionIntentFromInputs(const FKinematicDefaultInputs& Inputs);

	/** Returns the move direction intent, if any, in world space */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector GetMoveDirectionIntentFromSyncState(const FMoverDefaultSyncState& SyncState);

	/** Returns the orientation in world space */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FRotator GetOrientationFromSyncState(const FMoverDefaultSyncState& SyncState);

	/** Returns the velocity in world space */
	UFUNCTION(BlueprintCallable, Category="Mover")
	static FVector GetVelocityFromSyncState(const FMoverDefaultSyncState& SyncState);

};

