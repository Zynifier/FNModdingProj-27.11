// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "FortBTService_UpdateBotMissionGoal.generated.h"

UCLASS(HideCategories=("Service"))
class UFortBTService_UpdateBotMissionGoal : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Mission")
	uint8 bRequireInteraction : 1;

	UPROPERTY(EditAnywhere, Category="Mission")
	uint8 bRequireInteractionOrLocator : 1;

	UPROPERTY(EditAnywhere, Category="Mission")
	uint8 bRequireEncounter : 1;

	UPROPERTY(EditAnywhere, Category="Mission")
	uint8 bPickClosest : 1;

};

