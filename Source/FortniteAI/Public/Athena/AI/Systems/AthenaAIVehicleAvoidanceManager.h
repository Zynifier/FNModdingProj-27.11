// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"
#include "AthenaAIVehicleAvoidanceManager.generated.h"

UCLASS()
class FORTNITEAI_API UAthenaAIVehicleAvoidanceManager : public UAISubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaAIVehicleAvoidanceManager")
	float TimeToRefreshTree;

};

