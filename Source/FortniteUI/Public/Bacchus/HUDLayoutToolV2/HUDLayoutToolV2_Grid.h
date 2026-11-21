// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/Color.h"
#include "HUDLayoutToolV2_Grid.generated.h"

UCLASS()
class UHUDLayoutToolV2_Grid : public UWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Grid")
	int32 RuleLinePeriod;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Grid")
	FLinearColor RegularLineColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Grid")
	FLinearColor RuleLineColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Grid")
	float GridSize;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Grid")
	float SmallestGridSize;

};

