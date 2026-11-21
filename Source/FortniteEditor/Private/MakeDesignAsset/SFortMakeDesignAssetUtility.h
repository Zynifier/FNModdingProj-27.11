// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SFortMakeDesignAssetUtility.generated.h"

USTRUCT()
struct FCurveAssetForm
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Curve")
	FString RowName;

};

USTRUCT()
struct FDataAssetForm
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Data")
	FString RowName;

};

