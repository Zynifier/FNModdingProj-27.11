// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_GoalActorDot.generated.h"

class UEnvQueryContext;

UENUM(BlueprintType)
enum class EFortTestGoalActorDot : uint8
{
	Dot3D = 0 UMETA(DisplayName="Goal Actor Dot (3D)", Tooltip="Fully 3D dot-product using the Goal Actor as the start location of both direction vectors."),
	Dot2D = 1 UMETA(DisplayName="Goal Actor Dot 2D (Heading)", Tooltip="Dot Product in the XY-plane, which is equivalent to the cosine of the heading or yaw angle.  Uses the Goal Actor as the start location of both direction vectors."),
};

UCLASS()
class UFortQueryTest_GoalActorDot : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Direction", meta=(DisplayName="Line A To"))
	TSubclassOf<UEnvQueryContext> LineATo;

	UPROPERTY(EditDefaultsOnly, Category="Direction", meta=(DisplayName="Line B To"))
	TSubclassOf<UEnvQueryContext> LineBTo;

	UPROPERTY(EditDefaultsOnly, Category="Dot")
	EFortTestGoalActorDot TestMode;

	UPROPERTY(EditDefaultsOnly, Category="Dot")
	bool bAbsoluteValue;

};

