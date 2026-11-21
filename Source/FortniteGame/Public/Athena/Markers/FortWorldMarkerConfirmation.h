// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "FortWorldMarkerConfirmation.generated.h"

USTRUCT()
struct FFortWorldMarkerConfirmation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PlayerId;

	UPROPERTY()
	FLinearColor PinColor;

};

USTRUCT()
struct FFortWorldMarkerConfirmationContainer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FFortWorldMarkerConfirmation> Confirmations;

};

