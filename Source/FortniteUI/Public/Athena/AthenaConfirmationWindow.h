// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "Engine/DataTable.h"
#include "Input/Events.h"
#include "Layout/Geometry.h"
#include "AthenaConfirmationWindow.generated.h"

class UBacchusCloseButton;
class UCommonBorder;
class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortLazyImage;
class UObject;
class UWidgetAnimation;

UENUM()
enum class EAthenaConfirmationResult : uint8
{
	Confirmed = 0,
	Declined = 1,
	Canceled = 2,
	Max_NONE = 3,
};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaConfirmationWindow : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetButtonText(UCommonButtonBase* Button, const FText& Text);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowConfirmationContent();

private:
	UFUNCTION()
	FEventReply HandleTapToCloseZoneMouseButtonDown(FGeometry MyGeometry, const FPointerEvent& MouseEvent);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaConfirmationWindow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaConfirmationWindow", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PostConfirmation;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaConfirmationWindow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaConfirmationWindow", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortLazyImage> Image_MainIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="CommonButtonBase"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Buttons;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBacchusCloseButton> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_TapToCloseZone;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaConfirmationWindow", meta=(AllowPrivateAccess, BindWidgetAnimOptional))
	TObjectPtr<UWidgetAnimation> BoundAnim_PostConfirm;

	UPROPERTY(EditDefaultsOnly, Category="AthenaConfirmationWindow", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CancelAction;

	UPROPERTY(EditDefaultsOnly, Category="AthenaConfirmationWindow")
	TSubclassOf<UCommonButtonBase> ConfirmButtonClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaConfirmationWindow")
	TSubclassOf<UCommonButtonBase> DeclineButtonClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaConfirmationWindow")
	TSubclassOf<UCommonButtonBase> CancelButtonClass;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Enable Design Time Preview"))
	bool bDesignTime_EnablePreview;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Title", EditCondition="bDesignTime_EnablePreview"))
	FString DesignTime_Title;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Rich Description", EditCondition="bDesignTime_EnablePreview"))
	FText DesignTime_RichDescription;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Confirm Button Text", EditCondition="bDesignTime_EnablePreview"))
	FString DesignTime_ConfirmButtonText;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Decline Button Text", EditCondition="bDesignTime_EnablePreview"))
	FString DesignTime_DeclineButtonText;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Cancel Button Text", EditCondition="bDesignTime_EnablePreview"))
	FString DesignTime_CancelButtonText;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Icon", EditCondition="bDesignTime_EnablePreview"))
	TSoftObjectPtr<UObject> DesignTime_Icon;
#endif

};

