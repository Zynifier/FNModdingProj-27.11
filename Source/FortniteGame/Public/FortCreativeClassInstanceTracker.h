// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeClassInstanceTracker.generated.h"

class UObject;

USTRUCT()
struct FFortCreativeClassInstanceTracker
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TSubclassOf<UObject>> ChildClassesAtLimit;

	UPROPERTY()
	TArray<TSubclassOf<UObject>> ParentClassesAtLimit;

};

