// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAthenaTutorialTargetCounter.generated.h"

UCLASS()
class UFortAthenaTutorialTargetCounter : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaTutorialTargetCounter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, Category="PlayAnimation")
	void ResetCounterVisuals();

	UFUNCTION(BlueprintImplementableEvent, Category="PlayAnimation")
	void UpdateTargetCounterVisuals(int32 NumberOfTargets);

};

