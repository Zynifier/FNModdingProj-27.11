// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/ButtonBehavior/FortMobileHudWidgetContentComponent.h"
#include "FortMobileHudWidgetContentComponent_RadialCooldown.generated.h"

class URadialBacchusButtonBase;
class UUserWidget;

UCLASS()
class UFortMobileHudWidgetContentComponent_RadialCooldown : public UFortMobileHudWidgetContentComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="RadialCooldown")
	TSoftClassPtr<UUserWidget> RadialCooldownSoftClass;

	UPROPERTY(EditDefaultsOnly, Category="RadialCooldown")
	FGameplayTag GameplayTagToListen;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URadialBacchusButtonBase> CurrentRadialCooldownWidget;

};

