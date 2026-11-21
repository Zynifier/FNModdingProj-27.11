// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemTiles/FortItemTileButton.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "FortSquadSlotItemPickerTileButton.generated.h"

enum class EFortSquadSlottingRestrictionReason : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSquadSlotItemPickerTileButton : public UFortItemTileButton
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	TArray<EFortSquadSlottingRestrictionReason> GetSlottingRestrictionReasons() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleItemSlottedToDifferentSquad(const FHomebaseSquadSlotId& SquadSlotId);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleSlottingRestrictionReasonsChanged();

};

