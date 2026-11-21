// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagIconPicker.h"
#include "FortMobileButtonBehaviorComponent_AbilityIconPicker.generated.h"

class UAbilitySystemComponent;

UCLASS()
class UFortMobileButtonBehaviorComponent_AbilityIconPicker : public UFortMobileButtonBehaviorComponent_TagIconPicker
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

};

