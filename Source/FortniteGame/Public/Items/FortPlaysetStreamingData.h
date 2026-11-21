// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortPlaysetStreamingData.generated.h"

USTRUCT(BlueprintType)
struct FFortPlaysetStreamingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PackageName;

	UPROPERTY()
	FName UniquePackageName;

	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FRotator Rotation;

	UPROPERTY()
	uint8 bValid : 1;

};

