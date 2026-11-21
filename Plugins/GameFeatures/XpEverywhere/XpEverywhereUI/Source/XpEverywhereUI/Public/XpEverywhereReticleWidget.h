// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "XpEverywhereReticleWidget.generated.h"

class USoundCue;
enum class EFortSimulatedXPSize : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UXpEverywhereReticleWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ForwardEvents();

	UFUNCTION()
	void HandleProfileUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRestXP(int32 RestXpRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateXPAmount(int32 NewAmount, USoundCue* Cue, const EFortSimulatedXPSize SimulatedXpSize);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateXPSource(const FText& NewSourceText);

};

