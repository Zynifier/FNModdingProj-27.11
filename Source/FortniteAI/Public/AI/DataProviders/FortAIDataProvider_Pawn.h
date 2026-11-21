// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "Math/MathFwd.h"
#include "FortAIDataProvider_Pawn.generated.h"

UCLASS(AutoExpandCategories=("Provider"), meta=(DisplayName="Fort Pawn"))
class UFortAIDataProvider_Pawn : public UAIDataProvider
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float SightRadius;

	UPROPERTY()
	float HearingRadius;

	UPROPERTY()
	float ViewLocationOffsetFromGround;

	UPROPERTY()
	float MaxStepHeight;

	UPROPERTY()
	FVector TetheredBoxCenterLocation;

	UPROPERTY()
	float TetheredBoxWidth;

	UPROPERTY()
	float TetheredBoxHeight;

	UPROPERTY()
	float TetheredBoxEQSGridSize;

	UPROPERTY()
	float TetheredBoxEQSSpaceBetween;

};

