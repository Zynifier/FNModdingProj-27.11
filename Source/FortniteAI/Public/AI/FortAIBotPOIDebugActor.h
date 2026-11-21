// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortAIBotPOIDebugActor.generated.h"

class UAthenaAIBotPOIDebugMiniMapIndicator;

UCLASS()
class AFortAIBotPOIDebugActor : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_PlayerBotsDebugMiniMap(UAthenaAIBotPOIDebugMiniMapIndicator* OldPlayerBotsDebugMiniMap);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerBotsDebugMiniMap)
	TObjectPtr<UAthenaAIBotPOIDebugMiniMapIndicator> BotPOIDebugMiniMapIndicator;

};

