// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "SocialListEntryEmptyPanelBase.generated.h"

class UCommonRichTextBlock;
class UFortCTAButton;
class UImage;
class USidebarListEmptyPanelButton;

UCLASS()
class FORTNITEUI_API USocialListEntryEmptyPanelBase : public USocialListEntryBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ButtonClicked();

	UFUNCTION(BlueprintCallable)
	void ButtonSecClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateText(const FText& Title, const FText& Description, const FText& ButtonText, const FText& ButtonSecText);

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialListEntryEmptyPanelBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> EmptyListImage;

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialListEntryEmptyPanelBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> EmptyListDescription;

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialListEntryEmptyPanelBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> EmptyListTitle;

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialListEntryEmptyPanelBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<USidebarListEmptyPanelButton> ButtonWidget;

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialListEntryEmptyPanelBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<USidebarListEmptyPanelButton> ButtonWidgetSec;

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialListEntryEmptyPanelBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> WBP_UIKit_Button_Regular;

};

