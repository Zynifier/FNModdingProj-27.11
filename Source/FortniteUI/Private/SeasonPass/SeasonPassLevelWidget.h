// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "CommonActivatablePanelLegacy.h"
#include "SeasonPassLevelWidget.generated.h"

class AFortPlayerController;
class UAthenaSeasonItemDefinition;
class UFortItem;
class UFortSeasonPassLevelInfo;
enum class EAthenaSeasonRewardTrack : uint8;

UCLASS(BlueprintType, meta=(Category="Fortnite UI"))
class UFortSeasonPassLevelInfo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	bool ContainsChaseReward(EAthenaSeasonRewardTrack Track) const;

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	int32 GetLevel() const;

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	float GetLevelProgress() const;

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	int32 GetNumRewardItems(EAthenaSeasonRewardTrack Track) const;

	UFUNCTION(BlueprintCallable, Category="FortSeasonPassLevelInfo")
	TArray<UFortItem*> GetRewardItems(EAthenaSeasonRewardTrack Track);

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	int32 GetSeasonPassMaxLevel() const;

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	bool IsFreeClaimed() const;

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	bool IsFreeUnlocked() const;

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	bool IsPaidClaimed() const;

	UFUNCTION(BlueprintPure, Category="FortSeasonPassLevelInfo")
	bool IsPaidUnlocked() const;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> FortPC;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonItemDefinition> SeasonData;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItem>> FreeRewards;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItem>> PaidRewards;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class USeasonPassLevelPanel : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="SeasonPassLevelPanel")
	UFortSeasonPassLevelInfo* GetLevelInfo() const;

	UFUNCTION(BlueprintImplementableEvent, Category="SeasonPassLevelPanel")
	void OnLockedStatusChanged(bool FreeUnlocked, bool PaidUnlocked);

	UFUNCTION(BlueprintImplementableEvent, Category="SeasonPassLevelPanel")
	void OnSetup();

	UFUNCTION(BlueprintCallable, Category="SeasonPassLevelPanel")
	void Setup(UFortSeasonPassLevelInfo* Info);

private:
	UPROPERTY()
	TObjectPtr<UFortSeasonPassLevelInfo> LevelInfo;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class USeasonPassLevelWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="SeasonPassLevelWidget")
	void AttemptClaim();

	UFUNCTION(BlueprintPure, Category="SeasonPassLevelWidget")
	UFortSeasonPassLevelInfo* GetLevelInfo() const;

	UFUNCTION(BlueprintImplementableEvent, Category="SeasonPassLevelWidget")
	void OnAttemptClaimFinished(bool FreeClaimed, bool PaidClaimed);

	UFUNCTION(BlueprintImplementableEvent, Category="SeasonPassLevelWidget")
	void OnLockedStatusChanged(bool FreeUnlocked, bool PaidUnlocked);

	UFUNCTION(BlueprintImplementableEvent, Category="SeasonPassLevelWidget")
	void OnNavigateTo();

	UFUNCTION(BlueprintImplementableEvent, Category="SeasonPassLevelWidget")
	void OnSetup();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="SeasonPassLevelWidget")
	void PlayIntro();

private:
	UPROPERTY()
	TObjectPtr<UFortSeasonPassLevelInfo> LevelInfo;

};

