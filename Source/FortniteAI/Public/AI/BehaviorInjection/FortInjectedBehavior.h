// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortInjectedBehavior.generated.h"

class UBehaviorTree;
class UFortAthenaAIEvaluator;
class UFortInjectedBehavior;

USTRUCT()
struct FFortInjectedBehaviorEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortInjectedBehaviorEntry")
	FGameplayTagContainer InjectionTags;

	UPROPERTY(EditAnywhere, Category="FortInjectedBehaviorEntry")
	FGameplayTagQuery InjectionRequirements;

	UPROPERTY(EditAnywhere, Category="FortInjectedBehaviorEntry")
	TSoftClassPtr<UFortInjectedBehavior> InjectedBehavior;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortInjectedBehavior : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortInjectedBehavior")
	TSubclassOf<UFortAthenaAIEvaluator> AIEvaluator;

	UPROPERTY(EditAnywhere, Category="FortInjectedBehavior", meta=(ClampMin="0.001"))
	float Interval;

	UPROPERTY(EditAnywhere, Category="FortInjectedBehavior", meta=(ClampMin="0.0"))
	float RandomDeviation;

	UPROPERTY(EditAnywhere, Category="Injection Data")
	TObjectPtr<UBehaviorTree> InjectedBehaviorTree;

	UPROPERTY(EditAnywhere, Category="Injection Data")
	uint32 Priority;

};

