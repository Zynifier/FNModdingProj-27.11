// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/Player/FortPlayerControllerPvE.h"
#include "FortPlayerControllerBoss.generated.h"

UCLASS(HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerBoss : public AFortPlayerControllerPvE
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FName LastPossessedPawn;

};

