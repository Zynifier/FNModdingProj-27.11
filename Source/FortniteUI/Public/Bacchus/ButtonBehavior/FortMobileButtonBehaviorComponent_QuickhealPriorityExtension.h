// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent.h"
#include "Inventory/QuickHeal/QuickHealPriority.h"
#include "FortMobileButtonBehaviorComponent_QuickhealPriorityExtension.generated.h"

UCLASS()
class UFortMobileButtonBehaviorComponent_QuickhealPriorityExtension : public UFortMobileButtonBehaviorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortMobileButtonBehaviorComponent_QuickhealPriorityExtension")
	TArray<FQuickHealPriorityExtension> QuickhealExtensions;

};

