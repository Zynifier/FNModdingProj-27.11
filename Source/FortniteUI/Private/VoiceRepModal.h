// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonActivatablePanelLegacy.h"
#include "VoiceRepModal.generated.h"

class UDynamicEntryBox;
class UVoiceRepModalPanelContainer;
enum class EVoiceRepUploadRecordResult : uint8;

UCLASS(meta=(DisableNativeTick))
class UVoiceRepModal : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BeginReportingFlow();

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="VoiceRepModal", meta=(AllowPrivateAccess="true", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UVoiceRepModalPanelContainer> WBP_StepWizard_Base;

};

UCLASS(meta=(DisableNativeTick))
class UVoiceRepModalPanelContainer : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleCloseButtonClicked();

};

UCLASS(meta=(DisableNativeTick))
class UVoiceRepPanel_Reporting : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void CompleteReport(const bool bSucceeded);

	UFUNCTION(BlueprintImplementableEvent)
	void EnableSubmission();

	UFUNCTION(BlueprintImplementableEvent)
	void ReportIsReadyToSubmit(const EVoiceRepUploadRecordResult Result);

	UFUNCTION(BlueprintCallable)
	void SubmitReport();

	UPROPERTY(BlueprintReadOnly, Export, Category="VoiceRepPanel_Reporting", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ChannelPortraits;

};

