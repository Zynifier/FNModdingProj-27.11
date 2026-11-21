// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent_ExternalEmote.h"
#include "Modifiers/FortAthenaMutator_ExternalEmotes.h"
#include "FortAthenaMutator_PartyRiftEmotes.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PartyRiftEmotes : public AFortAthenaMutator_ExternalEmote
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FExternalEmoteCategory> ActiveEmoteList;

};

