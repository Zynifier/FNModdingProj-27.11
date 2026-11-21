// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_MovementData.generated.h"

class UFortMovementControls;

UCLASS(MinimalAPI, meta=(DisplayName="Movement Data"))
class UFortGameFeatureAction_MovementData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Movement Data")
	TArray<TObjectPtr<UFortMovementControls>> GameFeatureMovementControls;

};

