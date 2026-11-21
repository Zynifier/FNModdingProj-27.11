// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "FortObjectiveProcessor_VehicleBase.generated.h"

USTRUCT(meta=(Hidden))
struct FFortObjectiveFilter_VehicleBase : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase")
	FObjectiveSubjectTags_Progressible Vehicle;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase")
	FObjectiveSubjectTags_Progressible Driver;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase")
	FObjectiveSubjectTags_Progressible Passengers;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase")
	uint8 bRequireAllPassengersToMatchFilter : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase", meta=(InlineEditConditionToggle))
	uint8 bUseVehicleHealthPercent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase", meta=(InlineEditConditionToggle))
	uint8 bUseVehicleFuelPercent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase", meta=(EditCondition="bUseVehicleHealthPercent", UIMin="0"))
	FFloatRange VehicleHealthPercent;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleBase", meta=(EditCondition="bUseVehicleFuelPercent", UIMin="0"))
	FFloatRange VehicleFuelPercent;

};

