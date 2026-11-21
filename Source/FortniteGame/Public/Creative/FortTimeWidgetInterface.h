// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTimeWidgetInterface.generated.h"

UENUM()
enum class EWidgetInterfaceTimerStatus : uint8
{
	None = 0,
	// Default

	Active = 1,
	// Timer is currently ticking along.

	Paused = 2,
	// Timer still has time, but is paused.

	Inactive = 3,
};

UINTERFACE(MinimalAPI)
class UFortTimeWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortTimeWidgetInterface
{
	GENERATED_BODY()

};

