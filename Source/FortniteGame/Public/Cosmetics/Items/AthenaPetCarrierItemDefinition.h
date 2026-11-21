// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Cosmetics/Items/AthenaBackpackItemDefinition.h"
#include "AthenaPetCarrierItemDefinition.generated.h"

class UAthenaPetItemDefinition;

UCLASS(MinimalAPI, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaPetCarrierItemDefinition : public UAthenaBackpackItemDefinition, public IFortItemPreviewBoundsInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visuals")
	TObjectPtr<UAthenaPetItemDefinition> DefaultPet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Preview|Bounds")
	FFortUICameraFrameTargetBounds CameraFramingBounds;

};

