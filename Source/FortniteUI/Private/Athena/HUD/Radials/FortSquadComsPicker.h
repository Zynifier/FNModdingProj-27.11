// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "Athena/AI/Components/PingCommandUtils.h"
#include "Athena/Markers/FortWorldMarkerTypeEnum.h"
#include "RadialContextMenu/FortSlottedRadialMenu.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortSquadComsPicker.generated.h"

class AFortPlayerState;
class UAthenaQuickChatBank;
class UCommonButtonLegacy;
class UCommonLazyImage;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortAutoRunNotificationWidget;
class UFortCTAButton;
class UFortDottedPagination;
class UFortKeybindWidget;
class UFortPickerOverlay;
class UFortTextButton;
class USoundBase;
class UTexture2D;
class UWidget;

USTRUCT()
struct FFortSquadComsPickerCategory
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortSquadComsPickerSubCategoryIdentifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSquadComsPickerSubCategoryIdentifier")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, Category="FortSquadComsPickerSubCategoryIdentifier")
	FText Name;

};

USTRUCT(BlueprintType)
struct FSquadComsNPCCommandEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SquadComsNPCCommandEntry", meta=(MultiLine="TRUE"))
	FText Label;

	UPROPERTY(EditAnywhere, Category="SquadComsNPCCommandEntry")
	FSlateBrush Brush;

	UPROPERTY(EditAnywhere, Category="SquadComsNPCCommandEntry")
	PingCommandType CommandType;

	UPROPERTY(EditAnywhere, Category="SquadComsNPCCommandEntry")
	USoundBase* ConfirmSound;

};

USTRUCT(BlueprintType)
struct FSquadComsQuickChatEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SquadComsQuickChatEntry", meta=(MultiLine="TRUE"))
	FText Label;

	UPROPERTY(EditAnywhere, Category="SquadComsQuickChatEntry")
	FSlateBrush Brush;

	UPROPERTY(EditAnywhere, Category="SquadComsQuickChatEntry")
	EFortWorldMarkerType MarkerType;

};

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortSquadComsPicker : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="CategoryChanged"))
	void BP_CategoryChanged(const int32 Direction);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="PageChanged"))
	void BP_PageChanged(const int32 Direction);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateNPCColor(const FSlateColor& UpdatedColor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateNPCName(const FText& UpdatedName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateWarningVisibility(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void PlaySelectionAnimation();

private:
	UPROPERTY(EditAnywhere, Category="Data")
	TObjectPtr<UAthenaQuickChatBank> RequestOptionsBank;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FSquadComsNPCCommandEntry> NPCCommandOptions;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FSquadComsNPCCommandEntry> WildlifeCommandOptions;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FSquadComsQuickChatEntry> QuickChatOptions;

	UPROPERTY(EditAnywhere, Category="Data")
	TObjectPtr<USoundBase> DismissConfirmSound;

	UPROPERTY(EditAnywhere, Category="Data")
	TObjectPtr<USoundBase> DefaultConfirmSound;

	UPROPERTY(EditAnywhere, Category="FortSquadComsPicker")
	FText DefaultMultiCompanionText;

	UPROPERTY(EditAnywhere, Category="FortSquadComsPicker")
	TSoftObjectPtr<UTexture2D> DefaultMultiCompanionPreviewImage;

	UPROPERTY(Transient)
	PingCommandType PingCommandSelected;

	UPROPERTY(Transient)
	EFortWorldMarkerType WorldMarkerSelected;

	UPROPERTY(EditAnywhere, Category="Categories")
	TMap<FGameplayTag, TSoftObjectPtr<UTexture2D>> CategoryIcons;

	UPROPERTY(EditAnywhere, Category="Categories")
	TArray<FFortSquadComsPickerSubCategoryIdentifier> SubCategoryIdentifiers;

	UPROPERTY()
	AFortPlayerState* AllyNPCPlayerState;

	UPROPERTY(EditAnywhere, Category="Content Display Settings")
	bool bShowSquadComsInSolo;

	UPROPERTY(Config)
	TArray<PingCommandType> BlockedPingCommandTypes;

	UPROPERTY(EditAnywhere, Category="Primary Content Settings")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(EditAnywhere, Category="Bindings")
	TArray<FDataTableRowHandle> QuickSelectBindings;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle PreviousWheelInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle NextWheelInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle PreviousCategoryInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle NextCategoryInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle DismissNPCInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle OnReleaseSelectInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PreviousWheel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NextWheel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTextButton> Button_CategoryMinusOne;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTextButton> Button_CategoryPlusOne;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_WheelLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_InGameChatBinding;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSquadComsPicker", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortPickerOverlay> PickerOverlay_SquadComs;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_Pagination;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDottedPagination> DottedPagination_Category;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Pagination;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_NPCIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NPCName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_PagesTutorial;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_UnavailableWarning;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_DismissNPC;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSquadComsPicker", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_DismissNPC;

	UPROPERTY(EditAnywhere, Category="Primary Content Settings")
	FGameplayTag PagesTutorialTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAutoRunNotificationWidget> Widget_AutoRunNotification;

	UPROPERTY(EditAnywhere, Category="Picker Orderings")
	TArray<ECardinalPoint> Ordering_Request;

	UPROPERTY(EditAnywhere, Category="Picker Orderings")
	TArray<ECardinalPoint> Ordering_NPCCommands;

	UPROPERTY(EditAnywhere, Category="Picker Orderings")
	TArray<ECardinalPoint> Ordering_SquadComs;

};

