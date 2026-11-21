// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileHudWidgetContentComponent.h"
#include "FortMobileHUDWidgetContentComponent_RadialIndicator.generated.h"

class UBacchusRadialDisplayBase;
class UUserWidget;

UCLASS()
class UFortMobileHUDWidgetContentComponent_RadialIndicator : public UFortMobileHudWidgetContentComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="RadialIndicator")
	TSoftClassPtr<UUserWidget> RadialIndicatorSoftClass;

	UPROPERTY(EditDefaultsOnly, Category="RadialIndicator")
	FGameplayTag TrackedGameplayCueTag;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBacchusRadialDisplayBase> CurrentRadialIndicatorWidget;

};

