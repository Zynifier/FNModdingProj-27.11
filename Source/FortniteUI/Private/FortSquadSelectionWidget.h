// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortSquadSelectionWidget.generated.h"

class UAthenaTeamSquadsEntryBox;
class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UOverlay;
class UWidgetSwitcher;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSquadSelectionMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerParticipationChanged(bool bIsParticipating);

private:
	UFUNCTION(BlueprintCallable)
	void HandleExitAction();

	UFUNCTION()
	void HandleMemberEntryClicked(UCommonButtonLegacy* MemberEntryButton, int32 EntryIdx);

	UPROPERTY(EditAnywhere, Category="FortSquadSelectionMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ExitInputAction;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaTeamSquadsEntryBox> TeamEntryBox_Squads;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ConfirmMove;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CancelMove;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ActionPrompt;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSquadSelectionMenu", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ChangeParticipation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_Buttons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Mobile_Overlay;

};

