// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCreativeCreditsSectionTitle.generated.h"

class UCommonTextBlock;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeCreditsSectionTitle : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SetTitleText(const FText& TitleText) const;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonTextBlock* Text_Title;

};

