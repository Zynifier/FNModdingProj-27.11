// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Missions/FortMission.h"
#include "FortMissionAircraft.generated.h"

class AFortAircraft;

UCLASS(HideCategories=("Input", "Actor", "Replication", "Rendering"))
class AFortMissionAircraft : public AFortMission
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Aircraft")
	AFortAircraft* CreateAircraft(const FTransform SpawnTransform, TSubclassOf<AFortAircraft> AircraftClass);

	UPROPERTY()
	TObjectPtr<AFortAircraft> Aircraft;

};

