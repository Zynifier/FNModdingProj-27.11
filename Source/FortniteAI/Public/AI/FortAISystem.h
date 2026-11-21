// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AISystem.h"
#include "Math/MathFwd.h"
#include "FortAISystem.generated.h"

class UAthenaAIServiceManager;
class UAthenaAISpawner;
class UFortBotMissionManager;
class UFortInfluenceMap;
class UFortQueryTwoPointSolver;
class UFortRiftBlockerComponent;

UCLASS(MinimalAPI)
class UFortAISystem : public UAISystem
{
	GENERATED_BODY()

public:
	UFortAISystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="AI")
	static bool IsInCone2D(FVector ConeOrigin, FVector ConeDirection, float HalfAngle, FVector LocationToCheck);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQueryTwoPointSolver>> TwoPointSolvers;

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortInfluenceMap> InfluenceMap;

	UPROPERTY(Transient)
	TObjectPtr<UFortBotMissionManager> BotManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortRiftBlockerComponent>> ActiveRiftBlockers;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAISpawner> AISpawner;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIServiceManager> AIServiceManager;

};

