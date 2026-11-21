// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Curie/Elements/FortCurieFireTypes.h"
#include "Curie/FortCurieManagerComponent.h"
#include "Curie/FortCurieManagerComponentSpatialInterface.h"
#include "CurieManagerComponent.h"
#include "FortCurieFirePropagationManager.generated.h"

class UFortCurieFirePropagationManagerConfig;

USTRUCT()
struct FFortCurieFirePropagationManagerTickFunction : public FTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FFortCurieFirePropagationManagerTickFunction> : public TStructOpsTypeTraitsBase2<FFortCurieFirePropagationManagerTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

UCLASS(MinimalAPI)
class UFortCurieFirePropagationManager : public UFortCurieManagerComponent, public IFortCurieFirePropagationManagerInterface, public IFortCurieManagerComponentSpatialInterface
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FFortCurieFirePropagationManagerTickFunction PrimaryTickFunction;

	UPROPERTY(Transient)
	TObjectPtr<UFortCurieFirePropagationManagerConfig> InternalManagerConfig;

};

UCLASS(MinimalAPI)
class UFortCurieFirePropagationManagerConfig : public UCurieManagerComponentConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float TickInterval;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float FirePropagationDelay;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float MinPropagationFuel;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float DefaultPropagationFuel;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float MaxPropagationFuel;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float DefaultPropagationFuelCost;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float IncompletePropagationRefundFuelMultiplier;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float InactiveFireFailsafeRemovalTime;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float MaximumPendingInteractTimePerTick;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float PropagationApplicationMagnitude;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float HalfAngleForUpwardMobilityCalculation;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	int32 PropagationLimit;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	int32 ForcedNeighborPropagationLimitPerTick;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(DisplayAfter="MaximumPendingInteractTimePerTick", Patchable))
	int32 MinimumPendingInteractsToProcessPerTick;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	int32 DefaultConnectivityPoints;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	FScalableFloat PropagationRate;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	FVector2D PropagationApplicationMagnitudeRandomizationRange;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	FVector DefaultFireBoundsExpansion;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(DisplayAfter="MaxPropagationFuel", Patchable))
	bool bAllowPropagationFuelOverrides;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float FireElementSubgridOverlapThreshold;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float BuildingFirePropagationTickInterval;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassFirePropagationInterval;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassFireBurnoutInterval;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassFireInitialPropagationDelay;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassFireMinPropagationDelay;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassFireMaxPropagationDelay;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassFireBurnoutTime;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassMaxWaterContent;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassWaterContentChangeOnFireApplication;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassWaterContentChangeOnWaterApplication;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassFirePropagationCostPerLocation;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float GrassTraceLandscapeOffset;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	float FireFoundationGrassDefaultExpansion;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	int32 GrassFirePropagationRate;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	int32 GrassGridCellsPerAxisManagedByGrassFireReplicator;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	int32 GrassGridFireMinimumTraceOptimization;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	int32 GrassFirePropagationFuelConsumptionLimit;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float FireLandscapePropagationApplicationMagnitude;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(Patchable))
	float OverlapFireApplicationMagnitude;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(EditCondition="bCreateFireInteractsForMovableActors", Patchable))
	float MovableActorFireInteractionMagnitude;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	bool bUseLandscapeMapForGrassGrid;

	UPROPERTY(EditAnywhere, Category="GrassGrid", meta=(Patchable))
	bool bUseIFACacheForGrassGrid;

	UPROPERTY(EditAnywhere, Category="Interacts", meta=(Patchable))
	bool bAllowInteractsWhileDBNO;

	UPROPERTY(EditAnywhere, Category="Interacts", meta=(Patchable))
	bool bAllowInteractsWhileInVehicle;

	UPROPERTY(EditAnywhere, Category="FortCurieFirePropagationManagerConfig", meta=(DisplayAfter="StormFireInteractionMagnitude", Patchable))
	bool bCreateFireInteractsForMovableActors;

};

