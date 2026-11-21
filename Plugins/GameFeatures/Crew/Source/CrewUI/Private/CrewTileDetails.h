// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CrewTileDetails.generated.h"

class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCrewTileDetails : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="CrewTileDetails", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="CrewTileDetails", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="CrewTileDetailsTag"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Tags;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MobileMoreInfo;

};

