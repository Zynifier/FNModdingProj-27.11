// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonActivatableWidget.h"
#include "UObject/NoExportTypes.h"
#include "CommonButtonLegacy.h"
#include "FortTournamentLiveGames.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortTournamentLiveGameSessionData;
class UListView;
class USocialUser;

UCLASS()
class UFortTournamentLiveGameSessionData : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<USocialUser>> UserInfo;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortTournamentLiveGameSessionEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEntrySet(int32 EntryIndex);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_GameTimeDuration;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTournamentLiveGames : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void NotifyLoadingMoreGames(bool bIsLoading);

	UFUNCTION(BlueprintImplementableEvent)
	void NotifyNoLiveGames();

	UFUNCTION(BlueprintCallable)
	void OnViewLiveGames();

	UFUNCTION(BlueprintCallable)
	void SetTournamentIds(const FString& InTournamentId, const FString& InEventWindowId);

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortTournamentLiveGameSessionData>> LiveSessions;

	UPROPERTY(Transient)
	TObjectPtr<UFortTournamentLiveGameSessionData> SelectedGame;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortTournamentLiveGameSessionEntry"))
	TObjectPtr<UListView> ListView_SessionEntries;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_WatchGame;

};

