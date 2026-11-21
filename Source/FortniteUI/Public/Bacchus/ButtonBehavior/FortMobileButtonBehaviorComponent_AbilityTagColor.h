// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_Color.h"
#include "FortMobileButtonBehaviorComponent_AbilityTagColor.generated.h"

class UAbilitySystemComponent;

UCLASS()
class UFortMobileButtonBehaviorComponent_AbilityTagColor : public UFortMobileButtonBehaviorComponent_Color
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FTagColor> ColorOverrides;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

};

