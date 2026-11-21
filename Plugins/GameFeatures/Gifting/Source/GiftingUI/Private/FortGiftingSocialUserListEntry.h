// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "FortGiftingSocialUserListEntry.generated.h"

class UAthenaGiftingPriceWidget;
class UCommonRichTextBlock;
class UFortSocialAvatarIcon;
class USocialNameTextBlock;
enum class ERecipientPresentationMode : uint8;

UENUM(BlueprintType)
enum class ERecipientPresentationMode : uint8
{
	Loading = 0,
	GiftPrice = 1,
	AlreadyOwned = 2,
	Unavailable = 3,
};

UCLASS(Abstract)
class UFortGiftingSocialUserListEntry : public USocialListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnHighlightedStateChanged(bool bInIsHighlighted, bool bPlayAnimation);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnTouchSelectionConfirmed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRecipientStatusUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUserItemSet();

	UFUNCTION(BlueprintImplementableEvent)
	void SetPresentationMode(ERecipientPresentationMode Mode);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_MemberIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortGiftingSocialUserListEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USocialNameTextBlock> Text_SocialName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_EligibilityStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_OwnedItems;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortGiftingSocialUserListEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingPriceWidget> Widget_Price;

};

