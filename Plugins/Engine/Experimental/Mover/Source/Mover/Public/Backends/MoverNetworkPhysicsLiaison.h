// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Physics/NetworkPhysicsComponent.h"
#include "Backends/MoverBackendLiaison.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoverNetworkPhysicsLiaison.generated.h"

//////////////////////////////////////////////////////////////////////////
// Physics networking

USTRUCT()
struct MOVER_API FNetworkPhysicsMoverInputs : public FNetworkPhysicsDatas
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FKinematicMoverInputCmdContext InputCmdContext;

};

USTRUCT()
struct MOVER_API FNetworkPhysicsMoverState : public FNetworkPhysicsDatas
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FKinematicMoverSyncState SyncStateContext;

	UPROPERTY()
	FKinematicMoverAuxStateContext AuxStateContext;

};

/**
 * MoverPhysicsLiaisonComponent: This component acts as a middleman between an actor's Mover component and the chaos physics network prediction system.
 * This class is set on a Mover component as the "back end".
 */
UCLASS()
class MOVER_API UMoverNetworkPhysicsLiaisonComponent : public UActorComponent, public IMoverBackendLiaisonInterface
{
	GENERATED_BODY()

};

