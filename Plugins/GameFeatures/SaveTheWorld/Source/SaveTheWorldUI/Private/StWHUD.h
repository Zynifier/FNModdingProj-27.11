// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "StWHUD.generated.h"

class AFortWeapon;
class UCommonActivatableWidget;
class UCommonUserWidget;
class UFortActivatableChatWidget;
class UFortDefenderConfigPanel_STW;
class UFortItemInspectionScreen;
class UFortMissionActivationWidgetSTW;
class UFortPickerData;
class UFortRadialPicker;
class UFortResultsWidgetSTW;
class UFortUINavigationManager;
class UFortWeaponReticleExtensionWidgetBase;
class UOverlay;
class UTopBar_STW;
class UUserWidget;
enum class EFortPickerMode : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSTWHUDMenuStackChanged, UCommonActivatableWidget*, NewTopDisplayedWidget);

UCLASS(BlueprintType, Blueprintable)
class UStWHUD : public UFortUIStateWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void NativeHandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UPROPERTY(EditDefaultsOnly, Category="Pickers")
	TObjectPtr<UFortPickerData> PickerData;

	UPROPERTY(EditDefaultsOnly, Category="Pickers")
	TSoftClassPtr<UFortRadialPicker> EmotePickerClass;

	UPROPERTY(EditDefaultsOnly, Category="Menus")
	TSoftClassPtr<UCommonActivatableWidget> ManagementTabsScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="Menus")
	TSoftClassPtr<UTopBar_STW> TopBarClass;

	UPROPERTY(EditDefaultsOnly, Category="Menus")
	TSoftClassPtr<UFortMissionActivationWidgetSTW> MissionActivationWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Menus")
	TSoftClassPtr<UFortResultsWidgetSTW> PostGameScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="Menus")
	TSoftClassPtr<UFortDefenderConfigPanel_STW> DefenderConfigPanelClass;

	UPROPERTY(BlueprintAssignable)
	FOnSTWHUDMenuStackChanged OnSTWHUDMenuStackChanged;

	UPROPERTY(EditDefaultsOnly, Category="Reticle Extensions")
	int32 ReticleExtensionSize;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonUserWidget* BottomBarWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UOverlay* PersistentHUDContent;

protected:
	UFUNCTION()
	void HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CursorModeContentWidget);

	UFUNCTION()
	void HandlePickerOpenRequest(EFortPickerMode Mode, int32 InitialOption, bool bIgnoreFirstAccept);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonActivatableWidget* TitleBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UOverlay* IndicatorContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActivatableChatWidget> ChatWidget_STW;

	UPROPERTY(EditDefaultsOnly, Category="Menus")
	TSoftClassPtr<UFortItemInspectionScreen> InspectionScreenClass;

	UPROPERTY(Transient)
	UFortUINavigationManager* NavigationManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponReticleExtensionWidgetBase> CurrentCustomReticleExtension;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortWeaponReticleExtensionWidgetBase>> RecentReticleExtensions;

};

