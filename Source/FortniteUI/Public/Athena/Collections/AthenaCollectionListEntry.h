// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonButtonLegacy.h"
#include "AthenaCollectionListEntry.generated.h"

class UCommonTextBlock;
class UImage;
class UObject;
enum class EFortCollectedState : uint8;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCollectionListEntry : public UCommonButtonLegacy, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Friend Stats Set"))
	void BP_OnCollectedByFriendSet(bool bCollectedByFriend);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Collection State Set"))
	void BP_OnCollectionStateSet(EFortCollectedState CollectedState);

	UFUNCTION(BlueprintImplementableEvent, meta=(Displayname="On Entry Icon Loaded"))
	void BP_OnEntryIconLoaded(UObject* EntryIcon);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Entry Image Set"))
	void BP_OnEntryImageSet();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Entry Reset"))
	void BP_OnEntryReset();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionListEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionListEntry", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_SecondaryIcon;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionListEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Number;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionListEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

};

