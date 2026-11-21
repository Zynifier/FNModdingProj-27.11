// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "VKDebugMessagesBase.generated.h"

class AFortGameState;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UVKDebugMessagesBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Game State", meta=(DisplayName="On GameState Initialized"))
	void BP_OnGameStateInitialized(AFortGameState* GameState);

	UFUNCTION()
	void HandleGameStateInitialized(AFortGameState* GameState);

};

