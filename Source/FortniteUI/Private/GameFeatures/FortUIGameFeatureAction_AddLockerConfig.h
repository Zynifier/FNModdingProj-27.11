// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddLockerConfig.generated.h"

class UFortLockerConfig;

UCLASS(MinimalAPI, meta=(DisplayName="Add Locker Config General Override"))
class UFortUIGameFeatureAction_AddLockerConfig : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config Override")
	TObjectPtr<UFortLockerConfig> LockerConfig;

};

