// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Creative/FortCreativeTags.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortSpecialActorStatData.h"
#include "Items/FortGadgetItemDefinition.h"
#include "AthenaGadgetItemDefinition.generated.h"

class UFortInteractContextInfoWidget;

UCLASS(MinimalAPI, BlueprintType)
class UAthenaGadgetItemDefinition : public UFortGadgetItemDefinition, public IFortCreativeTagsBearer, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Inventory")
	uint8 bCanBeDroppedWhenEquipmentChangeIsBlocked : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	uint8 bAllowedFuelGadgetUI : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	uint8 bShowCooldownUI : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	uint8 bShowShortDescriptionInPickupDisplay : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor", meta=(DisplayAfter="InventoryCompassIconScale"))
	uint8 bDisplayPlayerNameForInventoryActor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor", meta=(DisplayAfter="InventoryActorDisplayName"))
	uint8 bDisplayHealthForInventoryActor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor", meta=(DisplayAfter="bDisplayHealthForInventoryActor"))
	uint8 bDisplayShieldForInventoryActor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorInventoryTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FName InventorySpecialActorUniqueID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush InventoryMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D InventoryMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush InventoryCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D InventoryCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FText InventoryActorDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	TArray<FSpecialActorSingleStatData> SpecialActorInventoryStatList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	TSubclassOf<UFortInteractContextInfoWidget> ContextOverrideWidget;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Creative", meta=(Patchable, ShowOnlyInnerProperties))
	FFortCreativeTagsHelper CreativeTagsHelper;

};

