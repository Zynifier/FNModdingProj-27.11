// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortAthenaReward.generated.h"

class UFortCosmeticItemCard;
class UFortItem;
class UFortItemDefinition;
class UWidget;
enum class EFortAthenaRewardState : uint8;

UENUM(BlueprintType)
enum class EFortAthenaRewardState : uint8
{
	LevelAchieved = 0,
	Claimed = 1,
	ForceLocked = 2,
	Owned = 3,
	Max_None = 4 UMETA(Hidden),
};

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UFortAthenaReward : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetupRewardItem(const UFortItemDefinition* ItemDefToRepresent, const int32 Quantity = 1);

	UFUNCTION(BlueprintCallable)
	void SetViewOnHovered(bool bShouldViewOnHovered);

	UFUNCTION(BlueprintCallable)
	void UpdateRewardState(const EFortAthenaRewardState StateToSetup, const bool bEnabled);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRepresentedItemSet(const UFortItem* RepresentedItem, bool IsEquipped);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateUpdated(bool bClaimed);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> SecondaryItemDefToRepresent;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> RepresentedItemDefinition;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaReward", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCosmeticItemCard> ItemCard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_ClaimedImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_LockedImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_UnearnedTintOverlay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_OwnedBorder;

};

