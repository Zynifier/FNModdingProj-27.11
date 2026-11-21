// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UIStateChartContext.h"
#include "UIStateComponent.h"
#include "SceneUIStateComponent.generated.h"

class UDynamicUIScene;
class USceneUIStateComponentConfiguration;

UCLASS()
class UICHART_API USceneUIStateComponent : public UUIStateComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	USceneUIStateComponentConfiguration* Configuration;

	UPROPERTY(Transient)
	TSet<FGameplayTag> ConditionContextKeys;

};

UCLASS()
class UICHART_API USceneUIStateComponentConfiguration : public UUIStateComponentConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Instanced, Category="SceneUIStateComponentConfiguration")
	TObjectPtr<UDynamicUIScene> Scene;

	UPROPERTY(EditAnywhere, Category="SceneUIStateComponentConfiguration")
	TArray<FUIStateChartContextCondition> ContextConditions;

};

