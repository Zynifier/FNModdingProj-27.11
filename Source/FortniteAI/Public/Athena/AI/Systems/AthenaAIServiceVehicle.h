// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/Systems/AthenaAIService.h"
#include "AthenaAIServiceVehicle.generated.h"

UCLASS()
class UAthenaAIServiceVehicle : public UAthenaAIService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaAIServiceVehicle")
	float TimeToRefreshTree;

};

