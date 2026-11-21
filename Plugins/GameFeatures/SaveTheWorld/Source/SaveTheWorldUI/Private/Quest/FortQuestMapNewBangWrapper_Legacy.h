// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBangWrapper_NUI.h"
#include "FortQuestMapNewBangWrapper_Legacy.generated.h"

class UCommonWidgetSwitcherLegacy;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortQuestMapNewBangWrapper_Legacy : public UFortBangWrapper_NUI
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Bangs;

};

