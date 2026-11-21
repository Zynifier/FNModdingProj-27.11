// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BattlePassSubPageInterface.h"
#include "BattlePassRewardPageBase.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UBattlePassRewardPageBase : public UCommonActivatableWidget, public IBattlePassSubPageInterface
{
	GENERATED_BODY()

};

