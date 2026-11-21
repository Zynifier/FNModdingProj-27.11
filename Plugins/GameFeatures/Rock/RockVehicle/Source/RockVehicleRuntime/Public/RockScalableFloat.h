// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "RockScalableFloat.generated.h"

USTRUCT(BlueprintType)
struct FRockScalableFloat : public FScalableFloat
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float CachedValue;

};

