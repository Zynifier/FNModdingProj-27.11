// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineLinkId.h"
#include "OnlineDiscoveryServiceMcpTypes.generated.h"

USTRUCT()
struct FOnlineDiscoveryModeSetDef
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnlineLinkId ModeSetId;

	UPROPERTY()
	FString SubModeLinkType;

	UPROPERTY()
	TArray<FOnlineLinkId> SubModeLinkIds;

};

USTRUCT()
struct FOnlineDiscoverySurfaceDevelopmentLinkCodes
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName SurfaceName;

	UPROPERTY()
	TArray<FString> DevelopmentLinkCodes;

};

