// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/Systems/AthenaAIServiceCreativePlayerBots.h"
#include "AthenaAIServicePlayerBots_CreativeRoyale.generated.h"

class AFortPlayerState;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UAthenaAIServicePlayerBots_CreativeRoyale : public UAthenaAIServiceCreativePlayerBots
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPlayerJoiningInProgress(const AFortPlayerState* FortPlayerState);

	UFUNCTION()
	void StartLootClustering();

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIServicePlayerBots_CreativeRoyale")
	FScalableFloat PlayerBotsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIServicePlayerBots_CreativeRoyale")
	FScalableFloat BotsAllowedOnHumanTeam;

	UPROPERTY(EditDefaultsOnly, Category="AthenaAIServicePlayerBots_CreativeRoyale")
	FScalableFloat ForceAllPlayerBotsToOneTeam;

};

