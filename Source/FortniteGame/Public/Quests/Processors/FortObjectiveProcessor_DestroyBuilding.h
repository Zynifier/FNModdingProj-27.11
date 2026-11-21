// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "FortObjectiveProcessor_DestroyBuilding.generated.h"

USTRUCT(meta=(DisplayName="Destroy Building"))
struct FFortObjectiveFilter_DestroyBuilding : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DestroyBuilding")
	FObjectiveSubjectTags DestroyedBuilding;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DestroyBuilding")
	FObjectiveSubjectTags DamageSource;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DestroyBuilding")
	uint8 bRequireInVehicle : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DestroyBuilding", meta=(EditCondition="bRequireInVehicle"))
	uint8 bUseAdvancedVehicleFilter : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DestroyBuilding", meta=(EditCondition="bRequireInVehicle && bUseAdvancedVehicleFilter", EditConditionHides))
	FFortObjectiveFilterType_VehicleFilter VehicleFilter;

};

UCLASS()
class UFortObjectiveProcessor_DestroyBuilding : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

