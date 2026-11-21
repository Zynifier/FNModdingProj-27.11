// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaFrontEndMapPoiIcon.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaFrontEndMapPoiIcon : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleTextChanged(bool bIsRedacted);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFrontEndMapPoiIcon", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PoiName;

};

