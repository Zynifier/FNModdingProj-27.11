// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "BattlePassRewardViewBase.generated.h"

USTRUCT()
struct FBattlePassPageData
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UBattlePassRewardViewBase : public UCommonUserWidget
{
	GENERATED_BODY()

};

