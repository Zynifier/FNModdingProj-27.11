// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "FortTeamActorInterface.h"
#include "FortPvPPlayerStart.generated.h"

UCLASS(HideCategories=("Collision", "Lighting", "LightColor", "Force"), ClassGroup=("Common"))
class AFortPvPPlayerStart : public APlayerStart, public IFortTeamActorInterface
{
	GENERATED_BODY()

public:
	AFortPvPPlayerStart(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Team")
	uint8 Team;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning")
	uint8 bDynamicStartLocation : 1;

};

