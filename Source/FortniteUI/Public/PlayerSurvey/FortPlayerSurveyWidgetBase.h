// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "PlayerSurvey/FortPlayerSurveyQuestion.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortPlayerSurveyWidgetBase.generated.h"

class UCanvasPanel;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortPlayerSurveyResponseWidget;
class URichTextBlock;
class UWidgetSwitcher;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPlayerSurveyWidgetBase : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_Question;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> CanvasPanel_ResponseFrame;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Skip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_NextButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NextQuestion;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Submit;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestionCount;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerSurveyWidgetBase", meta=(AllowPrivateAccess="true", RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DeselectInputAction;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerSurveyWidgetBase", meta=(AllowPrivateAccess="true", RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ExitInputAction;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerSurveyWidgetBase", meta=(AllowPrivateAccess="true"))
	TMap<EFortPlayerSurveyQuestionType, TSubclassOf<UFortPlayerSurveyResponseWidget>> ResponseWidgetMap;

	UPROPERTY(EditDefaultsOnly, Category="Primary Content Settings")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<EFortPlayerSurveyQuestionType, TObjectPtr<UFortPlayerSurveyResponseWidget>> ResponseWidgetInstances;

};

