// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "FortPlayerStartWarmup.generated.h"

UCLASS(MinimalAPI, HideCategories=("Collision", "Lighting", "LightColor", "Force"), ClassGroup=("Common"))
class AFortPlayerStartWarmup : public APlayerStart
{
	GENERATED_BODY()

public:
	AFortPlayerStartWarmup(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

