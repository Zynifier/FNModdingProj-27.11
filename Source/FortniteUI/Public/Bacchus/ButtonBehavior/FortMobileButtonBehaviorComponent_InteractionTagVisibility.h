// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_TagVisibility.h"
#include "FortMobileButtonBehaviorComponent_InteractionTagVisibility.generated.h"

class UFortControllerComponent_Interaction;

UCLASS()
class UFortMobileButtonBehaviorComponent_InteractionTagVisibility : public UFortMobileButtonBehaviorComponent_TagVisibility
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_Interaction> InteractionComponent;

};

