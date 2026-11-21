// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Generators/EnvQueryGenerator_ProjectedPoints.h"
#include "FortQueryGenerator_PointsFromNavGraph.generated.h"

class UEnvQueryContext;

UENUM()
namespace EFortPointsFromNavGraphGoalPathDistanceFilterOperator
{
	enum Type
	{
		AllGoalsInRange = 0 UMETA(Tooltip="All goals must be in range"),
		AnyGoalInRange = 1 UMETA(Tooltip="At least one goal must be in range"),
	};
}

UCLASS(HideCategories=("Generator"), meta=(DisplayName="Points: Using Navigation Graph"))
class UFortQueryGenerator_PointsFromNavGraph : public UEnvQueryGenerator_ProjectedPoints
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GraphGenerator")
	FAIDataProviderFloatValue MinPathDistance;

	UPROPERTY(EditAnywhere, Category="GraphGenerator")
	FAIDataProviderFloatValue MaxPathDistance;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator", meta=(ClampMax="16", ClampMin="1", EditCondition="bLimitExplorationDirection"))
	FAIDataProviderIntValue Density;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator", meta=(EditCondition="bUseParameterizedDirection"))
	FAIDataProviderFloatValue ExploreDirectionYaw;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator", meta=(EditCondition="!bUseParameterizedDirection"))
	FEnvDirection ExploreDirection;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator", meta=(ClampMax="1", ClampMin="-1", EditCondition="bLimitExplorationDirection"))
	float ExploreAngleDot;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator", meta=(EditCondition="bLimitExplorationDirection"))
	FAIDataProviderFloatValue ExploreInnerRadius;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator")
	uint8 bLimitExplorationDirection : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator")
	uint8 bOnlyFlatSurface : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator")
	uint8 bUseParameterizedDirection : 1;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="GraphGenerator")
	uint8 bUseHeightCheck : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphFilter")
	uint8 bFilterAllowTerrain : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphFilter")
	uint8 bFilterAllowBuildings : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphFilter")
	uint8 bFilterAllowDropdown : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphFilter")
	uint8 bFilterAllowClimbup : 1;

	UPROPERTY(EditDefaultsOnly, Category="GraphFilter")
	uint8 bFilterAllowSmash : 1;

	UPROPERTY(EditAnywhere, Category="GraphGenerator")
	TEnumAsByte<EFortPointsFromNavGraphGoalPathDistanceFilterOperator::Type> PathDistanceFilterOperator;

	UPROPERTY(EditDefaultsOnly, Category="GraphGenerator")
	TSubclassOf<UEnvQueryContext> GenerateAround;

};

