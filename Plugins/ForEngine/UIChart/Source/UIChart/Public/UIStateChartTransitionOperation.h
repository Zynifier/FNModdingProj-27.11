// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateRelay.h"
#include "UIStateChartTransitionOperation.generated.h"

class UUIState;
class UUIStateChartRegion;
class UUIStateChartTransitionOperationGroup;

UCLASS()
class UICHART_API UUIStateChartTransitionOperation : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartRegion> Region;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> OriginState;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> EndState;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> TransitionTargetState;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UUIState*> KnownStatesToActivate;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UUIState*> StatesToDeactivate;

	UPROPERTY(Transient)
	UUIStateChartTransitionOperationGroup* Group;

	UPROPERTY()
	FUIStateRelay StateRelay;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> BacktrackReturnState;

};

