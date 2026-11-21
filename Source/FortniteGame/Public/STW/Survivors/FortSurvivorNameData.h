// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortSurvivorNameData.generated.h"

USTRUCT()
struct FFortSurvivorNameData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Survivors")
	FText Name;

};

