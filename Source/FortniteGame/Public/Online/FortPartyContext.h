// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Party/PartyTypes.h"
#include "FortBlueprintContext.h"
#include "Online/FortUITeamInfo.h"
#include "FortPartyContext.generated.h"

class AFortPlayerState;
class UFortUITeamInfo;
enum class EAthenaPartyMemberReadyType : uint8;
enum class EFortFriendRequestStatus : uint8;
enum class EFortPartyMemberDisplayState : uint8;
enum class EFortPartyMemberLocation : uint8;
enum class EFortPartyState : uint8;

UENUM(BlueprintType)
enum class EAthenaPartyMemberReadyType : uint8
{
	Ready = 0,
	NotReady = 1,
	Playing = 2,
	Spectating = 3,
	WatchingReplay = 4,
};

UENUM(BlueprintType)
enum class EFortFriendRequestStatus : uint8
{
	/** There is no friend request between the two players */
	None = 0,
	/** The request has been accepted and the players are friends */
	Accepted = 1,
	/** The player has received a friend request from the other player that is pending action */
	PendingReceived = 2,
	/** The player has sent a friend request to the other player that is pending action */
	PendingSent = 3,
};

UENUM(BlueprintType)
enum class EFortPartyMemberDisplayState : uint8
{
	Open = 0,
	Connecting = 1,
	Connected = 2,
	Max = 3 UMETA(Hidden),
};

UCLASS(Config=Game, MinimalAPI)
class UFortPartyContext : public UFortBlueprintContext
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAthenaPartyMemberReadyTypeChanged, const FUniqueNetIdRepl&, UniqueId, EAthenaPartyMemberReadyType, MemberReadyType);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClientPartyStateChanged, EFortPartyState, PartyState);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCrossplayPreferenceChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLFGChanged, bool, bLFG);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNumAliveChanged, const FUniqueNetIdRepl&, UniqueId, int32, NumAlive);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPartyInvitesCountUpdatedDelegate, int32, PartyInvitesCount);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyJoinedDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyJoinRequested);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyLeftDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPartyPrivacyChangedDelegate);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPartyTypeChanged, EPartyType, PartyType);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerStateChangedDelegate, const FFortTeamMemberInfo&, PlayerInfo);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTimeSpentInMatchChanged, const FUniqueNetIdRepl&, UniqueId, const FText&, Mins, const FText&, Seconds);

public:
	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void AcceptMcpFriendRequest(const FUniqueNetIdRepl& PlayerID);

	UFUNCTION(BlueprintPure, Category="PartyContext")
	FText GetAthenaPartyMemberReadyText(const FUniqueNetIdRepl& MemberId) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	EAthenaPartyMemberReadyType GetAthenaPartyMemberReadyType(const FUniqueNetIdRepl& MemberId) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	EFortFriendRequestStatus GetConsoleFriendRequestStatusForPlayer(const FUniqueNetIdRepl& PlayerID) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	EFortFriendRequestStatus GetFriendRequestStatusForTeamMember(const FFortTeamMemberInfo& TeamMemberInfo, FUniqueNetIdRepl& UniqueIdUsed, bool& bIsMcpId) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	bool GetLocalPartyMemberLocation(EFortPartyMemberLocation& Location) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	EFortPartyState GetLocalPartyProgression() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	FString GetLocalPlayerDisplayName() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	UFortUITeamInfo* GetLocalPlayerTeam() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	void GetLocalPlayerTeamMemberInfo(FFortTeamMemberInfo& LocalPlayerInfo) const;

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	bool GetLocalTeamTeamMemberInfo(AFortPlayerState* TeamMemberState, FFortTeamMemberInfo& TeamMemberInfo);

	UFUNCTION(BlueprintPure, Category="PartyContext")
	int32 GetMaxTeamSizeForSelectedTheater() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	EFortFriendRequestStatus GetMcpFriendRequestStatusForPlayer(const FUniqueNetIdRepl& PlayerID) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	int32 GetNumPlayersInLocalParty() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	EFortPartyMemberDisplayState GetPartyMemberDisplayState(const FFortTeamMemberInfo& PartyMemberInfo) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	ECommonInputType GetPartyMemberInputType(const FUniqueNetIdRepl& MemberId) const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	bool GetPartyMemberLocation(const FUniqueNetIdRepl& MemberId, EFortPartyMemberLocation& LocationOut) const;

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	bool GetPartyPrivacySetting(EPartyType& OutPartyType, bool& OutLeaderFriendsOnly, bool& OutLeaderInvitesOnly);

	UFUNCTION(BlueprintPure, Category="PartyContext")
	bool IsEntirePartyInFrontEnd() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	bool IsLocalPlayerLFG() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	bool IsLocalPlayerPartyLeader() const;

	UFUNCTION(BlueprintPure, Category="PartyContext")
	bool IsNetIdFromLocalPlayersPlatform(const FUniqueNetIdRepl& PlayerId) const;

	UFUNCTION(BlueprintCallable, Category="UniqueNetID")
	static bool IsValidNetID(const FUniqueNetIdRepl& UniqueNetID);

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void LeaveAction(bool bInStayWithParty);

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void LeaveParty();

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void SendMcpFriendRequest(const FUniqueNetIdRepl& PlayerID);

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void SetLocalPartyMemberLocation(EFortPartyMemberLocation location);

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void SetLocalPlayerLFG(bool bInLFG);

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void SetPartyPrivacySetting(EPartyType PartyType, bool bLeaderFriendsOnly, bool bLeaderInvitesOnly);

	UFUNCTION(BlueprintPure)
	bool ShouldShowCrossplayWarningDialog() const;

	UFUNCTION(BlueprintCallable, Category="PartyContext")
	void ShowInitialCrossplayPrompt();

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPartyJoinedDelegate OnPartyJoined;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnClientPartyStateChanged OnClientPartyStateChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPartyTypeChanged OnPartyTypeChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnCrossplayPreferenceChanged OnCrossplayPreferenceChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPlayerStateChangedDelegate OnPlayerStateChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnNumAliveChanged OnAthenaNumAliveChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnTimeSpentInMatchChanged OnAthenaTimeSpentInMatch;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FAthenaPartyMemberReadyTypeChanged OnAthenaReadyTypeChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPartyJoinRequested OnPartyJoinRequested;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPartyInvitesCountUpdatedDelegate OnPartyInvitesCountChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnLFGChanged OnLFGChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPartyPrivacyChangedDelegate OnPartyPrivacyChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPlayerStateChangedDelegate OnLocalPlayerStateChanged;

	UPROPERTY(BlueprintAssignable, Category="PartyContext")
	FOnPartyLeftDelegate OnPartyLeft;

private:
	UPROPERTY()
	TMap<uint8, TObjectPtr<UFortUITeamInfo>> TeamsMap;

	UPROPERTY()
	TMap<FUniqueNetIdRepl, TObjectPtr<AFortPlayerState>> UnassignedPlayerStatesByID;

	UPROPERTY()
	TObjectPtr<UFortUITeamInfo> LocalPlayerTeam;

	UPROPERTY(Transient)
	TSet<FFortTeamMemberInfo> PendingChangedMemberInfos;

};

