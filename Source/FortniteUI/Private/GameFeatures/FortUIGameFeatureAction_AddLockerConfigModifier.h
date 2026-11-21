// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatures/FortUIGameFeatureAction.h"
#include "FortUIGameFeatureAction_AddLockerConfigModifier.generated.h"

class UFortLockerConfigModifier;

UCLASS(MinimalAPI, meta=(DisplayName="Add Locker Config General Modifier"))
class UFortUIGameFeatureAction_AddLockerConfigModifier : public UFortUIGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Config Modifier")
	TObjectPtr<UFortLockerConfigModifier> Modifier;

};

