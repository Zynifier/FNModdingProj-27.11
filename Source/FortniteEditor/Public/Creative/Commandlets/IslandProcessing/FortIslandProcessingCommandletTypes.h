// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortIslandProcessingCommandletTypes.generated.h"

class ULevelSaveRecord;

USTRUCT()
struct FIslandFileToProcessByCommandlet
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ULevelSaveRecord* InputLevelSaveRecord;

};

