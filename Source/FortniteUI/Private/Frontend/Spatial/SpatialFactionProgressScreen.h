// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SpatialFactionProgressScreen.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UDynamicEntryBox;
class UFortPlayerPerksItemDefinition;
class UFortSocialAvatarIcon;
class UFortSpyTechItemDefinition;
class UScrollBox;
class UTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class USpatialFactionProgressScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFactionSet(int32 PlayerFaction);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPerkSelected(UFortSpyTechItemDefinition* PerkItemDef, int32 PerkLevel, int32 PerkFaction, bool bIsRevealed, bool bIsEarned, bool bIsCurrentFaction);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpatialFactionProgressScreen")
	TObjectPtr<UFortPlayerPerksItemDefinition> Faction1PerksItemDef;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpatialFactionProgressScreen")
	TObjectPtr<UFortPlayerPerksItemDefinition> Faction2PerksItemDef;

private:
	UFUNCTION()
	void HandlePerkSelected(UCommonButtonLegacy* AssociatedButton, int32 Index);

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_FactionPerks;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionProgressScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SwapFaction;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionProgressScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> SpatialFaction_ShadowButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionProgressScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> SpatialFaction_GhostButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="SpatialFactionPerkTier"))
	TObjectPtr<UDynamicEntryBox> EntryBox_FactionPerkTiers;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionProgressScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_PerkItems;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Icon_PlayerImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_PlayerName;

};

