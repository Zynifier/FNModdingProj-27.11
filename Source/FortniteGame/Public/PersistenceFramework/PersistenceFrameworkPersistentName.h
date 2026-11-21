// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFrameworkPersistentName.generated.h"

USTRUCT()
struct FORTNITEGAME_API FPersistenceFrameworkPersistentName
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<FName> HierarchicalName;

	UPROPERTY()
	TArray<FName> Names;

	UPROPERTY()
	FString StringName;

};

