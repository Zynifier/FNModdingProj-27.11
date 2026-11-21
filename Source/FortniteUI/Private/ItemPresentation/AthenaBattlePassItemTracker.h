// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaBattlePassItemTracker.generated.h"

class UCommonNumericTextBlock;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaBattlePassItemTracker : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInterpStarted();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInterpEnded(UCommonNumericTextBlock* NumericTextBlock, const bool HadCompleted);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassItemTracker", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Category;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBattlePassItemTracker", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> Text_Counter;

};

