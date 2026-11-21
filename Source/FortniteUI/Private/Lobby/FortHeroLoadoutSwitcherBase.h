// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHeroLoadoutSwitcherBase.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortCampaignHeroLoadoutItem;
class UFortHeroAbilitiesAndGadgetsBase;
class UFortItemDetailsHostPanel;
class UHorizontalBox;
enum class EFortRarity : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHeroLoadoutSwitcherBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Update(const UFortCampaignHeroLoadoutItem* HeroLoadout);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRarity(const EFortRarity Rarity);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_LoadoutPagingContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsHostPanel> HeroLoadoutCommanderDetailsHostPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortHeroAbilitiesAndGadgetsBase> HeroAbilitiesAndGadgets;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_LoadoutDisplayName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PageLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PageRight;

};

