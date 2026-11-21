// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/HUD/Feedback/AthenaHUDFeedbackLine.h"
#include "AthenaHUDFeedbackLineCooldown.generated.h"

class AActor;
class AFortPlayerController;

UCLASS()
class FORTNITEUI_API UAthenaHUDFeedbackLineCooldown : public UAthenaHUDFeedbackLine
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCooldownFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCooldownStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCooldownUpdated(float CooldownDuration, float CooldownRemaining, float CooldownPercentage);

private:
	UFUNCTION()
	void OnCooldownTagChanged(const FGameplayTag CooldownTag, int32 Count);

	UFUNCTION()
	void RegisterAbilityNotify(AFortPlayerController* PlayerController, AActor* OldViewTarget, AActor* NewViewTarget);

};

