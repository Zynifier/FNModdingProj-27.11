// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameplayTagContainer.h"
#include "FortGameFeatureAction_InjectAIEvaluators.generated.h"

class UBehaviorTree;
class UFortAthenaAIEvaluator;

USTRUCT()
struct FGameFeatureFortAIEvaluatorEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AI Evaluator")
	TSoftObjectPtr<UBehaviorTree> TreeAsset;

	UPROPERTY(EditAnywhere, Category="AI Evaluator")
	FGameplayTag InjectionTag;

	UPROPERTY(EditAnywhere, Category="AI Evaluator", meta=(AssetBundles="Server"))
	TSoftClassPtr<UFortAthenaAIEvaluator> AIEvaluatorClass;

};

UCLASS(MinimalAPI, meta=(DisplayName="Inject AI Evaluators"))
class UFortGameFeatureAction_InjectAIEvaluators : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AI Evaluators")
	TArray<FGameFeatureFortAIEvaluatorEntry> AIEvaluatorList;

};

