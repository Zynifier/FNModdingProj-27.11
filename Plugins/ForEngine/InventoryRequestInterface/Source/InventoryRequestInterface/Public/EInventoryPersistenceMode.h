// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EInventoryPersistenceMode.generated.h"

UENUM()
enum class EInventoryPersistenceMode : uint8
{
	/** All changes automatically sent to sidecar on the next tick */
	Normal = 0,
	/** Writing of any changes is deferred until SetPersistence(Normal) is called */
	Deferred = 1,
	/** No changes to this inventory are persisted */
	Disabled = 2,
	/** No changes to this inventory are allowed */
	ReadOnly = 3,
};

