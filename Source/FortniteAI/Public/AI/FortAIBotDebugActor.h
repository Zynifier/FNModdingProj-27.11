// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortAIBotDebugActor.generated.h"

class UAthenaAIBotDebugMiniMapIndicator;

UCLASS()
class AFortAIBotDebugActor : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_BotDebugMiniMapIndicator(UAthenaAIBotDebugMiniMapIndicator* OldBotDebugMiniMap);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BotDebugMiniMapIndicator)
	TObjectPtr<UAthenaAIBotDebugMiniMapIndicator> BotDebugMiniMapIndicator;

};

