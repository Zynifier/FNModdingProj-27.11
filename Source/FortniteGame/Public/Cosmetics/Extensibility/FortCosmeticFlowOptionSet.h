// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCosmeticFlowOptionSet.generated.h"

class UFortCosmeticFlowOption;

UCLASS(Const, MinimalAPI)
class UFortCosmeticFlowOptionSet : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TSoftClassPtr<UFortCosmeticFlowOption>> Options;

};

