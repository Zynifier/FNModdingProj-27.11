// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NavFilters/NavigationQueryFilter.h"
#include "FortNavigationFilter_Caretaker.generated.h"

class UNavigationQueryFilter;

UCLASS(BlueprintType, Blueprintable)
class UFortNavigationFilter_Caretaker : public UNavigationQueryFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node", meta=(ClampMin="0.0", UIMin="0.0"))
	float EndPointAcceptableRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Node")
	TSubclassOf<UNavigationQueryFilter> EndPointFilterClass;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bEndPointReachTestIncludesAgentRadius : 1;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bEndPointReachTestIncludesGoalRadius : 1;

};

