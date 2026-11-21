// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_Glide.generated.h"

UENUM(BlueprintType)
enum class EGlideBehavior : uint8
{
	GlideFocusOnDestination = 0,
	GlideSurveyArea = 1,
};

UENUM(BlueprintType)
enum class EGlideMovementType : uint8
{
	GlideMovementLinear = 0,
	GlideMovementSpiral = 1,
	GlideMovementSerpentine = 2,
};

UCLASS()
class UFortAthenaBTTask_Glide : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName GlideDestinationKeyName;

};

