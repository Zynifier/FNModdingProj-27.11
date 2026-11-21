// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortSpectatorRebootWidget.generated.h"

class ABuildingGameplayActorSpawnMachine;
class AFortPlayerStateAthena;
class AFortPlayerStateZone;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSpectatorRebootWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleOnSpectatingTargetChanged(AFortPlayerStateZone* PS);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResurrectionStateChanged();

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSpectatorRebootWidget")
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSpectatorRebootWidget")
	TObjectPtr<AFortPlayerStateAthena> SpectatingTargetPlayerState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortSpectatorRebootWidget")
	TWeakObjectPtr<ABuildingGameplayActorSpawnMachine> CurrentInteractingRebootVan;

};

