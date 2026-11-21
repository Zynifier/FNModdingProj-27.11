// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineLinkModerationStatus.generated.h"

UENUM()
enum class EOnlineLinkModerationStatus : uint8
{
	Unmoderated = 0,
	Approved = 1,
	Denied = 2,
};

