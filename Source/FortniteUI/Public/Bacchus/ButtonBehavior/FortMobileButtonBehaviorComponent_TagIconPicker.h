// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_IconPicker.h"
#include "FortMobileButtonBehaviorComponent_TagIconPicker.generated.h"

UCLASS(Abstract)
class UFortMobileButtonBehaviorComponent_TagIconPicker : public UFortMobileButtonBehaviorComponent_IconPicker
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FIconPicker> SpriteOverrides;

};

