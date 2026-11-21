// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "MidMatchRiftPoiManagerActor.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AMidMatchRiftPoiManagerActor : public AActor, public IFortMarkableActorInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Map")
	void SetDynamicLandBrush(const FSlateBrush& LandIcon);

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	FVector MarkerPositionOffset;

private:
	UPROPERTY(Transient)
	bool bDynamicLandBrushApplied;

};

