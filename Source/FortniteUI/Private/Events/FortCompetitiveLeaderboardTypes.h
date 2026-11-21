// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "FortCompetitiveLeaderboardTypes.generated.h"

class UCommonTextBlock;
class UDynamicEntryBox;
class UFortEventLeaderboardEntryData;
class UFortFlagImage;
class UTexture2D;
class UUserWidget;

UCLASS(Abstract)
class UFortEventLeaderboardEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void DisplayTeamUsernames(const UFortEventLeaderboardEntryData* LeaderboardEntryData);

	UFUNCTION(BlueprintImplementableEvent)
	void InitializeTeamTextEntry(UUserWidget* TeamEntryWidget, const FText& Usernames);

	UFUNCTION(BlueprintCallable)
	void SetPlayerFlag(TSoftObjectPtr<UTexture2D> PlayerFlag);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> FlagImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_TeamEntries;

};

UCLASS(BlueprintType)
class UFortEventLeaderboardEntryData : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool DoesLeaderboardHaveQualifiedIcons() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	float GetAverageMatchScore() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	float GetAveragePlacement() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	float GetAverageTrackedStat(const FString& TrackedStatName) const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	FString GetEventId() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	FString GetEventWindowId() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	bool GetIsMatchPointWinner() const;

	UFUNCTION(BlueprintPure)
	FString GetLiveSessionId() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetNumTeammates() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetPageIndex() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetRank() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetScore() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	const FString GetTeamAccountId(int32 Index) const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	FText GetTeamDisplayNameText() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	void GetTeammateDisplayNames(TArray<FString>& DisplayNames) const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetTotalEliminations() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetTotalMatchesPlayed() const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetTotalPointsForCategory(FName ScoreCategoryId) const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetTotalTrackedStat(const FString& TrackedStatName) const;

	UFUNCTION(BlueprintPure, Category="LeaderboardEntryData")
	int32 GetTotalVictoryRoyales() const;

	UFUNCTION(BlueprintPure)
	bool ShouldShowQualifiedIcon() const;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEventLeaderboardTeammateEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardEntryDeselected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardEntrySelected();

	UFUNCTION(BlueprintCallable)
	void SetPlayerFlag(TSoftObjectPtr<UTexture2D> PlayerFlag);

	UFUNCTION(BlueprintCallable)
	void SetPlayerName(const FString& PlayerName);

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> IdentityFlag;

};

