// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortRestartClientModal.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortRestartClientModal : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonSet(bool InbShouldExit, bool bShouldShow);

};

