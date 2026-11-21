// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagVisibility.h"
#include "FortMobileButtonBehaviorComponent_BlockedAbilityTagVisibility.generated.h"

class UFortAbilitySystemComponent;

UCLASS()
class UFortMobileButtonBehaviorComponent_BlockedAbilityTagVisibility : public UFortMobileButtonBehaviorComponent_TagVisibility
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

};

