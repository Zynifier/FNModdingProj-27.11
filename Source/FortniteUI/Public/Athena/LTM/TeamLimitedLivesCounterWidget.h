// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPlayerInfoBaseWidgetInterface.h"
#include "Athena/LTM/LimitedLivesCounterWidget.h"
#include "TeamLimitedLivesCounterWidget.generated.h"

UCLASS(meta=(DisableNativeTick))
class UTeamLimitedLivesCounterWidget : public ULimitedLivesCounterWidget, public IAthenaPlayerInfoBaseWidgetInterface
{
	GENERATED_BODY()

};

