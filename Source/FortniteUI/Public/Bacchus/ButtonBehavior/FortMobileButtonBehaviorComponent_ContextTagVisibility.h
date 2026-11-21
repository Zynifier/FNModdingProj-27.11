// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagVisibility.h"
#include "FortMobileButtonBehaviorComponent_ContextTagVisibility.generated.h"

class UFortControllerComponent_InputContextTracker;

UCLASS()
class UFortMobileButtonBehaviorComponent_ContextTagVisibility : public UFortMobileButtonBehaviorComponent_TagVisibility
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_InputContextTracker> ContextTracker;

};

