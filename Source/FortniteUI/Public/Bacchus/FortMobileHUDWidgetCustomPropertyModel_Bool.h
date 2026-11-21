// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/FortMobileHUDWidgetCustomPropertyModel.h"
#include "FortMobileHUDWidgetCustomPropertyModel_Bool.generated.h"

UCLASS()
class UFortMobileHUDWidgetCustomPropertyModel_Bool : public UFortMobileHUDWidgetCustomPropertyModel
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel_Bool")
	bool DefaultValue;

};

