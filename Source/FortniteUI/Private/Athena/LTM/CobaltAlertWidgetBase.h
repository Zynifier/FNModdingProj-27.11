// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltAlertWidgetBase.generated.h"

UCLASS()
class UCobaltAlertWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRoundComplete(const TArray<uint8>& WinningTeams);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTieBreakerUI(bool bHasTieBreaker);

	UFUNCTION()
	void UpdateAlertUI();

	UPROPERTY(Transient)
	uint8 LastViewedTeam;

};

