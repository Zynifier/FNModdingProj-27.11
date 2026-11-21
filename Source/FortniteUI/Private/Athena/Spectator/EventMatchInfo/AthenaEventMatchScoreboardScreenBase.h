// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UITag.h"
#include "Athena/Spectator/EventMatchInfo/AthenaEventScreenBase.h"
#include "AthenaEventMatchScoreboardScreenBase.generated.h"

class UAthenaRemoteSquadViewData;
class UCommonListView;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaEventMatchScoreboardScreenBase : public UAthenaEventScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetSquadIdsVisible_BP(bool bSquadIdsVisible);

private:
	UFUNCTION()
	void HandleSquadEliminated(UAthenaRemoteSquadViewData* InSquadData);

	UFUNCTION()
	void HandleSquadKillScoreChanged(UAthenaRemoteSquadViewData* InSquadData, int32 InKillScore);

	UPROPERTY(EditAnywhere, Category="AthenaEventMatchScoreboardScreenBase")
	FUIActionTag SortByElimsAction;

	UPROPERTY(EditAnywhere, Category="AthenaEventMatchScoreboardScreenBase")
	FUIActionTag SortByPlaceAction;

	UPROPERTY(EditDefaultsOnly, Category="Event Match Scoreboard Input", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SortByEliminationsActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="Event Match Scoreboard Input", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SortByPlaceActionRowHandle;

	UPROPERTY()
	TArray<TObjectPtr<UAthenaRemoteSquadViewData>> SquadDataArray;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ScoreboardListView;

};

