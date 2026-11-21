// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "MoverTypes.h"
#include "MovementMode.generated.h"

class UKinematicMoverComponent;
class UMoverBlackboard;
class UObject;
class UPrimitiveComponent;
class USceneComponent;

// Input parameters for SimulationTick functions

USTRUCT(BlueprintType)
struct MOVER_API FSimulationTickParams
{
	GENERATED_BODY()

public:
	// The scene component that is being moved by the simulation, usually the same as the primitive component

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Mover", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> UpdatedComponent;

	// The primitive component used for collision checking by the simulation, usually the same as UpdatedComponent

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Mover", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> UpdatedPrimitive;

	// Simulation state data at the start of the tick, including Input Cmd

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FKinematicMoverTickStartData StartState;

	// Time and frame information for this tick

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FMoverTimeStep TimeStep;

	// Proposed movement for this tick

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mover")
	FProposedMove ProposedMove;

};

/**
 * Base class for all movement modes, exposing simulation update methods for both C++ and blueprint extension
 */
UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class MOVER_API UBaseMovementMode : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mover", meta=(DisplayName="Get Blackboard"))
	const UMoverBlackboard* GetBlackboard() const;

	UFUNCTION(BlueprintPure, Category="Mover", meta=(DisplayName="Get Blackboard"))
	UMoverBlackboard* GetBlackboard_Mutable() const;

	UFUNCTION(BlueprintPure, Category="Mover", meta=(DisplayName="Get Mover Component"))
	UKinematicMoverComponent* GetMoverComponent() const;

	/** Settings object type that this mode depends on. May be shared with other movement modes. When the mode is added to a Mover Component, it will create a shared instance of this settings class. */
	UPROPERTY(EditDefaultsOnly, Category="Mover", meta=(MustImplement="/Script/Mover.MovementSettingsInterface"))
	TSubclassOf<UObject> SharedSettingsClass;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnGenerateMove", ScriptName="OnGenerateMove"))
	FProposedMove K2_OnGenerateMove(const FKinematicMoverTickStartData& StartState, const FMoverTimeStep& TimeStep) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnRegistered", ScriptName="OnRegistered"))
	void K2_OnRegistered(const FName ModeName);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnSimulationTick", ScriptName="OnSimulationTick"))
	FKinematicMoverTickEndData K2_OnSimulationTick(const FSimulationTickParams& Params);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnUnregistered", ScriptName="OnUnregistered"))
	void K2_OnUnregistered();

};

UINTERFACE(MinimalAPI, BlueprintType)
class UMovementSettingsInterface : public UInterface
{
	GENERATED_BODY()
};

class IMovementSettingsInterface
{
	GENERATED_BODY()

};

