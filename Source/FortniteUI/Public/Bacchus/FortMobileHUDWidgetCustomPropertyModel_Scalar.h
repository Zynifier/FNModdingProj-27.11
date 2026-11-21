// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/FortMobileHUDWidgetCustomPropertyModel.h"
#include "FortMobileHUDWidgetCustomPropertyModel_Scalar.generated.h"

UCLASS()
class UFortMobileHUDWidgetCustomPropertyModel_Scalar : public UFortMobileHUDWidgetCustomPropertyModel
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel_Scalar")
	double DefaultValue;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel_Scalar")
	double PropertyLowerBound;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel_Scalar")
	double PropertyUpperBound;

	UPROPERTY(EditAnywhere, Category="FortMobileHUDWidgetCustomPropertyModel_Scalar")
	double PropertyStepSize;

};

