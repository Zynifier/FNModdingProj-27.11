// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortPlayerStateComponent_Habanero.h"
#include "FortHUDElementWidget.h"
#include "AthenaHUDPlayerActionAlertBase.generated.h"

enum class EAthenaPlayerActionAlert : uint8;

UENUM(BlueprintType)
enum class EAthenaPlayerActionAlert : uint8
{
	PlayerDown = 0,
	PlayerKill = 1,
	EnteredStorm = 2,
	NewZebulonDrone = 3,
	NewZebulonDroneYou = 4,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaHUDPlayerActionAlertBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Alerts Cleared"))
	void BP_OnAlertsCleared();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Show Alert"))
	void BP_ShowAlert(EAthenaPlayerActionAlert Alert, const FText& DetailText, const FRankedProgressReplicatedData& RankedProgress);

	UFUNCTION(BlueprintCallable)
	void RequestNextAlert();

	UPROPERTY(EditDefaultsOnly, Category="AthenaHUDPlayerActionAlertBase")
	FGameplayTag HideStormAlertTag;

};

