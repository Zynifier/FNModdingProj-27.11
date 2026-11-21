// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UIStateChart.generated.h"

class UUIStateConfiguration;

USTRUCT()
struct UICHART_API FUIStateTransitionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="UIStateTransitionData", meta=(Categories="UI.Chart.TransitionTag"))
	FGameplayTag TriggerTag;

	UPROPERTY(EditAnywhere, Category="UIStateTransitionData")
	int32 SourceStateId;

	UPROPERTY(EditAnywhere, Category="UIStateTransitionData")
	int32 TargetStateId;

};

UCLASS(BlueprintType)
class UICHART_API UUIStateChart : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Instanced, Category="StateChart")
	TObjectPtr<UUIStateConfiguration> RootState;

	UPROPERTY(EditAnywhere, Category="StateChart")
	TArray<FUIStateTransitionData> Transitions;

};

