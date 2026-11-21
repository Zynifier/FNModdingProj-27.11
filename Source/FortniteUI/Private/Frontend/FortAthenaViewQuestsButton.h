// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortAthenaViewQuestsButton.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAthenaViewQuestsButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleUnseenQuestsChanged(bool bHasUnseenQuests);

	UFUNCTION(BlueprintPure)
	bool HasUnseenQuests() const;

private:
	UFUNCTION()
	void HandleToggleFullscreenMap(bool bVisible);

};

