// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPlaylistAthena.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SafeZoneStartupHelper.generated.h"

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SafeZoneStartupHelper : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Event Name")
	FString EventName;

	UPROPERTY(EditAnywhere, Category="Gameplay")
	ESafeZoneStartUp OverrideSafeZoneType;

};

