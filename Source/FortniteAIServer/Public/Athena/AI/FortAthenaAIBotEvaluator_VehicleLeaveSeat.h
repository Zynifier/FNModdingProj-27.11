// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_VehicleLeaveSeat.generated.h"

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAISERVER_API UFortAthenaAIBotEvaluator_VehicleLeaveSeat : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LeaveSeatStatusKeyName;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bLeaveSeatWhenPlayerInVehicle;

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	bool bLeaveSeatWhenConverterLeave;

};

