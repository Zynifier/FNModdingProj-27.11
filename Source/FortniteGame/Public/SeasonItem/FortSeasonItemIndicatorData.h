// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "FortSeasonItemIndicatorData.generated.h"

USTRUCT(BlueprintType)
struct FFortSeasonItemMapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortSeasonItemMapData")
	FString SeasonItemTag;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonItemMapData")
	FVector WorldLocation;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonItemMapData")
	FSlateBrush FullScreenMapIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonItemMapData")
	FSlateBrush InteractedIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonItemMapData")
	FVector2D FullScreenMapScale;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonItemMapData")
	bool bAlwaysRender;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonItemMapData")
	FString CalendarEventName;

};

UCLASS(MinimalAPI)
class UFortSeasonItemIndicatorData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category="FortSeasonItemIndicatorData")
	TArray<FFortSeasonItemMapData> SeasonItemMapData;

};

