// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Math/MathFwd.h"
#include "LevelStreamingBuildingFoundation.generated.h"

UCLASS()
class ULevelStreamingBuildingFoundation : public ULevelStreamingDynamic
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FBox FoundationStreamingBounds;

	UPROPERTY(Transient)
	FName FoundationName;

};

