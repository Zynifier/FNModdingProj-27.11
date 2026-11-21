// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "UI/FortElevationData.h"
#include "AthenaSpecialActorComponent.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger"), meta=(BlueprintSpawnableComponent))
class UAthenaSpecialActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetSeasonItemTag(const FGameplayTag& InSeasonItemTag);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimap")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Minimap")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FullScreen Map")
	FSlateBrush SpecialActorFullScreenMapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FullScreen Map")
	FVector2D SpecialActorFullScreenMapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FullScreen Map")
	bool bDrawMapIconUnderStorm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FullScreen Map")
	bool bDrawRotated;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FullScreen Map")
	float YawOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Compass", meta=(AllowPrivateAccess="true"))
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Compass", meta=(AllowPrivateAccess="true"))
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Compass")
	bool bUseCompassIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Compass")
	bool bDrawCompassDistanceText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Elevation")
	FElevationArrowData ElevationArrowData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RenderConditions", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EAthenaGamePhase"))
	uint8 RenderOnMapDuringPhases;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RenderConditions")
	FScalableFloat RenderDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RenderConditions")
	FGameplayTagContainer RenderTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonItem")
	FGameplayTag SeasonItemTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonItem")
	FSlateBrush SeasonItemInteractedBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Calendar")
	FString CalendarEventName;

	UPROPERTY(Transient)
	FName SpecialActorID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RenderConditions")
	int32 Priority;

};

