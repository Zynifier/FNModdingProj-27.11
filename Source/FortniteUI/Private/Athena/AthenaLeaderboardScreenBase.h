// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaLeaderboardScreenBase.generated.h"

class UCommonBorder;
class UCommonButtonBase;
class UCommonRotator;
class UCommonTextBlock;
class UDataTable;
class UFortLeaderboardRowProxyInstance;
class UFortProfileStatsRow;
class UFortTabListWidgetBase_Legacy;
class UWidget;

UENUM(BlueprintType)
enum class EFortAthenaPlaylist : uint8
{
	/** Only 1 allowed in party*/
	AthenaSolo = 0,
	/** Party of 1 or 2 */
	AthenaDuo = 1,
	/** Party of 1-4 */
	AthenaSquad = 2,
};

USTRUCT(BlueprintType)
struct FAthenaPlaylistLeaderboardData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlaylistLeaderboardData")
	FName StatId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlaylistLeaderboardData")
	FText StatDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlaylistLeaderboardData", meta=(Multiline="true"))
	FText TabDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlaylistLeaderboardData")
	FText RowDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlaylistLeaderboardData")
	FString BaseGameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlaylistLeaderboardData")
	bool bIsGlobal;

};

USTRUCT(BlueprintType)
struct FAthenaLeaderboardData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaLeaderboardData")
	EFortAthenaPlaylist Playlist;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaLeaderboardData")
	FName PlaylistName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaLeaderboardData")
	ECommonInputType InputType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaLeaderboardData")
	TArray<FAthenaPlaylistLeaderboardData> Stats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaLeaderboardData")
	bool bExcludePlaylistNames;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaLeaderboardData")
	TArray<FString> PlaylistNames;

};

USTRUCT()
struct FPlaylistFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UDataTable> PlaylistsData;

};

USTRUCT()
struct FLeaderboardFilter : public FPlaylistFilter
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaLeaderboardScreenBase : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Leaderboards")
	bool CanShowFriendsOnlyLeaderboard() const;

	UFUNCTION(BlueprintCallable, Category="Leaderboards")
	void OnActiveLeaderboardTabChanged(int32 ActiveWidgetIndex);

	UFUNCTION(BlueprintCallable, Category="Leaderboards")
	void OnFriendsFilterChanged(int32 FriendsFilterIndex);

	UFUNCTION(BlueprintCallable, Category="Leaderboards")
	void OnMatchTypeChanged(int32 MatchTypeIndex);

	UFUNCTION(BlueprintCallable, Category="Leaderboards")
	void OnPlaylistChanged(const FName NewPlaylistName, const ECommonInputType NewInputType);

	UFUNCTION(BlueprintImplementableEvent, Category="Leaderboards")
	void OnQueryFinished();

	UFUNCTION(BlueprintImplementableEvent, Category="Leaderboards")
	void OnQueryStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="Leaderboards")
	void OnUpdateLeaderboardListUI(bool bWasSuccessful, UFortLeaderboardRowProxyInstance* LocalUserRow, const FText& QueryErrorStr);

	UFUNCTION(BlueprintImplementableEvent, Category="Leaderboards")
	void OnUpdateListHeader(const FAthenaPlaylistLeaderboardData& PlaylistTabData);

	UFUNCTION(BlueprintImplementableEvent, Category="Leaderboards")
	void OnUpdateTabButtonText(UCommonButtonBase* Button, const FAthenaPlaylistLeaderboardData& PlaylistTabData);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> LeaderboardTabList;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRotator> MatchRotator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRotator> LeaderboardTypeRotator;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> RefreshTimeText;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> NoDataMessageText;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> BorderLocalUserFocus;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_ProfileStats;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsRow> AthenaStats_Wins;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsRow> AthenaStats_SecondTierFinishes;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsRow> AthenaStats_ThirdTierFinishes;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsRow> AthenaStats_Eliminations;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLeaderboardScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsRow> AthenaStats_MatchesPlayer;

	UPROPERTY(EditAnywhere, Category="AthenaLeaderboardScreenBase")
	FName LTMPlaylistDefaultName;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UFortProfileStatsRow>> ActiveProfileRows;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Leaderboards")
	TObjectPtr<UDataTable> PlaylistsData;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="AthenaLeaderboardScreenBase", meta=(EditInline="true"))
	TMap<FName, TObjectPtr<UCommonButtonBase>> ActiveTabButtons;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaLeaderboardScreenBase")
	TArray<TObjectPtr<UFortLeaderboardRowProxyInstance>> RowProxies;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaLeaderboardScreenBase")
	TObjectPtr<UFortLeaderboardRowProxyInstance> LocalUserRowProxy;

	UPROPERTY(Transient)
	FLeaderboardFilter CurrentLeaderboardFilter;

	UPROPERTY(EditDefaultsOnly, Category="AthenaLeaderboardScreenBase")
	FDataTableRowHandle BackAction;

};

