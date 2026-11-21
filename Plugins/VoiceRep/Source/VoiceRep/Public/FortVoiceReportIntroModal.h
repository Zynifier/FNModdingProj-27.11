// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortVoiceReportIntroModal.generated.h"

class UCommonTextBlock;
enum class UFortVoiceReportIntroModalType : uint8;

UENUM(BlueprintType)
enum class UFortVoiceReportIntroModalType : uint8
{
	IsFreshAccount = 0,
	IsUnder18 = 1,
	Over18VoiceChatEnabled = 2,
	Over18VoiceChatDisabled = 3,
};

UCLASS(meta=(DisableNativeTick))
class UFortVoiceReportIntroModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleTurnOffClicked();

	UFUNCTION(BlueprintCallable)
	void HandleTurnOnClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisuals(const UFortVoiceReportIntroModalType DescriptionType);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortVoiceReportIntroModal", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VoiceReportingTitle;

};

