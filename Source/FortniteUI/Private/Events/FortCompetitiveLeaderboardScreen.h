// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCompetitiveLeaderboardScreen.generated.h"

class UCommonBorder;
class UCommonWidgetSwitcherLegacy;
class UFortEventLeaderboardEntryData;
class UFortLeaderboardListViewWrapper;
class UFortLeaderboardViewTab;
class UHorizontalBox;
class UListView;
class UTextBlock;
enum class ELeaderboardDisplayType : uint8;

UENUM(BlueprintType)
enum class ELeaderboardDisplayType : uint8
{
	/* For the new leaderboard system this means that this leaderboard is related to the score location with bIsMainWindowLeaderboard set as true,
	 * while for the old leaderboard system it means that this leaderboard is the one related to the score location with scoreMode of type "window". */
	Default = 0,
	/* For the new leaderboard system this means that this leaderboard isn't the one related to the score location with bIsMainWindowLeaderboard set as true,
	 * while for the old leaderboard system it means that this leaderboard is the one related to a score location with scoreMode of type "floating". */
	Extra = 1,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCompetitiveLeaderboardScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	UFortEventLeaderboardEntryData* GetMyLeaderboardEntry();

	UFUNCTION(BlueprintCallable)
	void HandleLeaderboardSetInView();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardDisplayTypeChanged(ELeaderboardDisplayType NewDisplayType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardEntrySelected(const UFortEventLeaderboardEntryData* EntryData);

	UFUNCTION(BlueprintCallable)
	void RequestNextPage();

	UFUNCTION(BlueprintCallable)
	virtual void SetEvent(const FString& EventId, const FString& EventWindowId);

	UPROPERTY()
	TArray<TObjectPtr<UFortEventLeaderboardEntryData>> LeaderboardEntries;

	UPROPERTY(Transient)
	TObjectPtr<UFortEventLeaderboardEntryData> MyEntryData;

	UPROPERTY(Transient)
	TObjectPtr<UFortEventLeaderboardEntryData> EntryToShowDetails;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCompetitiveLeaderboardScreen")
	FString RepresentedEventId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortCompetitiveLeaderboardScreen")
	FString RepresentedEventWindowId;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCompetitiveLeaderboardScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLeaderboardViewTab> ActivatableContent_LeaderboardTab;

};

UCLASS(meta=(DisableNativeTick))
class UFortLeaderboardListViewWrapper : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardDisplayTypeChanged(ELeaderboardDisplayType NewDisplayType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardEntryAdded(ELeaderboardDisplayType NewDisplayType);

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> ListView_LeaderboardEntries;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Content_LoadingEntries;

};

UCLASS(meta=(DisableNativeTick))
class UFortLeaderboardViewTab : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UListView* GetListView() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardDisplayTypeChanged(ELeaderboardDisplayType NewDisplayType);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLeaderboardViewTab", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_DebugId;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLeaderboardViewTab")
	bool bDisplayTabHeaders;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_LeaderboardEntries;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLeaderboardViewTab", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLeaderboardListViewWrapper> ActivatableContent_LeaderboardListWrapper;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Content_NoLeaderboardEntries;

};

