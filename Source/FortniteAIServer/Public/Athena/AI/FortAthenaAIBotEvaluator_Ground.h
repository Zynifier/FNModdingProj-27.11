// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Ground.generated.h"

class UFortAthenaAIRuntimeParameters_Behavior;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Ground : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="SurfaceType", meta=(AllowPrivateAccess="true"))
	FVector SurfaceTypeRaycastDir;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_Behavior> CachedBehaviorRuntimeParameters;

};

