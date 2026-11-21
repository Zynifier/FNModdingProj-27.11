// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateBrush.h"
#include "QuestEditorButton.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UQuestEditorButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FText& GetText() const;

	UFUNCTION(BlueprintCallable)
	void SetText(const FText& InText);

protected:
	UPROPERTY(EditAnywhere, Category="Icon")
	bool bShowIcon;

	UPROPERTY(EditAnywhere, Category="QuestEditorButton")
	bool bIsEnabledWithoutValidAsset;

	UPROPERTY(EditAnywhere, Category="Icon", meta=(EditCondition="bShowIcon"))
	FName SlateIconName;

	UPROPERTY(EditAnywhere, Category="Icon", meta=(EditCondition="bShowIcon"))
	FSlateBrush IconBrush;

	UPROPERTY(EditAnywhere, Category="Text")
	FText Text;

	UPROPERTY(EditAnywhere, Category="Text")
	FSlateFontInfo Font;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Label;

};

