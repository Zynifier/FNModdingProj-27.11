// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FrontEnd/IFortDebounceInterface.h"
#include "SidebarTagsEditorHeaderWidget.generated.h"

class UBorder;
class UCommonButtonBase;
class UCommonRichTextBlock;
class UFortSocialAvatarIcon;
class USidebarSocialTagListBase;
class USocialNameTextBlock;

UCLASS(Config=Game)
class USidebarTagsEditorHeaderWidget : public UCommonActivatableWidget, public IFortDebounceInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarTagsEditorHeaderWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_SocialAvatarIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarTagsEditorHeaderWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USocialNameTextBlock> Text_SocialName;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarTagsEditorHeaderWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_PlatformNames;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarTagsEditorHeaderWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USidebarSocialTagListBase> SidebarSocialTagList;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarTagsEditorHeaderWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> AddButton_1;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarTagsEditorHeaderWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> AddButton_2;

	UPROPERTY(BlueprintReadOnly, Export, Category="SidebarTagsEditorHeaderWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> AddButton_3;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_OnlineStatusIndicator;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_OnlineStatusOutline;

	UPROPERTY(Config)
	double DebounceSetTagsDurationSeconds;

};

