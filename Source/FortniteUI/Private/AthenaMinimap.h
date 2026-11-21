// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/MathFwd.h"
#include "AthenaMinimap.generated.h"

UCLASS()
class UAthenaMinimap : public UWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Minimap")
	FVector2D DesiredSize;

};

