// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortSnapOnSurfaceSubsystem.generated.h"

class UFortLandscapeClampingHelper;

UCLASS(MinimalAPI)
class UFortSnapOnSurfaceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortLandscapeClampingHelper> LandscapeClampingHelper;

};

