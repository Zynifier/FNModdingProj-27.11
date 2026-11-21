// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDLayoutToolV2_QuickbarProxySlot.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract)
class UHUDLayoutToolV2_QuickbarProxySlot : public UUserWidget
{
	GENERATED_BODY()

public:
	UHUDLayoutToolV2_QuickbarProxySlot(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_SlotIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SlotNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LockIcon;

};

