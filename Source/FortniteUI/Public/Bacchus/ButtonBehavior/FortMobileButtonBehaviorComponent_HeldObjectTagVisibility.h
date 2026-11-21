// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagVisibility.h"
#include "FortMobileButtonBehaviorComponent_HeldObjectTagVisibility.generated.h"

class UAbilitySystemComponent;

UCLASS()
class UFortMobileButtonBehaviorComponent_HeldObjectTagVisibility : public UFortMobileButtonBehaviorComponent_TagVisibility
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> AbilityComponent;

};

