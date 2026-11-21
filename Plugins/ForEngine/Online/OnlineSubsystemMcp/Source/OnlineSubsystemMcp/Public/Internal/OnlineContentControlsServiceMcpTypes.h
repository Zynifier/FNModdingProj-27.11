// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineContentControlsServiceMcpTypes.generated.h"

UENUM(BlueprintType)
enum class ESocialCommsPermission : uint8
{
	Nobody = 0,
	FriendsOnly = 1,
	FriendsAndTeammates = 2,
	Everybody = 3,
};

