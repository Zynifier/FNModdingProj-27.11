// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "AthenaItemShopNavigationButton.generated.h"

class UCommonTextBlock;

UCLASS()
class UAthenaItemShopNavigationButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Section;

};

