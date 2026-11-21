// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoverBasePawn.generated.h"

class UKinematicMoverComponent;

UCLASS(HideCategories=("Navigation"))
class MOVER_API AMoverBasePawn : public APawn
{
	GENERATED_BODY()

public:
	/** Accessor for the actor's movement component */
	UFUNCTION(BlueprintPure, Category="Mover")
	UKinematicMoverComponent* GetMoverComponent() const;

protected:
	// Implement this event in Blueprints to author input for the next simulation frame. Consider also calling Parent event.

	UFUNCTION(BlueprintImplementableEvent, Category="Mover", meta=(DisplayName="On Produce Input", ScriptName="OnProduceInput"))
	FKinematicMoverInputCmdContext OnProduceInputInBlueprint(float DeltaMs, FKinematicMoverInputCmdContext InputCmd);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Movement", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UKinematicMoverComponent> CharacterMotionComponent;

};

