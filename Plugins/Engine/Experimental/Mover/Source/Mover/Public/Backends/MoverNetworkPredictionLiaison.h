// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkPredictionComponent.h"
#include "Backends/MoverBackendLiaison.h"
#include "MoverNetworkPredictionLiaison.generated.h"

/**
 * MoverNetworkPredictionLiaisonComponent: this component acts as a middleman between an actor's Mover component and the Network Prediction plugin.
 * This class is set on a Mover component as the "back end".
 */
UCLASS()
class MOVER_API UMoverNetworkPredictionLiaisonComponent : public UNetworkPredictionComponent, public IMoverBackendLiaisonInterface
{
	GENERATED_BODY()

};

