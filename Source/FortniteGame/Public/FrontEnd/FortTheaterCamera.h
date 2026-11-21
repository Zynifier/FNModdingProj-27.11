// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraBase.h"
#include "FortTheaterCamera.generated.h"

class AFortTheaterMapTile;
class UFortQuestItem;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortTheaterCamera : public AFortCameraBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Theater Camera")
	TArray<UFortQuestItem*> FindPinnedQuestsForTiles(TArray<AFortTheaterMapTile*> Tiles) const;

	UFUNCTION(BlueprintPure, Category="Theater Camera")
	FVector LimitToTheater(const FVector& DesiredPosition) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Theater Camera")
	void SetTileFocus(AFortTheaterMapTile* TargetTile);

};

