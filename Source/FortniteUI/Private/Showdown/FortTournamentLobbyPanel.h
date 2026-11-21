// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Showdown/FortShowdownDetailView.h"
#include "FortTournamentLobbyPanel.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortTournamentModal;
class UTextBlock;

UCLASS(Abstract)
class UFortTournamentLobbyPanel : public UFortShowdownDetailView
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool UsesScheduledMatchmaking() const;

	UPROPERTY(EditAnywhere, Category="FortTournamentLobbyPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle EventDetailsAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTournamentLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EventDetails;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="FortTournamentLobbyPanel")
	TSubclassOf<UFortTournamentModal> TournamentModalClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTournamentLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeRemainingScheduledMatch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTournamentLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ScheduledMatchInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTournamentLobbyPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_DebugLBId;

};

