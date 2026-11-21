// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPopupMenu_Legacy.h"
#include "FortSquadSlotSelectorPopupMenu.generated.h"

class UFortSquadSlotSelectorButton;

UCLASS()
class UFortSquadSlotSelectorPopupMenu : public UFortPopupMenu_Legacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Type Landing Page")
	bool IsScreenWIFE() const;

	UPROPERTY(BlueprintReadWrite, Category="Squad Type Landing Page|Mode")
	bool bReadOnlyModeWIFE;

protected:
	UFUNCTION(BlueprintPure)
	UFortSquadSlotSelectorButton* GetHostButton() const;

};

