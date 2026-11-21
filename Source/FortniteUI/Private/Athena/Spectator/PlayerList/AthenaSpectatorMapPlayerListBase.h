// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Athena/Spectator/PlayerList/AthenaSpectatorPlayerListBase.h"
#include "AthenaSpectatorMapPlayerListBase.generated.h"

class UAthenaMapLayer;
class UAthenaRemotePlayerViewData;
class UCommonButtonLegacy;

UENUM(BlueprintType)
enum class ESpectatorMapPlayerListState : uint8
{
	Default = 0,
	Irrelevant = 1,
	Eliminated = 2,
};

UCLASS(Abstract)
class UAthenaSpectatorMapPlayerListBase : public UAthenaSpectatorPlayerListBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Squad Id Visibility Changed"))
	void BP_HandleSquadIdVisibilityChanged(bool bSquadIdsVisible);

private:
	UFUNCTION()
	void OnPlayerEliminatedStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsEliminated);

	UFUNCTION()
	void OnPlayerIsInRelevancyChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsInRelevancy);

	UFUNCTION()
	void OnPlayerKillScoreChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InKillScore);

	UFUNCTION()
	void OnPlayerNameChanged(UAthenaRemotePlayerViewData* InPlayerData, const FString& InPlayerName);

	UFUNCTION()
	void OnPlayerSquadIdChanged(UAthenaRemotePlayerViewData* InPlayerData, uint8 InSquadId);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Squad IDs Visible"))
	bool bDesignTime_ShowSquadIds;
#endif

	UPROPERTY(EditAnywhere, Category="AthenaSpectatorMapPlayerListBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleOnlyShowMapPlayersRowHandle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SortBySquadId;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SortByPlayerName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SortByEliminations;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SortByEventScore;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SortByState;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMapLayer> MapLayer;

};

