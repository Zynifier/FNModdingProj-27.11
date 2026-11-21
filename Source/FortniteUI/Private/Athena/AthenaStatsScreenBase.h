// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaStatsScreenBase.generated.h"

class UCommonButtonBase;
class UCommonTabListWidgetBase;
class UCommonTextBlock;
class UDataTable;
class UFortFlagImage;
class UFortFlagSelectionModal;
class UFortProfileStatsMainTile;
class UFortProfileStatsRow;
class UImage;
class USocialUser;
class UWidget;
class UWidgetSwitcher;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaStatsScreenBase : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Stats")
	void DisplayQueriedUserPlatformProfile();

	UFUNCTION(BlueprintImplementableEvent, Category="Stats")
	void OnQueryFinished(bool bWasSuccessful, bool bHasStatsToDisplay);

	UFUNCTION(BlueprintImplementableEvent, Category="Stats")
	void OnQueryStarted();

	UFUNCTION(BlueprintCallable, Category="Stats")
	void OnTabSelected(FName TabName);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void SetAccountIdToQueryFromString(const FString& InAccountId);

	UFUNCTION(BlueprintCallable, Category="Stats")
	void SetDisplayName(FText InDisplayName);

	UFUNCTION(BlueprintImplementableEvent, Category="Stats")
	void SetPlatformButtonText(const FText& PlatformButtonText);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTabListWidgetBase> StatsTabList;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsMainTile> WinsTile;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsMainTile> SecondTierTile;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsMainTile> ThirdTierTile;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsRow> KillsRow;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProfileStatsRow> MatchesPlayedRow;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> LastUpdatedTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> SeasonContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> AccountContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> MainStatsContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> PlatformButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlatformIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> LTM_Disclaimer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ChangeFlag;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> Image_YourFlag;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> Image_OtherUserFlag;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaStatsScreenBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_FlagDisplay;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaStatsScreenBase")
	bool bWasLastQuerySuccessful;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Leaderboards")
	TObjectPtr<UDataTable> PlaylistsData;

	UPROPERTY(EditAnywhere, Category="AthenaStatsScreenBase")
	FName LTMPlaylistDefaultName;

	UPROPERTY(EditAnywhere, Category="AthenaStatsScreenBase")
	TSubclassOf<UFortFlagSelectionModal> FortFlagSelectionModalClass;

	UPROPERTY(Config)
	FText PlatformButtonDisplayText;

private:
	UPROPERTY(Transient)
	TObjectPtr<USocialUser> QueriedSocialUser;

	UPROPERTY(EditDefaultsOnly, Category="AthenaStatsScreenBase")
	FDataTableRowHandle BackAction;

};

