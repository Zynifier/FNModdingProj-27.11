// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehaviorExtension.h"
#include "FortMobileActionButtonBehaviorExtension_ScoutDroneUse.generated.h"

UCLASS()
class UFortMobileActionButtonBehaviorExtension_ScoutDroneUse : public UFortMobileActionButtonBehaviorExtension
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionButtonBehaviorExtension_ScoutDroneUse")
	FGameplayTagContainer ContextTagToCheck;

};

