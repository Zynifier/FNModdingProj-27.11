// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaUIStateWidgetTypes.generated.h"

UENUM(BlueprintType)
enum class EFrontendVisibilityMode : uint8
{
	Normal = 0,
	HideTopTabsOnly = 1,
	HideTopTabsOnlyWithoutBottomBar = 2,
	OnlyBottom = 3,
	OnlyTop = 4,
	OnlyTitleBar = 5,
	Empty = 6,
};

