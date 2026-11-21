// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBangWrapper_NUI.h"
#include "FortQuestMapNewBangWrapper.generated.h"

class UCommonAnimatedSwitcher;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortQuestMapNewBangWrapper : public UFortBangWrapper_NUI
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_Bangs;

};

