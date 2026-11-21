// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaChallengesWidget.h"
#include "AthenaContextualChallengesWidget.generated.h"

class UFortQuestItem;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaContextualChallengesWidget : public UAthenaChallengesWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetOutroDelay() const;

	UFUNCTION()
	void HandleNewContextualObjectives(const TArray<UFortQuestItem*>& InContextualQuests);

	UFUNCTION()
	void HandleToggleFullscreenMap(bool bFullscreenMapVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewContextualHeader(const FText& NewText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResetOutroDelay();

	UFUNCTION(BlueprintPure)
	bool ShouldOutroAutomatically() const;

};

