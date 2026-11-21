// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CosmeticBackendLoadout.h"
#include "McpItemAware.h"
#include "FortCosmeticLoadoutItem.generated.h"

UCLASS(MinimalAPI)
class UFortCosmeticLoadoutItem : public UObject, public IMcpItemAware
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FCosmeticBackendLoadout BackendLoadout;

};

