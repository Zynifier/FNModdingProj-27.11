// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplaySpectator.h"
#include "FortReplaySpectatorAthena.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTogglePlayPause);

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortReplaySpectatorAthena : public AFortReplaySpectator
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnTogglePlayPause OnTogglePlayPause;

protected:
	UFUNCTION(Exec)
	void SimulateLiveStream(bool bEnable, float UpdateFrequency);

};

