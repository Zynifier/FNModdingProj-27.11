// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_Visibility.h"
#include "FortMobileButtonBehaviorComponent_TagVisibility.generated.h"

UCLASS(Abstract)
class FORTNITEUI_API UFortMobileButtonBehaviorComponent_TagVisibility : public UFortMobileButtonBehaviorComponent_Visibility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="HUD Visibility")
	TArray<FTagVisibility> TagVisibilities;

};

