// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NavAreas/NavArea.h"
#include "FortNavArea.generated.h"

UENUM()
namespace EFortAreaFlag
{
	enum Type
	{
		Default = 0,
		Obstacle = 1,
		Smashable = 2,
		Unwalkable = 3,
		// used for segment link patches

		Interactable = 4,
	};
}

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortNavArea : public UNavArea
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="NavAreaFlags")
	uint8 bObstacle : 1;

	UPROPERTY(EditAnywhere, Category="NavAreaFlags")
	uint8 bSmashable : 1;

};

