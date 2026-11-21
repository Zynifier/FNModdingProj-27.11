// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_ReachBeacon.generated.h"

class UFortAthenaBeaconComponent;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_ReachBeacon : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReachBeaconStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReachBeaconMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ReachBeaconTargetKeyName;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortAthenaBeaconComponent> CurrentBeacon;

};

