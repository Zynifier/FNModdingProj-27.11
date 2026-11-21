// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "Heroes/FortHeroLoadoutPerkTileBase.h"
#include "FortHeroLoadoutInGameScreenBase.generated.h"

class UFortGadgetItemDefinition;
class UFortHeroLoadoutGadgetTileBase;
class UFortHeroLoadoutPerkTileBase;
class UFortItemDetailsHostPanel;
class UGridPanel;
class UGridSlot;
class UScrollBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHeroLoadoutInGameScreenBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortGadgetItemDefinition* GetGadgetDefinitionBySlot(int32 SlotIndex) const;

	UFUNCTION(BlueprintImplementableEvent, Category="InGameHeroLoadout")
	void OnPerkWidgetAdded(UGridSlot* GridSlot);

protected:
	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutInGameScreenBase")
	TArray<FFortInGamePerkDisplayData> PerksDisplayData;

	UPROPERTY(EditAnywhere, Category="FortHeroLoadoutInGameScreenBase")
	TSubclassOf<UFortHeroLoadoutPerkTileBase> TileClass;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Content;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsHostPanel> ItemDetailsHostPanel_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UGridPanel> GridPanel_Perks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHeroLoadoutGadgetTileBase> GadgetTile_Gadget1;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHeroLoadoutGadgetTileBase> GadgetTile_Gadget2;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortHeroLoadoutGadgetTileBase>> GadgetTiles;

};

