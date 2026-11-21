// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaMatchmakingViolator.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaMatchmakingViolator : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MainText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SubText;

	UPROPERTY(EditInstanceOnly, Category="First Time User", meta=(DisplayName="Dialog Name"))
	FName FirstTimeUser_DialogName;

	UPROPERTY(EditInstanceOnly, Category="First Time User", meta=(DisplayName="Main Text"))
	FText FirstTimeUser_MainText;

	UPROPERTY(EditInstanceOnly, Category="First Time User", meta=(DisplayName="Sub Text"))
	FText FirstTimeUser_SubText;

};

