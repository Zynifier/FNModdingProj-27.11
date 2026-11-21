// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/TopBar/FortTopBarTabButton.h"
#include "FortTopBarTabTextIconButton.generated.h"

class UCommonTextBlock;
class UFortBangWrapper_NUI;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTopBarTabTextIconButton : public UFortTopBarTabButton
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortTopBarTabTextIconButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortBangWrapper_NUI> BangWrapper;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTopBarTabTextIconButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_MobileIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTopBarTabTextIconButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisplayName;

};

