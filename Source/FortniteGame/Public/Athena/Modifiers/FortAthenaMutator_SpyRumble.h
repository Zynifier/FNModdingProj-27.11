// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator_TDM.h"
#include "Athena/Modifiers/Interfaces/InfiltrationRoundInfoMutatorInterface.h"
#include "FortAthenaMutator_SpyRumble.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequiredKillsForPerkUnlockChanged, int32, KillCount);

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpyRumble : public AFortAthenaMutator_TDM, public IInfiltrationRoundInfoMutatorInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat NumKillsForPerkUnlock;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FScalableFloat ScoreToAddOnSupplyDropCollect;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTag SupplyDropAccoladeTag;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Win;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText RoundResultsText_Lost;

	UPROPERTY(ReplicatedUsing=OnRep_NumKillsForNextPerkUnlock)
	int32 NumKillsForNextPerkUnlock;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	int32 KillCountCutOff;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_SupplyDropOpened_Friendly;

	UPROPERTY(EditDefaultsOnly, Category="Game Message")
	FAthenaGameMessageData GameMsg_SupplyDropOpened_Enemy;

private:
	UFUNCTION()
	void OnRep_NumKillsForNextPerkUnlock();

};

