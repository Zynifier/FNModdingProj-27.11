// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "GenericFortPrioritizedWidgetBase.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UGenericFortPrioritizedWidgetBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

