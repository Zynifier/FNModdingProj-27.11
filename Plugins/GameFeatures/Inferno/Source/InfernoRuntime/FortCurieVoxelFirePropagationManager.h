// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/EngineBaseTypes.h"
#include "Curie/Elements/FortCurieFireTypes.h"
#include "Curie/FortCurieManagerComponent.h"
#include "Curie/FortCurieManagerComponentSpatialInterface.h"
#include "Curie/Managers/FortCurieFirePropagationManager.h"
#include "FortCurieVoxelFirePropagationManager.generated.h"

class UFortCurieVoxelFirePropagationManagerConfig;

USTRUCT()
struct FFortCurieVoxelFirePropagationManagerTickFunction : public FTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FFortCurieVoxelFirePropagationManagerTickFunction> : public TStructOpsTypeTraitsBase2<FFortCurieVoxelFirePropagationManagerTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

USTRUCT()
struct FFortCurieVoxelPropagationProperties : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCurieVoxelPropagationProperties")
	float PropagationZDirectionDownMultiplier;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelPropagationProperties")
	float PropagationZDirectionUpMultiplier;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelPropagationProperties")
	float PropagationBaseDelay;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelPropagationProperties", meta=(ClampMin="32.0", UIMin="32.0"))
	float PropagationBaseSpeed;

};

UCLASS()
class UFortCurieVoxelFirePropagationManager : public UFortCurieManagerComponent, public IFortCurieFirePropagationManagerInterface, public IFortCurieManagerComponentSpatialInterface
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FFortCurieVoxelFirePropagationManagerTickFunction PrimaryTickFunction;

	UPROPERTY(Transient)
	TObjectPtr<UFortCurieVoxelFirePropagationManagerConfig> InternalManagerConfig;

};

UCLASS()
class UFortCurieVoxelFirePropagationManagerConfig : public UFortCurieFirePropagationManagerConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	FFortCurieVoxelPropagationProperties DefaultPropagationProperties;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	FName PropagationPropertiesRegistry;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	float PropagationNoiseMinimum;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	float PropagationNoiseMaximum;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(ClampMin="0.0", Patchable, UIMin="0.0"))
	float PropagationSpeedNoiseRange;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(ClampMin="1.0", Patchable, UIMin="1.0"))
	float PropagationMinimumSpeed;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(ClampMin="0.1", Patchable, UIMin="0.1"))
	float PropagationMinimumTime;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	float VoxelOverlapExpansionFactor;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	bool bAllowPerMaterialPropagationProperties;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	float ActorPropagationInteractMagnitude;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	float MovedActorGrassIgnitionDelay;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	float MovedActorGrassGridCellZExpansion;

	UPROPERTY(EditAnywhere, Category="FortCurieVoxelFirePropagationManagerConfig", meta=(Patchable))
	float MovedActorGroundTraceZRange;

};

