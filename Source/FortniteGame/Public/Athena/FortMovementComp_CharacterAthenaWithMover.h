// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Athena/FortMovementComp_CharacterAthena.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "MoverTypes.h"
#include "FortMovementComp_CharacterAthenaWithMover.generated.h"

class UKinematicMoverComponent;

UCLASS(MinimalAPI)
class UFortMovementComp_CharacterAthenaWithMover : public UFortMovementComp_CharacterAthena
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MoverCompatibility")
	TMap<FName, TEnumAsByte<EMovementMode>> MoverMovementModeToCharacterMovementMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MoverCompatibility")
	TMap<FName, TEnumAsByte<EFortCustomMovement::Type>> MoverMovementModeToCharacterCustomMovementMode;

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UKinematicMoverComponent> MoverComponent;

private:
	UFUNCTION()
	void OnMoverPostSimulationTick(const FMoverTimeStep& TimeStep);

	UFUNCTION()
	void OnMoverPreSimulationTick(const FMoverTimeStep& TimeStep, const FKinematicMoverInputCmdContext& InputCmd);

};

