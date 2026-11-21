// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFramework/PersistenceFrameworkPersistentName.h"
#include "PersistenceFrameworkWorldPartInfo.generated.h"

USTRUCT()
struct FORTNITEGAME_API FPersistenceFrameworkWorldPartInfo
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FPersistenceFrameworkPersistentName WorldId;

	UPROPERTY()
	FPersistenceFrameworkPersistentName TileId;

	UPROPERTY()
	FPersistenceFrameworkPersistentName LayerId;

	UPROPERTY()
	FPersistenceFrameworkPersistentName CombinedPersistentName;

};

