// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Styling/SlateBrush.h"
#include "UObject/NoExportTypes.h"
#include "STW/FortHomebase/FortHomeBaseInfo.h"
#include "FortUITeamInfo.generated.h"

class AFortPlayerState;
class UFortItem;
class UFortPartyContext;
class UFortRegisteredPlayerInfo;
class UObject;

USTRUCT(BlueprintType)
struct FFortTeamMemberInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTeamMemberInfo")
	FUniqueNetIdRepl MemberUniqueId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTeamMemberInfo")
	FUniqueNetIdRepl PartyLeaderUniqueId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTeamMemberInfo")
	FUniqueNetIdRepl ConsoleUniqueId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortTeamMemberInfo")
	FString Platform;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	FText PlayerName;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	bool bPartyLeader;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	bool bIsInZone;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	bool bHasBoostXp;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	bool bHasRestXp;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	FString BannerIconId;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	FString BannerColorId;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	bool bBattlePassPurchased;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	int32 BattlePassLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	int32 BattlePassSelfXpBoost;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	int32 BattlePassFriendXpBoost;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	int32 NumPlayersInParty;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	int32 PlayerIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	uint8 TeamAffiliation;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	FText HeroClass;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	FText HeroLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	int32 HeroXP;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	TObjectPtr<UFortItem> HeroItem;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	TArray<TObjectPtr<UFortItem>> SelectedGadgetItems;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	FSlateBrush HeroIcon;

	UPROPERTY(BlueprintReadOnly, Category="FortTeamMemberInfo")
	FFortHomeBaseInfo HomeBaseInfo;


	FORTNITEGAME_API bool operator==(const FFortTeamMemberInfo& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FFortTeamMemberInfo& Value);
};

UCLASS(MinimalAPI, BlueprintType)
class UFortUITeamInfo : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTeamHitPointFractionsChanged, const TArray<float>&, HealthFractions, const TArray<float>&, ShieldFractions);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamMemberAddedDelegate, FFortTeamMemberInfo, NewTeamMemberInfo);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamMemberFinishedSynchronizingDelegate, FUniqueNetIdRepl, NewTeamMemberId);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamMemberRemovedDelegate, int32, PlayerIndex);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTeamMemberSimpleDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamMemberStateChangedDelegate, FFortTeamMemberInfo, TeamMemberInfo);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="UI Team")
	void GetTeamHitPointFractions(TArray<float>& HealthFractions, TArray<float>& ShieldFractions) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="UI Team")
	bool GetTeamMember(int32 MemberIndex, FFortTeamMemberInfo& OutMember) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="UI Team")
	void GetTeamMemberIDs(TArray<FUniqueNetIdRepl>& TeamMemberIDs) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="UI Team")
	void GetTeamMembers(TArray<FFortTeamMemberInfo>& TeamMembers) const;

	UFUNCTION(BlueprintPure, Category="UI Team")
	bool IsTeamMemberSynchronizing(const FUniqueNetIdRepl& PlayerID);

	UPROPERTY(BlueprintAssignable, Category="UI Team")
	FOnTeamMemberFinishedSynchronizingDelegate OnTeamMemberFinishedSynchronizing;

	UPROPERTY(BlueprintAssignable, Category="UI Team")
	FOnTeamMemberAddedDelegate OnTeamMemberAdded;

	UPROPERTY(BlueprintAssignable, Category="UI Team")
	FOnTeamMemberRemovedDelegate OnTeamMemberRemoved;

	UPROPERTY(BlueprintAssignable, Category="UI Team")
	FOnTeamMemberStateChangedDelegate OnTeamMemberStateChanged;

	UPROPERTY(BlueprintAssignable, Category="UI Team")
	FOnTeamMemberSimpleDelegate OnTeamMemberPromoted;

	UPROPERTY(BlueprintAssignable, Category="UI Team")
	FOnTeamHitPointFractionsChanged OnTeamHitPointFractionsChanged;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortPartyContext> TeamContext;

	UPROPERTY(Transient)
	uint8 TeamAssignment;

	UPROPERTY(Transient)
	TObjectPtr<UObject> FortTeamUEnum;

	UPROPERTY(Transient)
	int32 TotalFilledSlots;

	UPROPERTY(Transient)
	int32 PreviousFilledSlots;

	UPROPERTY()
	TArray<TObjectPtr<UFortRegisteredPlayerInfo>> PendingFinalTeardownRegisteredPlayerInfos;

	UPROPERTY()
	TMap<TObjectPtr<UFortRegisteredPlayerInfo>, TObjectPtr<AFortPlayerState>> PlayerStateByRegisteredPlayerInfo;

};

