// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "CosmeticFlowData.generated.h"

USTRUCT()
struct COSMETICSFRAMEWORKFLOWGRAPH_API FCosmeticFlowData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FName, FInstancedStruct> NamedData;

};

