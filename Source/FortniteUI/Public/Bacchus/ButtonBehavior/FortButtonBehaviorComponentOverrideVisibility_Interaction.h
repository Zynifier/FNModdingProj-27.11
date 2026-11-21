// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortButtonBehaviorComponentOverride.h"
#include "FortButtonBehaviorComponentOverrideVisibility_Interaction.generated.h"

class UFortControllerComponent_Interaction;

UCLASS()
class UFortButtonBehaviorComponentOverrideVisibility_Interaction : public UFortButtonBehaviorComponentOverride
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortControllerComponent_Interaction* InteractionComponent;

};

