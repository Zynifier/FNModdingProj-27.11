// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_LinkAcrossPanel.generated.h"

class UBacchusCloseButton;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortMobileHUDWidgetRegistry;
class UHUDLayoutToolV2_Button;
class UHUDLayoutToolV2_LinkAcrossActionPanel;
class UHUDLayoutToolV2_LinkAcrossPanelTitle;
class UHUDLayoutToolV2_LinkAcrossWarningIndicator;
class UHUDLayoutToolV2_TooltipLayer;
class USizeBox;
class UVerticalBox;

UENUM(BlueprintType)
enum class ELinkAcrossSimpleAction : uint8
{
	AddToAll = 0,
	RemovedFromAll = 1,
	Custom = 2,
	Nothing = 3,
};

USTRUCT()
struct FSimpleActionMessages
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SimpleActionMessages")
	ELinkAcrossSimpleAction SimpleActionType;

	UPROPERTY(EditAnywhere, Category="SimpleActionMessages")
	FText SimpleActionTitle;

	UPROPERTY(EditAnywhere, Category="SimpleActionMessages")
	FText SimpleActionBody;

};

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_LinkAcrossPanel : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDWidgetRegistry> HUDWidgetRegistry;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_TooltipLayer> TooltipLayer;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LinkAcrossPanel")
	TArray<FSimpleActionMessages> SimpleActionMessages;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LinkAcrossPanelTitle> LinkAcrossPanelTitle_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBacchusCloseButton> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Actions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_ActionPanelContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LinkAcrossActionPanel> LinkAcrossActionPanel_Actions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_SimpleAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SimpleAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SimpleActionWarning;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ToggleAdvanced;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LinkAcrossWarningIndicator> WarningIndicator_MainWarning;

};

