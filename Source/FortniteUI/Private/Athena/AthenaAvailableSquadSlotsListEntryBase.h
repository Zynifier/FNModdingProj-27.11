// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaAvailableSquadSlotsListEntryBase.generated.h"

enum class EAvailableSquadSlotsListEntryState : uint8;

UENUM(BlueprintType)
enum class EAvailableSquadSlotsListEntryState : uint8
{
	/** Entry is displayed with detailed information, usually used on the primary entry of the list at least */
	Detailed = 0,
	/** Entry is displayed in a simplified state with minimal information, usually used on non-primary entries to prevent clutter */
	Simplified = 1,
};

UCLASS(meta=(DisableNativeTick))
class UAthenaAvailableSquadSlotsListEntryBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnEntryStateUpdated(const EAvailableSquadSlotsListEntryState NewEntryState);

	UPROPERTY(BlueprintReadOnly, Category="AthenaAvailableSquadSlotsListEntryBase")
	EAvailableSquadSlotsListEntryState CurrentEntryState;

};

