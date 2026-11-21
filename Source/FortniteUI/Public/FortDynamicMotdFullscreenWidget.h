// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "MotdWidgetBase.h"
#include "FortDynamicMotdFullscreenWidget.generated.h"

class UAthenaScrollBox;
class UMotdViewModel;
enum class EButtonAction : uint8;

UENUM(BlueprintType)
enum class EButtonAction : uint8
{
	NextTile = 0,
	PreviousTile = 1,
	Close = 2,
};

UCLASS(BlueprintType, Blueprintable)
class UFortDynamicMotdFullscreenWidget : public UMotdWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType NewInputType);

	UFUNCTION(BlueprintCallable)
	void OnButtonPressed(const EButtonAction ButtonPressed);

	UFUNCTION(BlueprintCallable)
	void OnMotdShown();

	UFUNCTION()
	void OnScrollInput(const float ScrollDirection);

	UFUNCTION(BlueprintCallable)
	void SetCurrentMotd(const int32 Index);

	UFUNCTION(BlueprintImplementableEvent)
	void SwipeLeft();

	UFUNCTION(BlueprintImplementableEvent)
	void SwipeRight();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDynamicMotdFullscreenWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox;

	UPROPERTY(BlueprintReadOnly, Category="FortDynamicMotdFullscreenWidget")
	TObjectPtr<UMotdViewModel> CurrentMotd;

};

