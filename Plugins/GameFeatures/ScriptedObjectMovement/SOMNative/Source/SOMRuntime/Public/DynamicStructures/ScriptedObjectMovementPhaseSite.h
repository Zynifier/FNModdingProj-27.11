// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScalableFloat.h"
#include "DynamicStructures/ScriptedObjectMovementDynamicPathContext.h"
#include "DynamicStructures/ScriptedObjectMovementGrid.h"
#include "ScriptedObjectMovementPhaseSite.generated.h"

class AFortScriptedObjectMovement_MovableObjectBase;
class AFortScriptedObjectMovement_Structure;
class UFortScriptedObjectMovement_Slot;

USTRUCT()
struct FFortScriptedObjectMovementPhaseData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="FortScriptedObjectMovementPhaseData")
	TArray<TObjectPtr<AFortScriptedObjectMovement_Structure>> Structures;

};

UCLASS(BlueprintType, Blueprintable)
class AFortScriptedObjectMovement_WorldPhaseSite : public AActor, public IFortScriptedObjectMovement_GridProviderInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, Category="FortScriptedObjectMovement_WorldPhaseSite")
	TArray<FFortScriptedObjectMovementPhaseData> Phases;

	UPROPERTY(EditAnywhere, Category="FortScriptedObjectMovement_WorldPhaseSite")
	FScalableFloat NumSimulatenousMovingObjects;

	UPROPERTY(EditAnywhere, Category="FortScriptedObjectMovement_WorldPhaseSite")
	FScalableFloat PhaseIntervalSeconds;

private:
	UPROPERTY(Transient)
	FScriptedObjectMovement_Grid BaseGrid;

	UPROPERTY(Transient)
	FScriptedObjectMovement_DynamicPathContext InProgressPath;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortScriptedObjectMovement_Slot>> LeavingSlotStack;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortScriptedObjectMovement_Slot>> DestinationSlotStack;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortScriptedObjectMovement_Slot>> OverflowSlotStack;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortScriptedObjectMovement_MovableObjectBase>> CurrentlyMovingObjects;

};

