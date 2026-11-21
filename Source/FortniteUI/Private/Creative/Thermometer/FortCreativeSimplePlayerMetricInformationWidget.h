// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Thermometer/FortCreativeVolumeWidget.h"
#include "ObjectTracking/FortMetricInformation.h"
#include "FortCreativeSimplePlayerMetricInformationWidget.generated.h"

class APlayerState;

UCLASS()
class UFortCreativeSimplePlayerMetricInformationWidget : public UFortCreativeVolumeWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Simple Player Metric Information Updated"))
	void BP_OnSimplePlayerMetricInformationUpdated(const FSimpleMetricInformation& SimpleMetricInformation);

	UFUNCTION()
	void OnSimplePlayerMetricInformationUpdated(APlayerState* PlayerState, const FSimpleMetricInformation& SimpleMetricInformation);

};

