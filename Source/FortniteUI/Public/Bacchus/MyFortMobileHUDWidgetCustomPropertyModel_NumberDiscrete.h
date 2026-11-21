// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/FortMobileHUDWidgetCustomPropertyModel_Number.h"
#include "MyFortMobileHUDWidgetCustomPropertyModel_NumberDiscrete.generated.h"

UCLASS()
class UMyFortMobileHUDWidgetCustomPropertyModel_NumberDiscrete : public UFortMobileHUDWidgetCustomPropertyModel_Number
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="MyFortMobileHUDWidgetCustomPropertyModel_NumberDiscrete")
	TMap<int32, FText> PropertyOptions;

};

