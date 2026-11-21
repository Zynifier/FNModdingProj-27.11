// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "CommonActivatablePanelLegacy.h"
#include "AthenaProfileStatsBase.generated.h"

class UAthenaMatchStatView;
class UAthenaProfileStatBox;
class UAthenaSeasonStats;
class UFortMcpProfileAthenaStats;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UAthenaProfileStatsBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AthenaProfileStatsBase")
	FText GetCurrentPlaylistName() const;

	UFUNCTION(BlueprintPure, Category="AthenaProfileStatsBase")
	UAthenaSeasonStats* GetCurrentStatSet() const;

	UFUNCTION(BlueprintPure, Category="AthenaProfileStatsBase")
	FUniqueNetIdRepl GetUniqueID() const;

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatsBase")
	void NextPlaylist();

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatsBase")
	void NextStatSet();

	UFUNCTION(BlueprintPure, Category="AthenaProfileStatsBase")
	int32 NumStatSets() const;

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsBase")
	void OnDataRecieved();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsBase")
	void OnNoData();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsBase")
	void OnStartFetchingData();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaProfileStatsBase")
	void OnStatSetChanged();

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatsBase")
	void PrevStatSet();

	UFUNCTION(BlueprintCallable, Category="AthenaProfileStatsBase")
	void Setup(const FUniqueNetIdRepl& InUniqueId);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaProfileStatsBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaProfileStatBox> ProfileStatBox;

private:
	UFUNCTION()
	void OnProfileLoaded(UFortMcpProfileAthenaStats* ProfileAthenaStats);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaSeasonStats>> StatSets;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonStats> CurrentViewedStatSet;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaMatchStatView> CurrentStatView;

	UPROPERTY(Transient)
	FName CurrentPlaylist;

};

