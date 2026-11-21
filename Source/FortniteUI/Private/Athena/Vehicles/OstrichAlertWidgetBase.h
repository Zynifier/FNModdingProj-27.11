// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaCoupledWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "OstrichAlertWidgetBase.generated.h"

class AFortCharacterVehicle_Ostrich;

UCLASS(Abstract, meta=(DisableNativeTick))
class UOstrichAlertWidgetBase : public UFortHUDElementWidget, public IAthenaCoupledWidgetInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Ostrich")
	TObjectPtr<AFortCharacterVehicle_Ostrich> OwningOstrichVehicle;

};

