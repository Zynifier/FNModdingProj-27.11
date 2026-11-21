// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaSpectatorTeamTagBase.generated.h"

class AFortGameState;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorTeamTagBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateMaxSquadSize(int32 MaxSquadSize);

private:
	UFUNCTION()
	void OnGameStateSet(AFortGameState* InGameState);

};

