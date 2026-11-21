// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "BacchusQuickbarBase.generated.h"

UENUM(BlueprintType)
enum class EComboSlotType : uint8
{
	Primary = 0,
	// Only shows primary slot

	Secondary = 1,
	// Only shows secondary slot

	Combo = 2,
	// Switches between quickbar slots depending on build mode state.

	Creative = 3,
	COUNT = 4,
};

UCLASS(Abstract, MinimalAPI)
class UBacchusQuickbarBase : public UBacchusHUDElement
{
	GENERATED_BODY()

};

