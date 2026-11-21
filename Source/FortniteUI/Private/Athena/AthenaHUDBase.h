// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUIExtensionSlot.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "AthenaHUDBase.generated.h"

class AFortGameplayMutator;
class AFortMinigame;
class UAthenaHUDMenu;
class UAthenaMapScreenContainer;
class UCommonActivatableWidget;
class UFortWeaponWheel;
class UUserWidget;
enum class EFortPickerMode : uint8;
enum class EUIExtensionSlot : uint8;

USTRUCT()
struct FMutatorAddedWidgets
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaHUDBase : public UFortUIStateWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void BindVolumeEvents();

	UFUNCTION(BlueprintPure)
	bool GetZoneCompleted() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleCursorModeChanged(bool bCursorModeEnabled, FName ActionName, UUserWidget* CustomWidget);

	UFUNCTION()
	void HandleCursorModeChanging(bool bCursorModeEnabled, FName ActionName);

	UFUNCTION()
	void HandleMinigameHideHUD(bool bLoading);

	UFUNCTION()
	void HandleMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode);

	UFUNCTION()
	void HandleNewPanelFromMutator(TSubclassOf<UUserWidget> PanelClass);

	UFUNCTION()
	void HandleOnMutatorAdded(AFortGameplayMutator* NewMutator);

	UFUNCTION()
	void HandleOnMutatorRemoved(AFortGameplayMutator* NewMutator);

	UFUNCTION()
	void HandlePickerOpenRequest(EFortPickerMode Mode, int32 InitialOption, bool bIgnoreFirstAccept);

	UFUNCTION()
	void HandleRecoverFromPostGame();

	UFUNCTION()
	void HandleUpdateMinigameUIExtensions(AFortMinigame* Minigame);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetCreated(EUIExtensionSlot ExtensionSlot, UUserWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetRemoved(EUIExtensionSlot ExtensionSlot, UUserWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHUDScaleChanged(float HUDScale);

	UFUNCTION(BlueprintCallable)
	void SetZoneCompleted(bool bValue);

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UUserWidget>> MinigameWidgets;

	UPROPERTY(Transient)
	TSubclassOf<UUserWidget> KairosHUDLayerClass;

	UPROPERTY()
	TArray<FMutatorAddedWidgets> MutatorAddedWidgets;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaMapScreenContainer> MapScreenContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaHUDBase", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaHUDMenu> AthenaHudMenu;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> TitleBar;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSet<EUIExtensionSlot> RelevantExtensionSlots;

	UPROPERTY(EditDefaultsOnly, Category="Pickers", meta=(AllowedClasses="/Script/FortniteUI.FortEmotePicker"))
	TSoftClassPtr<UCommonActivatableWidget> NewEmotePicker;

	UPROPERTY(EditDefaultsOnly, Category="Pickers", meta=(AllowedClasses="/Script/FortniteUI.FortSquadComsPicker"))
	TSoftClassPtr<UCommonActivatableWidget> SquadComsPickerClass;

	UPROPERTY(EditDefaultsOnly, Category="Pickers")
	TSoftClassPtr<UFortWeaponWheel> WeaponWheelClass;

	UPROPERTY(EditDefaultsOnly, Category="Pickers")
	TSoftClassPtr<UCommonActivatableWidget> QuickWeaponClass;

};

