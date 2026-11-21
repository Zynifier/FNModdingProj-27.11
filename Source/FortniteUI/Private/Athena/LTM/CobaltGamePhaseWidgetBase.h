// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "CobaltGamePhaseWidgetBase.generated.h"

class AFortGameState;
enum class EAthenaGamePhaseStep : uint8;

UCLASS()
class UCobaltGamePhaseWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleCountdownUpdate(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnGamePhaseStepChanged(EAthenaGamePhaseStep GamePhaseStep);

	UFUNCTION()
	void OnGameStateSet(AFortGameState* InGameState);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTimeDisplay(bool bSetWarningFont, const FText& NewTimeDisplay);

	UPROPERTY(EditAnywhere, Category="Storm Coming")
	float StormComingWarningTime;

};

