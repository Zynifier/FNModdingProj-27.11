// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_AdHocSquads.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class UAdHocSquadData;
class UFortControllerComponent_AdHocSquads;
enum class EAdHocSquads_InviteStatus : uint8;
enum class EAdHocSquads_LeaveSquadReason : uint8;
enum class EAdHocSquads_SquadUpResult : uint8;

UENUM(BlueprintType)
enum class EAdHocSquads_InviteStatus : uint8
{
	/** The player is NOT currently inviting and we have no information about why they stopped inviting (probably they never invited.) */
	Unset = 0,
	/** The player is currently performing the invite emote. */
	Inviting = 1,
	/** The player is NOT currently inviting. Their last invite ended in a squad up between players. */
	InviteEnded_APlayerAcceptedTheInvite = 2,
	/** The player is NOT currently inviting. Their last invite ended because either was or became full. */
	InviteCancelled_SquadFull = 3,
	/** The player is NOT currently inviting. The player ended their last invite, or was possibly killed. */
	InviteCancelled_ByInvitingPlayer = 4,
};

UENUM(BlueprintType)
enum class EAdHocSquads_LeaveSquadReason : uint8
{
	/** The player decided to leave on their own. */
	ManualLeave = 0,
	/** The ad hoc squad mutator has become disabled. */
	MutatorDisabled = 1,
	/** The player left their previous squad to join a new squad.
	*	Should ONLY get called if bFollowingPlayerAutomaticallyLeavesCurrentSquadWhenSquadingUp is enabled. */
	JoinedADifferentSquad = 2,
	/** The player has died and canNOT be revived so they were kicked out of the squad. */
	PlayerDiedAndCannotBeRevived = 3,
	/** The player has won the game and are no longer playing. */
	PlayerHasWonGame = 4,
};

UENUM(BlueprintType)
enum class EAdHocSquads_SquadUpResult : uint8
{
	/** Successfully joined the squad */
	Success = 0,
	/** Could NOT join squad, one or both players were nullptr */
	Failure_OneOrMorePlayersWereNull = 1,
	/** Could NOT join squad, both players were already in ad hoc squads. */
	Failure_BothPlayersAreInAdHocSquads = 2,
	/** Could NOT join squad, both players are already in the same ad hoc squad. */
	Failure_BothPlayersAreAlreadyInTheSameAdHocSquad = 3,
	/** Could NOT join squad, could not find an empty squad to use*/
	Failure_CouldNotCreateAdHocSquad = 4,
	/** Could NOT join squad, the function was called on the client, it ONLY works if called on the server*/
	Failure_CalledOnClient = 5,
	/** Could NOT join squad, the squad you tried to join was already full. */
	Failure_SquadIsAlreadyFull = 6,
	/** Could NOT join squad, the combined number of players on both squads is too big to all join a single squad. */
	Failure_TooManyPlayersToMergeSquads = 7,
	/** Could NOT join squad, the ad hoc squad mutator is currently disabled. */
	Failure_MutatorIsDisabled = 8,
	/** Could NOT join squad for some unknown reason. */
	Failure_Unknown = 9,
	/** Could NOT join squad  for some reason defined in a derived class.
	*	This applies to any value at or above Failure_Custom. */
	Failure_Custom = 10,
};

USTRUCT()
struct FAdHocSquad_InviteData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> InvitingPlayerState;

	UPROPERTY()
	EAdHocSquads_InviteStatus InviteStatus;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAdHocSquads_InviteStatusChanged, const FAdHocSquad_InviteData&, InviteData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAdHocSquads_SquadChanged, const AFortPlayerStateAthena*, PlayerState, const uint8, PreviousSquadId, const uint8, NewSquadId);

USTRUCT()
struct FAdHocSquad_InviteDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FAdHocSquad_InviteData> Entries;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_AdHocSquads : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void HavePlayerLeaveAdHocSquad(AFortPlayerControllerAthena* LeavingPlayerController, const EAdHocSquads_LeaveSquadReason LeaveReason);

	UFUNCTION(BlueprintPure)
	bool IsPlayersSquadFull(const AFortPlayerControllerAthena* PlayerController) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool PlayerInitiatedSquadInvite(const AFortPlayerPawn* InFortPlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void PlayerSquadInviteEnded(AFortPlayerStateAthena* PlayerStateInviting, const EAdHocSquads_InviteStatus InviteEndedReason);

	UFUNCTION(BlueprintPure)
	static bool ShouldAllowAdHocSquads();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(ExpandBoolAsExec="SquadUpSuccessful"))
	bool SquadUpPlayers(EAdHocSquads_SquadUpResult& OutSquadUpResult, uint8& OutNewSharedSquad, AFortPlayerControllerAthena* SquadUpInstigatorPlayerController, AFortPlayerControllerAthena* SquadUpFollowerPlayerController);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	int32 MaxAdHocSquadSize;

	UPROPERTY(EditDefaultsOnly, Category="VoiceChat")
	FScalableFloat bVoiceChatSquaddingEnabled;

	UPROPERTY(EditDefaultsOnly, Category="SquadInvite")
	FScalableFloat MaxDistInviteNotificationCanBeReceived;

	UPROPERTY(EditDefaultsOnly, Category="SquadInvite")
	FScalableFloat MinimumDistInviteNotificationIsLost;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EAthenaGamePhase"))
	int32 ForceDisplaySquadInfoDuringGamePhases;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads")
	FText SquadsTooBigToMergeText;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	TSubclassOf<UFortControllerComponent_AdHocSquads> AdHocSquadsControllerComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	TSubclassOf<UAdHocSquadData> AdHocSquadDataClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	bool bMaintainSquadDataForNonAdHocSquads;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	FScalableFloat bForceAllPlayersOntoIndividualTeams;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	FScalableFloat bFollowingPlayerAutomaticallyLeavesCurrentSquadWhenSquadingUp;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	FScalableFloat bSquadingUpMergesSquads;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	FScalableFloat bEnsureOnOutsideTeamOrSquadChanged;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads", meta=(AllowPrivateAccess))
	FScalableFloat bBreakUpSocialPartiesOnInit;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_AdHocSquads")
	FGameplayTagContainer HUDElementTags;

	UPROPERTY()
	TMap<uint8, TObjectPtr<UAdHocSquadData>> AdHocSquadDataMap;

	UPROPERTY(Replicated)
	FAdHocSquad_InviteDataArray InviteDataArray;

	UPROPERTY()
	TArray<FAdHocSquad_InviteData> LocalClientInviteDataArray;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UAdHocSquadData : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> PlayerStates;

};

UCLASS()
class UFortCheatManager_AdHocSquads : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void AdHocSquadsDebugAssignPlayerToSquad(const int32 SquadIndex);

	UFUNCTION(Exec)
	void AdHocSquadsDebugResetPlayerSquad();

	UFUNCTION(Exec)
	void AdHocSquadsToggleVoiceChatSquadding();

};

