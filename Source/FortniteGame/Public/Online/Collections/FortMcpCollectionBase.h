// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "McpItemAware.h"
#include "Online/Collections/FortCollectionsTypes.h"
#include "FortMcpCollectionBase.generated.h"

UCLASS(MinimalAPI)
class UFortMcpCollectionBase : public UObject, public IMcpItemAware
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FFortMcpCollectedItemProperties> Collected;

};

