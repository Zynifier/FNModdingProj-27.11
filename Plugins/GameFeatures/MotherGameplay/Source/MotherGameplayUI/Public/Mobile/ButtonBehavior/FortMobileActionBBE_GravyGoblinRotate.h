// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileActionButtonBehaviorExtension.h"
#include "FortMobileActionBBE_GravyGoblinRotate.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortMobileActionBBE_GravyGoblinRotate : public UFortMobileActionButtonBehaviorExtension
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortMobileActionBBE_GravyGoblinRotate")
	FGameplayTag GravyGoblinTag;

};

