// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "Athena/FortActivatablePanelWithItemPreview.h"
#include "SpatialFactionUnlockedPerksScreen.generated.h"

class UCommonButtonLegacy;
class UFactionUnlockedPerkData;
class UFortItem;
class UTileView;

UCLASS(BlueprintType)
class UFactionUnlockedPerkData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FactionUnlockedPerkData")
	TObjectPtr<UFortItem> PerkItem;

};

UCLASS(meta=(DisableNativeTick))
class UFactionUnlockedPerkListEntry : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BPSetup(UFactionUnlockedPerkData* InPerk);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStaggerTimeElapsed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStaggerTimeStarted();

	UPROPERTY(Transient)
	TObjectPtr<UFactionUnlockedPerkData> Perk;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class USpatialFactionUnlockedPerksScreen : public UFortActivatablePanelWithItemPreview
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnlockedPerksScreenClosedDynamic);

public:
	UPROPERTY(BlueprintAssignable)
	FOnUnlockedPerksScreenClosedDynamic BP_OnUnlockedPerksScreenClosed;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemViewed(const UFactionUnlockedPerkData* ItemDisplayed);

	UPROPERTY(EditDefaultsOnly, Category="SpatialFactionUnlockedPerksScreen")
	float StaggerTime;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionUnlockedPerksScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTileView> TileView_Perks;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionUnlockedPerksScreen", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TouchBack;

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> LastViewedItem;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFactionUnlockedPerkData>> AllPerkItems;

};

