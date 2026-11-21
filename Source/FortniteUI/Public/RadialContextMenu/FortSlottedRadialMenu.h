// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RadialContextMenu/FortRadialMenu.h"
#include "FortSlottedRadialMenu.generated.h"

UENUM(BlueprintType)
enum class ECardinalPoint : uint8
{
	E = 0,
	NE = 1,
	N = 2,
	NW = 3,
	W = 4,
	SW = 5,
	S = 6,
	SE = 7,
	None = 8,
};

UENUM(BlueprintType)
enum class ERadialOrderingMode : uint8
{
	CounterClockwise = 0,
	Clockwise = 1,
	Cardinal = 2,
	Custom = 3,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UFortSlottedRadialMenu : public UFortRadialMenu
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Ordering")
	ERadialOrderingMode OrderingMode;

	UPROPERTY(EditAnywhere, Category="Ordering", meta=(EditCondition="OrderingMode == ERadialOrderingMode::Custom"))
	TArray<ECardinalPoint> CustomOrdering;

	UPROPERTY(EditAnywhere, Category="Ordering")
	bool bUseAsManySlotsAsItems;

	UPROPERTY(EditAnywhere, Category="Slots", meta=(ClampMax="8", ClampMin="2"))
	int32 NumSlotsSupported;

};

