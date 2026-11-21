// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_PathExists.generated.h"

class UNavigationQueryFilter;

UENUM()
namespace EPathTestQueryType
{
	enum Type
	{
		/** Really Fast */
		NavmeshRaycast2D = 0,
		/** Fast */
		HierarchicalQuery = 1,
		/** Slow */
		RegularPathFinding = 2,
	};
}

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_PathExists : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	FName GoalKeyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node", meta=(ClampMin="0.0", UIMin="0.0"))
	float AcceptableRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	TSubclassOf<UNavigationQueryFilter> FilterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	TEnumAsByte<EPathTestQueryType::Type> PathQueryType;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Node")
	uint8 bProjectGoalLocation : 1;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bReachTestIncludesAgentRadius : 1;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bReachTestIncludesGoalRadius : 1;

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PathExistsKeyName;

};

