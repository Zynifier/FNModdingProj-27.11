// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortEventTeamMatchHistoryModal.generated.h"

class UCommonBorder;
class UCommonListView;
class UCommonTextBlock;
class UFortEventLeaderboardEntryData;
class UFortEventTeamMatchHistoryEntryData;
class UFortEventTeamMatchHistoryStat;
class UOverlay;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventTeamMatchHistoryEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MatchNumber;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeAlive;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Eliminations;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Placement;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreativeScore;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_OnlineStatus;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_InteractionContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Icon_Eliminations;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Icon_Placement;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Icon_CreativeScore;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat0;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat2;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat3;

	UPROPERTY(Transient)
	TObjectPtr<UFortEventTeamMatchHistoryEntryData> MatchData;

};

UCLASS(BlueprintType)
class UFortEventTeamMatchHistoryEntryData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	int32 MatchNumber;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	int32 Eliminations;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	int32 CreativeScore;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	TArray<int32> AlternativeStats;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	int32 Placement;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	int32 SecondsAlive;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	bool bShowEliminations;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	bool bIsLive;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	bool bIsReplayAvailable;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	FString SessionId;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	TArray<FString> TeamAccountIds;

	UPROPERTY(BlueprintReadOnly, Category="FortEventTeamMatchHistoryEntryData")
	bool bIsScoreContributor;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventTeamMatchHistoryModal : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupMatchHistory(const FString& TournamentId, const FString& EventWindowId);

	UFUNCTION(BlueprintCallable)
	void SetupMatchHistory(const UFortEventLeaderboardEntryData* DataForDisplay, const FString& TournamentId, const FString& EventWindowId, const FString& LeaderboardGroupingKey, const FString& LeaderboardInstanceId);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_MatchHistory;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TeamNames;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat0;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat1;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat2;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEventTeamMatchHistoryModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventTeamMatchHistoryStat> Widget_AltStat3;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortEventTeamMatchHistoryModal")
	TObjectPtr<UFortEventLeaderboardEntryData> LeaderboardEntryData;

private:
	UPROPERTY()
	TObjectPtr<UFortEventTeamMatchHistoryEntryData> LastClickedMatchHistoryEntry;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventTeamMatchHistoryStat : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortEventTeamMatchHistoryStat(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortEventTeamMatchHistoryStat", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Icon;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortEventTeamMatchHistoryStat", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Widget_Score;

};

