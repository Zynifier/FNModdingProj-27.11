// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortActivityView.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortActivityView : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Local Player Demoted"))
	FORTNITEUI_API void BP_OnLocalPlayerDemoted();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Local Player Promoted To Leader"))
	FORTNITEUI_API void BP_OnLocalPlayerPromotedToLeader();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Party Size Changed"))
	FORTNITEUI_API void BP_OnPartySizeChanged(const int32 PartySize);

};

