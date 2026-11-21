// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortHighlightWidget.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, Config=Game)
class UFortHighlightWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortHighlightWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowNotification(bool bShowNotification);

private:
	UPROPERTY(Config)
	bool bDisableHighlightNotification;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

};

