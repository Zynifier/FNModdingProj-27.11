// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Hover.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Hover : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnGamePhaseStepChanged(const FFortGamePhaseStepUpdatedEvent& Event);

	UPROPERTY(EditDefaultsOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_Intro;

};

