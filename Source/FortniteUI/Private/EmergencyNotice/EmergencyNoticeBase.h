// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "EmergencyNoticeBase.generated.h"

class UBorder;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEmergencyNoticeBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="EmergencyNoticeBase")
	void HideNotice();

	UFUNCTION(BlueprintImplementableEvent, Category="EmergencyNoticeBase")
	void ShowNotice(const FText& Title, const FText& Body);

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_TestBG;

};

