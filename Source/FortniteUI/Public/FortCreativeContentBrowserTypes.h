// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeContentBrowserTypes.generated.h"

UENUM(BlueprintType)
enum class EFortCreativeItemType : uint8
{
	Chest = 0,
	Item = 1,
	Collection = 2,
	SubItems = 3,
	NoCreativeItems = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFocusChangedDelegate, bool, bIsFocused);

