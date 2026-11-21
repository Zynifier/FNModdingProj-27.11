// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Components/FortControllerComponent_ExternalEmote.h"
#include "FortAthenaMutator_ExternalEmotes.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ExternalEmote : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_ExternalEmote")
	TArray<FExternalEmoteCategory> GlobalEmotes;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_ExternalEmote")
	bool bAllowCategoryMerging;

	UPROPERTY(Transient)
	TArray<FExternalEmoteCategory> DynamicEmotes;

};

