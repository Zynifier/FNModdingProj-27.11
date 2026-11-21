// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/FortMobileHUDWidgetCustomPropertyModel.h"
#include "FortMobileHUDWidgetCustomPropertyModel_Number.generated.h"

UCLASS()
class UFortMobileHUDWidgetCustomPropertyModel_Number : public UFortMobileHUDWidgetCustomPropertyModel
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel_Number")
	int32 DefaultValue;

};

