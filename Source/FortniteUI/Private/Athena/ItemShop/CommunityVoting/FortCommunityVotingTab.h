// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCommunityVotingTab.generated.h"

class UCommonUserWidget;
class UFortEventDateTimeTextBlock;
class UHorizontalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingTab : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCommunityVotingTab")
	TSubclassOf<UCommonUserWidget> ContainedWidgetClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_LargeTile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventDateTimeTextBlock> DateTimeTextBlock_Countdown;

};

