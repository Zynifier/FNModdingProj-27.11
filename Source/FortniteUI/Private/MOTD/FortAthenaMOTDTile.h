// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonButtonLegacy.h"
#include "MOTD/FortAthenaMOTDWidget.h"
#include "FortAthenaMOTDTile.generated.h"

class UCommonBorder;
class UEpicCMSImage;
class URichTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortAthenaMOTDTile : public UCommonButtonLegacy, public IUserListEntry, public IFortAthenaMOTDNewsChildren
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> CMSImage_NewsImage;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaMOTDTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_NewsTitle;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaMOTDTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_AdSpace;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaMOTDTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_AdSpace;

};

