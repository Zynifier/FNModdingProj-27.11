// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCombatTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaRebootChipDirective.generated.h"

class AFortPlayerStateAthena;
class UAthenaPlayerViewModel;
enum class EAthenaSquadListUpdateType : uint8;

UENUM(BlueprintType)
enum class EAthenaSquadListUpdateType : uint8
{
	None = 0,
	CanResurrect = 1,
	FindResurrectChip = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaRebootChipDirective : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleLocalPlayerDied(const FFortPlayerDeathReport& DeathReport);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSquadListDisplay(EAthenaSquadListUpdateType UpdateType, AFortPlayerStateAthena* PS);

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaPlayerViewModel> PlayerVM;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStateAthena>> RebootableAllies;

};

