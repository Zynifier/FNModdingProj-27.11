// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAthenaTutorialProgressBar.generated.h"

UCLASS()
class UFortAthenaTutorialProgressBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaTutorialProgressBar(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, Category="PlayAnimation")
	void ResetProgressBarVisuals();

	UFUNCTION(BlueprintImplementableEvent, Category="PlayAnimation")
	void StartNewProgressBarPhase(int32 CurrentPhase);

};

