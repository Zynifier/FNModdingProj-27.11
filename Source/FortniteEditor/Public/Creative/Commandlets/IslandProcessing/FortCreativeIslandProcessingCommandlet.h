// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "Creative/Commandlets/IslandProcessing/FortIslandProcessingCommandletTypes.h"
#include "FortCreativeIslandProcessingCommandlet.generated.h"

class UFortCreativeIslandProcessingTaskBase;

UCLASS()
class UFortCreativeIslandProcessingCommandlet : public UCommandlet
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FIslandFileToProcessByCommandlet> IslandFilesToProcess;

	UPROPERTY()
	UFortCreativeIslandProcessingTaskBase* TaskToExecute;

};

