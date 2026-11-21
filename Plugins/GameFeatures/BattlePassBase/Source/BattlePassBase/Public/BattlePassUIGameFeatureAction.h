// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "BattlePassUIGameFeatureAction.generated.h"

class UBattlePassScreenBase;
class UCommonActivatableWidget;
class UFortGlobalSeasonResourceWidget;

UCLASS(MinimalAPI, meta=(DisplayName="Create Battle Pass"))
class UBattlePassUIGameFeatureAction : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="BattlePassUIGameFeatureAction")
	TSoftClassPtr<UBattlePassScreenBase> BattlePassScreenClass;

	UPROPERTY(EditAnywhere, Category="BattlePassUIGameFeatureAction")
	TSoftClassPtr<UFortGlobalSeasonResourceWidget> BattlePassResourceWidgetClass;

	UPROPERTY(EditAnywhere, Category="BattlePassUIGameFeatureAction")
	TSoftClassPtr<UCommonActivatableWidget> BattlePassInfoModalClass;

};

