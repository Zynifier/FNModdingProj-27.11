// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagIconPicker.h"
#include "FortMobileButtonBehaviorComponent_InteractionIconPicker.generated.h"

class UFortControllerComponent_Interaction;

UCLASS()
class UFortMobileButtonBehaviorComponent_InteractionIconPicker : public UFortMobileButtonBehaviorComponent_TagIconPicker
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Interaction> InteractionComponent;

};

