// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Components/SlateWrapperTypes.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "AthenaEquippedItemBase.generated.h"

class AFortWeapon;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortResourceItemDefinition;
class UImage;
class UPanelWidget;
class UScaleBox;
enum class EEquippedWeaponDisplay : uint8;
enum class EFortWeaponOverheatState : uint8;
enum class EFortWeaponReloadType : uint8;

UENUM(BlueprintType)
enum class EEquippedWeaponDisplay : uint8
{
	None = 0,
	Resource = 1,
	Magazine = 2,
	Utility = 3,
	Chargeable = 4,
};

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UAthenaEquippedItemBase : public UBacchusHUDElement
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Ammo Count Changed"))
	void BP_HandleAmmoCountChanged(int32 MagazineAmmoCount, int32 SurplusAmmoCount, int32 TotalRemaining);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Has Ammo Changed"))
	void BP_HandleHasAmmoChanged(bool bHasAmmo);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Has Bullets Per Clip Changed"))
	void BP_HandleHasBulletsPerClipChanged(bool bHasBulletsPerClip);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Hide Reserve Ammo"))
	void BP_HandleHideReserveAmmoChanged(bool bHideReserveAmmo);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Resource Count Changed"))
	void BP_HandleResourceCountChanged(int32 ResourceCount);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Resource Type Changed"))
	void BP_HandleResourceTypeChanged(const UFortResourceItemDefinition* Item, int32 ResourceCount);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Secondary Fire Pressed"))
	void BP_HandleSecondaryFirePressed();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Secondary Fire Released"))
	void BP_HandleSecondaryFireReleased();

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="Handle Weapon Equipped"))
	void BP_HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Weapon Mode Changed"))
	void BP_HandleWeaponModeChanged(EEquippedWeaponDisplay Mode);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Weapon Overheat Value Changed"))
	void BP_HandleWeaponOverheatValueChanged(float CurrentValue, float MaxValue, EFortWeaponOverheatState State, bool bIsInCooldown);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Weapon Reload Cancelled"))
	void BP_HandleWeaponReloadCancelled(AFortWeapon* Weapon);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Weapon Reload Started"))
	void BP_HandleWeaponReloadStarted(float ReloadTime, EFortWeaponReloadType ReloadType);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Weapon Targeting Changed"))
	void BP_HandleWeaponTargetingChanged(bool bIsTargeting);

	UFUNCTION()
	void HandleBuildingMaterialChanged();

	UFUNCTION()
	void HandleLocalAmmoChanged(int32 LocalCount, int32 LocalRemaining);

	UFUNCTION()
	void HandleSecondaryFirePressed(AFortWeapon* Weapon);

	UFUNCTION()
	void HandleSecondaryFireReleased(AFortWeapon* Weapon);

	UFUNCTION()
	void HandleViewTargetChanged();

	UFUNCTION()
	void HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void HandleWeaponOverheatValueChanged(float CurrentValue, float MaxValue, EFortWeaponOverheatState State, bool bIsInCooldown);

	UFUNCTION()
	void HandleWeaponReloadCancelled();

	UFUNCTION()
	void HandleWeaponReloadStarted(float ReloadTime, EFortWeaponReloadType ReloadType);

	UFUNCTION()
	void HandleWeaponTargetingChanged(bool bIsTargeting);

	UFUNCTION()
	void HandleWorldItemsChanged();

	UPROPERTY()
	EEquippedWeaponDisplay CurrentMode;

private:
	UPROPERTY(Config)
	int32 AmountConsideredInfinite;

	UPROPERTY(EditDefaultsOnly, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess))
	FText DefaultOutOfAmmoText;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Content;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_ResourceContent;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_AmmoContent;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_UtilityContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_AmmoIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_ResourceIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_UtilityIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MagazineAmmoCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SurplusAmmoCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ResourceCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_UtilityAmmoCount;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_OutOfAmmo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UScaleBox> RootScaleBox;

	UPROPERTY(BlueprintReadWrite, Category="AthenaEquippedItemBase", meta=(AllowPrivateAccess))
	ESlateVisibility WeaponEquipVisibility;

	UPROPERTY(Transient)
	TArray<FGameplayAttribute> TrackedAttributes;

};

