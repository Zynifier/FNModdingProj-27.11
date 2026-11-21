// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "FortSidebarButtons.generated.h"

class UBorder;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortBangWrapper_NUI;
class UFortSocialSidebarButton;
class UFortSocialSidebarLocalUserButton;
class UImage;
class UMaterialInstance;
class UScaleBox;
class UTexture2D;
class UWidget;

UENUM()
enum class EFortSidebarButtonType : uint8
{
	PartyUp = 0,
	FindFriends = 1,
	VoiceChat = 2,
	Settings = 3,
	YourProfile = 4,
	Tags = 5,
	Exit = 6,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSidebarButtons : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UWidget* GetFocusedSidebarButton() const;

	UFUNCTION(BlueprintPure)
	UWidget* GetHoveredSidebarButton() const;

	UFUNCTION(BlueprintPure)
	UWidget* GetSelectedSidebarButton() const;

private:
	UFUNCTION()
	void HandleButtonGroupOnHoveredChanged(UCommonButtonLegacy* HoveredButton, const int32 ButtonIdx);

	UFUNCTION()
	void HandleNextTabAction_STW(bool& bPassThrough);

	UFUNCTION()
	void HandlePrevTabAction_STW(bool& bPassThrough);

	UFUNCTION()
	void HandleSettingsSavedTabChanged(const bool IsTabSaved);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialSidebarButton> Button_PartyUp;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialSidebarButton> Button_FindFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialSidebarButton> Button_VoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialSidebarButton> Button_UserSettings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialSidebarButton> Button_Exit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialSidebarLocalUserButton> Button_UserProfile;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialSidebarButton> Button_Tags;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_SocialButtons;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CurrentlyHovered;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> Button_CurrentlyFocused;

	UPROPERTY(EditAnywhere, Category="FortSidebarButtons", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, Category="FortSidebarButtons", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

};

UCLASS(Abstract)
class UFortSocialSidebarButtonBase : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortSocialSidebarButtonBase")
	EFortSidebarButtonType ButtonType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSocialSidebarButtonBase")
	FLinearColor Color_SkewBox_Selected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSocialSidebarButtonBase")
	FLinearColor Color_SkewBox_Hover;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarButtonBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_SkewBox;

	UPROPERTY(EditAnywhere, Category="FortSocialSidebarButtonBase")
	int32 NumberToShow;

	UPROPERTY(EditAnywhere, Category="FortSocialSidebarButtonBase")
	bool bShowBang;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBangWrapper_NUI> BangWrapper;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialSidebarButton : public UFortSocialSidebarButtonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSocialSidebarButton")
	FLinearColor Color_ContentSelected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSocialSidebarButton")
	FLinearColor Color_ContentUnselected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSocialSidebarButton")
	FLinearColor Color_ContentHovered;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_TabIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_TabIcon_Selected;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Number;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Number_Selected;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_Number;

private:
	UPROPERTY(EditAnywhere, Category="FortSocialSidebarButton")
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, Category="FortSocialSidebarButton")
	TObjectPtr<UTexture2D> Icon_FeatureDisabled;

	UPROPERTY(EditAnywhere, Category="FortSocialSidebarButton")
	TObjectPtr<UMaterialInstance> Material_Icon;

	UPROPERTY(EditAnywhere, Category="FortSocialSidebarButton")
	TObjectPtr<UMaterialInstance> Material_Icon_FeatureDisabled;

};

