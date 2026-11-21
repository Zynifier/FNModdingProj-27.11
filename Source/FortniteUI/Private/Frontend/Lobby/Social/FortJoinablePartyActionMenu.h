// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "SocialInteractionMenu.h"
#include "FortJoinablePartyActionMenu.generated.h"

class UCommonButtonBase;
class UCommonRichTextBlock;
class UDynamicEntryBox;
class UFortJoinablePartyPortraitsDisplay;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortJoinablePartyActionMenu : public USocialInteractionMenu
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortJoinablePartyActionMenu")
	FColor SecondNameColor;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyActionMenu")
	uint32 SecondNameFontSize;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyActionMenu")
	uint8 MaxNamesToDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortJoinablePartyActionMenu")
	FColor InviteTextColor;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyActionMenu")
	FColor DimmerInviteColor;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyActionMenu")
	FColor DimmerDefaultColor;

	UPROPERTY(EditDefaultsOnly, Category="FortJoinablePartyActionMenu")
	FText OtherMemberNamesFormat;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_DisplayNames;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortJoinablePartyPortraitsDisplay> PartyPortraits;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_PartyPresence;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_PartyMembers;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_PartyMembers;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> SidebarBackButton;

};

