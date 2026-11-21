// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AthenaAIDropper.generated.h"

class AAthenaAIController;
class ABuildingActor;

USTRUCT()
struct FDroppingAgentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AAthenaAIController> AIController;

	UPROPERTY()
	TObjectPtr<ABuildingActor> MovementBase;

};

UCLASS()
class UAthenaAIDropper : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FDroppingAgentData> InactiveAgents;

};

