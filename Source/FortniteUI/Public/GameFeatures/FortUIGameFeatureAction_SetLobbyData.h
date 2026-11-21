// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/FrontendLobbyData.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_SetLobbyData.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Set Lobby Data"))
class UFortUIGameFeatureAction_SetLobbyData : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIGameFeatureAction_SetLobbyData")
	FFrontendLobbyData FrontendLobbyData;

};

