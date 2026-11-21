// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "Misc/Timespan.h"
#include "FortHabaneroInfoModal.generated.h"

class UAthenaScrollBox;
class UCommonButtonBase;
class UVerticalBox;

UCLASS(Config=Game, meta=(DisableNativeTick))
class UFortHabaneroInfoModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetGameType(const FString& GameMode);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Scroll Completed"))
	void BP_OnScrollCompleted(bool bScrolledDown);

	UFUNCTION(BlueprintImplementableEvent)
	void SetProgress(const FString& ProgressKey, const int32 CurrentHabanero, const int32 CurrentPosition, const float ProgressPercent);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTimerText(const FTimespan& Timespan);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTimerVisibility(const ESlateVisibility TimerVisibility);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortHabaneroInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> Vbox_Panels;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortHabaneroInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortHabaneroInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close_Alt;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortHabaneroInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortHabaneroInfoModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_Panels;

private:
	UPROPERTY(Config)
	bool bIsHabaneroTimerEnabled;

};

