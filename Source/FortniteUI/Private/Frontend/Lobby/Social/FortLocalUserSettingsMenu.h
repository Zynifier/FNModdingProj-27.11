// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonActivatableWidget.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "FortLocalUserSettingsMenu.generated.h"

class UCommonRichTextBlock;
class UDynamicEntryBox;
class UFortLocalUserSettingTitleButton;
class UFortLocalUserSettingsSection;
class UImage;
class UMenuAnchor;

UCLASS(Abstract)
class UFortLocalUserSettingButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_DisplayName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_CurrentSelectedArrow;

};

UCLASS(Abstract)
class UFortLocalUserSettingTitleButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExpansionChanged(bool bIsExpanded);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLocalUserSettingTitleButton", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Title;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortLocalUserSettingsMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFocused();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLocalUserSettingsMenu")
	FColor SettingTextColor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMenuAnchor> OwningMenuAnchor;

private:
	UFUNCTION()
	void HandleMenuAnchorOpenChanged(bool bIsOpen);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLocalUserSettingsSection> Section_OnlineStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLocalUserSettingsSection> Section_Privacy;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLocalUserSettingsSection> Section_Participation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLocalUserSettingsSection> Section_VoiceChannel;

};

UCLASS(Abstract)
class UFortLocalUserSettingsSection : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortLocalUserSettingsSection(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLocalUserSettingTitleButton> TitleButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortLocalUserSettingButton"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Options;

};

