// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreamingDynamic.h"
#include "UObject/NoExportTypes.h"
#include "FortLevelOverlayManager.generated.h"

UCLASS(MinimalAPI)
class UFortLevelOverlayManager : public UObject
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortOverlayLevelStreaming : public ULevelStreamingDynamic
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnOverlayLevelVisibiltyChanged();

};

