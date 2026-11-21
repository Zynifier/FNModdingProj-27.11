// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/MathFwd.h"
#include "FortCampaignMinimap.generated.h"

UCLASS()
class UFortCampaignMinimap : public UWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Minimap")
	FVector2D DesiredSize;

};

