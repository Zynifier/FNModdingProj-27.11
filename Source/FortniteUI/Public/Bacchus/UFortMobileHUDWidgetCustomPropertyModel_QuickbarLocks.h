// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/FortMobileHUDWidgetCustomPropertyModel_Number.h"
#include "UFortMobileHUDWidgetCustomPropertyModel_QuickbarLocks.generated.h"

UCLASS()
class UUFortMobileHUDWidgetCustomPropertyModel_QuickbarLocks : public UFortMobileHUDWidgetCustomPropertyModel_Number
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="UFortMobileHUDWidgetCustomPropertyModel_QuickbarLocks", meta=(ClampMax="32", ClampMin="0"))
	int32 MaximumDisplayedOptions;

};

