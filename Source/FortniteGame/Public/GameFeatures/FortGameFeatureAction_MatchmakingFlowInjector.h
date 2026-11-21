// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Matchmaking/FortMatchmakingFlowInjection.h"
#include "FortGameFeatureAction_MatchmakingFlowInjector.generated.h"

class UInjectPreMatchmakingFlow;

UCLASS(EditInlineNew)
class UDelMarFlowInjector : public UInjectPreMatchmakingFlow
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, meta=(DisplayName="Matchmaking Flow Injector"))
class UFortGameFeatureAction_MatchmakingFlowInjector : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Experience")
	TSubclassOf<UInjectPreMatchmakingFlow> Experience;

};

UCLASS(EditInlineNew)
class UJunoFlowInjector : public UInjectPreMatchmakingFlow
{
	GENERATED_BODY()

};

