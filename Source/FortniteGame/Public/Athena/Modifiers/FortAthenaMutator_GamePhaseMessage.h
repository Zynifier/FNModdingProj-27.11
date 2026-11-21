// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GamePhaseMessage.generated.h"

USTRUCT(BlueprintType)
struct FFortAthenaMutator_GamePhaseMessageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_GamePhaseMessageData")
	bool bSendIfPhaseSkipped;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_GamePhaseMessageData")
	TArray<FAthenaGameMessageData> Messages;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GamePhaseMessage : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_GamePhaseMessage")
	TMap<EAthenaGamePhase, FFortAthenaMutator_GamePhaseMessageData> GamePhaseMessageData;

private:
	UFUNCTION()
	void OnLoadingScreenVisibilityChanged(bool bVisible);

};

