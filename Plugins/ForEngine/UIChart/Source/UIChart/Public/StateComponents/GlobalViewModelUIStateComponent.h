// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Types/MVVMViewModelContext.h"
#include "UIStateChartContext.h"
#include "UIStateComponent.h"
#include "GlobalViewModelUIStateComponent.generated.h"

class UGlobalViewModelUIStateComponentConfiguration;

UCLASS()
class UICHART_API UGlobalViewModelUIStateComponent : public UUIStateComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UGlobalViewModelUIStateComponentConfiguration> Configuration;

	UPROPERTY(Transient)
	TSet<FGameplayTag> ConditionContextKeys;

};

UCLASS()
class UICHART_API UGlobalViewModelUIStateComponentConfiguration : public UUIStateComponentConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GlobalViewModelUIStateComponentConfiguration")
	TArray<FMVVMViewModelContext> ViewModelContexts;

	UPROPERTY(EditAnywhere, Category="GlobalViewModelUIStateComponentConfiguration")
	TArray<FUIStateChartContextCondition> ContextConditions;

};

