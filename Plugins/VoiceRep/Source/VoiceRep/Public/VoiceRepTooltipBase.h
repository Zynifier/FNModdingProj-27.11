// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSidebarOnboardTooltipWidget.h"
#include "VoiceRepTooltipBase.generated.h"

UCLASS(Config=Game, meta=(DisableNativeTick))
class VOICEREP_API UVoiceRepTooltipBase : public UFortSidebarOnboardTooltipWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	int32 AutoDismissTimerInterval;

};

