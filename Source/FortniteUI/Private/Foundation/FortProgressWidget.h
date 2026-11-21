// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Styling/SlateBrush.h"
#include "FortProgressWidget.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetDescription(FText Description);

	UFUNCTION(BlueprintCallable)
	void SetIcon(FSlateBrush IconBrush);

	UFUNCTION(BlueprintCallable)
	void SetTitle(FText Title);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_MainIcon;

};

