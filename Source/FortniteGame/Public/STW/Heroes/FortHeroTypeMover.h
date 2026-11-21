// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/Heroes/FortHeroType.h"
#include "FortHeroTypeMover.generated.h"

class AFortPlayerPawn;

UCLASS(MinimalAPI, NotBlueprintable)
class UFortHeroTypeMover : public UFortHeroType
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Pawn")
	TSoftClassPtr<AFortPlayerPawn> OverridePawnClassWithMover;

};

