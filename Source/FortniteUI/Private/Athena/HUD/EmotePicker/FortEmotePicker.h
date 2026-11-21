// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortEmotePicker.generated.h"

class AFortPlayerController;
class UCommonButtonLegacy;
class UCommonLazyImage;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortControllerComponent;
class UFortDottedPagination;
class UFortKeybindWidget;
class UFortPickerOverlay;
class UFortTextButton;
class UTexture2D;
class UUserWidget;
class UWidget;

USTRUCT()
struct FFortEmotePickerCategory
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortEmotePickerSubCategoryIdentifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortEmotePickerSubCategoryIdentifier")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, Category="FortEmotePickerSubCategoryIdentifier")
	FText Name;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEmotePicker : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetMultiEmoteIndex() const;

	UFUNCTION(BlueprintCallable)
	void SetMultiEmoteIndex(const int32 Index);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="CategoryChanged"))
	void BP_CategoryChanged(int32 Direction);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="ChangeElementVisibilitiesForFrontend"))
	void BP_ChangeElementVisibilitiesForFrontend();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="PageChanged"))
	void BP_PageChanged(int32 Direction);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="UpdateOverlayWidget"))
	void BP_UpdateOverlayWidget(TSubclassOf<UUserWidget> OverlayWidgetClass);

	UFUNCTION()
	void HandleExternalEmoteAdded(FName ActionName);

	UFUNCTION()
	void HandleExternalEmoteRemoved(FName ActionName);

	UFUNCTION()
	void OnControllerComponentAttached(AFortPlayerController* OwningController, UFortControllerComponent* ControllerComponent);

private:
	UPROPERTY(EditAnywhere, Category="Categories")
	TMap<FGameplayTag, TSoftObjectPtr<UTexture2D>> CategoryIcons;

	UPROPERTY(EditAnywhere, Category="Categories")
	TArray<FFortEmotePickerSubCategoryIdentifier> SubCategoryIdentifiers;

	UPROPERTY(EditAnywhere, Category="Primary Content Settings")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(EditAnywhere, Category="Bindings")
	TArray<FDataTableRowHandle> QuickSelectBindings;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle FrontEndOpenAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle PreviousWheelInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle NextWheelInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle PreviousCategoryInputAction;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle NextCategoryInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PreviousWheel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NextWheel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTextButton> Button_CategoryMinusOne;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTextButton> Button_CategoryMinusTwo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTextButton> Button_CategoryPlusOne;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTextButton> Button_CategoryPlusTwo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_WheelLabel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EmoteFrontend;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_InGameEmoteBinding;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> Image_CategoryIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmotePicker", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortPickerOverlay> PickerOverlay_EmoteWheel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VisibilitySwitcher_Pagination;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDottedPagination> DottedPagination_Category;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Pagination;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemDescription;

	UPROPERTY(Transient)
	int32 CurrentMultiEmoteIndex;

};

