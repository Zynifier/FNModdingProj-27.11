// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BattlePassSubPageInterface.h"
#include "BattlePassLandingPageBase.generated.h"

class UBattlePassLandingPageButton;
class UCommonButtonGroupBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UBattlePassLandingPageBase : public UCommonActivatableWidget, public IBattlePassSubPageInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBattlePassLandingPageButton> LastHoveredPageButton;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> LandingPageButtonGroupBase;

};

