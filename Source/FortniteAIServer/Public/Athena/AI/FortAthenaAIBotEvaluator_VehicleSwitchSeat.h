// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_VehicleSwitchSeat.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_VehicleSwitchSeat : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName SwitchSeatStatusKeyName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bSwitchToEmptyDriverSeat;

};

