// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagIconPicker.h"
#include "FortMobileButtonBehaviorComponent_ContextIconPicker.generated.h"

class UFortControllerComponent_InputContextTracker;

UCLASS()
class UFortMobileButtonBehaviorComponent_ContextIconPicker : public UFortMobileButtonBehaviorComponent_TagIconPicker
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_InputContextTracker> ContextTracker;

};

