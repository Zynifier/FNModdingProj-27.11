// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "McpEntitlementRefreshTimerInfo.generated.h"

USTRUCT()
struct GAMESUBCATALOG_API FMcpEntitlementRefreshTimerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime NextEntitlementRefresh;

	UPROPERTY()
	FDateTime MustRefreshAuthBy;

	UPROPERTY()
	FDateTime LastAuthRefresh;

};

