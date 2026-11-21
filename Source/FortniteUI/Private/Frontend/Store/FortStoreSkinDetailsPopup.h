// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortStoreSkinDetailsPopup.generated.h"

class UCommonRichTextBlock;
class UDataTable;

USTRUCT(BlueprintType)
struct FOfferPopUpData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="OfferPopUpData")
	FText FormatedText;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortStoreSkinDetailsPopup : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void RequestFadeIn();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void RequuestFadeOut();

private:
	UPROPERTY(EditAnywhere, Category="Data")
	TObjectPtr<UDataTable> OfferTagTable;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ItemPrompt;

};

