// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_CustomCharacterParts.h"
#include "FortAthenaMutator_FactionCustomCharacterParts.generated.h"

class AFortPlayerControllerAthena;

UCLASS(Abstract, HideDropdown, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_FactionCustomCharacterParts : public AFortAthenaMutator_CustomCharacterParts
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Skins")
	uint8 GetFactionForPlayer(const AFortPlayerControllerAthena* PlayerController) const;

};

