// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialProfilePanel.h"
#include "FortSocialProfileRebootRallyText.generated.h"

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfileRebootRallyText : public UFortSocialProfileSubPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsLocalUser() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayText(const bool bRallied);

};

