// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCompositeBool.generated.h"

class UObject;

USTRUCT()
struct FCompositeBool
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bDefaultValue;

	UPROPERTY()
	TArray<TSoftObjectPtr<UObject>> ModifyingObjects;

};

