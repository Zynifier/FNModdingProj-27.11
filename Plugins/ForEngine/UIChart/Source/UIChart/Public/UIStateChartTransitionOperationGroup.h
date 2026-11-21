// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartContext.h"
#include "UIStateChartTransitionOperationParameters.h"
#include "UIStateChartTransitionOperationGroup.generated.h"

class ULocalPlayer;
class UUIStateChartContext;
class UUIStateChartTransitionOperation;

UCLASS()
class UICHART_API UUIStateChartTransitionOperationGroup : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSet<UUIStateChartTransitionOperation*> Operations;

	UPROPERTY(Transient)
	TSet<UUIStateChartTransitionOperation*> OperationsReadyForContextUpdate;

	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartContext> Context;

	UPROPERTY(Transient)
	TObjectPtr<ULocalPlayer> LocalPlayer;

	UPROPERTY(Transient)
	FUIStateChartContextChangeSet ContextChanges;

	UPROPERTY(Transient)
	FUIStateChartContextChangeSet ReverseContextChanges;

	UPROPERTY(Transient)
	FUIStateChartTransitionOperationParameters Parameters;

	UPROPERTY(Transient)
	FGameplayTag TransitionEventTag;

};

