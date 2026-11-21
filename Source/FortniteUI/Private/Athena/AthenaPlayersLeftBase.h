// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaPlayersLeftBase.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaPlayersLeftBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetBotsLeftText(const FText& BotsText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetHumansLeftText(const FText& HumansText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetPlayersLeftText(const FText& PlayersText);

	UFUNCTION()
	virtual void UpdatePlayersLeft();

};

