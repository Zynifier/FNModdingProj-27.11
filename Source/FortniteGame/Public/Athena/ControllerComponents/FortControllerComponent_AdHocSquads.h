// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_AdHocSquads.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_AdHocSquads.generated.h"

class AFortAthenaMutator_AdHocSquads;
class AFortPlayerStateAthena;
class UAdHocSquadData;
enum class EAdHocSquads_LeaveSquadReason : uint8;
enum class EAdHocSquads_SquadUpResult : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FControllerComponentAdHocSquads_FailedToJoinSquad, const AFortPlayerStateAthena*, PlayerFromSquad, const EAdHocSquads_SquadUpResult, FailureReason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FControllerComponentAdHocSquads_NearbySquadInviteUpdate, const AFortPlayerStateAthena*, PlayerNearInviter, const AFortPlayerStateAthena*, InvitingPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FControllerComponentAdHocSquads_OtherPlayerLeftSquad, const AFortPlayerStateAthena*, LeavingPlayerState, const EAdHocSquads_LeaveSquadReason, Reason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControllerComponentAdHocSquads_OwningPlayerLeftSquad, const EAdHocSquads_LeaveSquadReason, Reason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControllerComponentAdHocSquads_SquadInviteInitiationFailed, const EAdHocSquads_SquadUpResult, FailureReason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FControllerComponentAdHocSquads_SquadInviteUpdate, const AFortPlayerStateAthena*, InvitingPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FControllerComponentAdHocSquads_SquadJoined, const AFortPlayerStateAthena*, PlayerState, const bool, bInviteInstigatedByThisPlayer);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_AdHocSquads : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientOnFailedToJoinSquad(const AFortPlayerStateAthena* PlayerFromSquad, const EAdHocSquads_SquadUpResult FailureReason);

	UFUNCTION(Client, Reliable)
	void ClientOnLeaveParty();

	UFUNCTION(Client, Reliable)
	void ClientOnOtherPlayerJoinedSquad(const AFortPlayerStateAthena* JoiningPlayer, const bool bInviteInstigatedByThisPlayer);

	UFUNCTION(Client, Reliable)
	void ClientOnOtherPlayerLeftSquad(const AFortPlayerStateAthena* LeavingPlayer, const EAdHocSquads_LeaveSquadReason LeaveReason);

	UFUNCTION(Client, Reliable)
	void ClientOnOwningPlayerJoinedSquad(const AFortPlayerStateAthena* PlayerTheOwningPlayerIsJoining, const bool bInviteInstigatedByThisPlayer);

	UFUNCTION(Client, Reliable)
	void ClientOnOwningPlayerLeftSquad(const EAdHocSquads_LeaveSquadReason LeaveReason);

	UFUNCTION(Client, Unreliable)
	void ClientOnSquadInviteInitiationFailed(const EAdHocSquads_SquadUpResult FailureReason);

	UFUNCTION(BlueprintPure, Category="AdHocSquads")
	UAdHocSquadData* GetAdHocSquadData() const;

	UFUNCTION(BlueprintPure)
	const TArray<AFortPlayerStateAthena*>& GetNearbySquadInvitingPlayers() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumberOfPlayersInSquad(const AFortPlayerStateAthena* InPlayerState) const;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_SquadJoined DelegateOwningPlayerJoinedSquad;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_SquadJoined DelegateOtherPlayerJoinedSquad;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_FailedToJoinSquad DelegateFailedToJoinSquad;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_OwningPlayerLeftSquad DelegateOwningPlayerLeftSquad;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_OtherPlayerLeftSquad DelegateOtherPlayerLeftSquad;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_SquadInviteUpdate DelegatePlayerInitiatedSquadInvite;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_SquadInviteUpdate DelegatePlayerEndedSquadInvite;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_SquadInviteInitiationFailed DelegateSquadInviteInitiationFailed;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_NearbySquadInviteUpdate DelegatePlayerHasNearedSquadInvitingPlayer;

	UPROPERTY(BlueprintAssignable)
	FControllerComponentAdHocSquads_NearbySquadInviteUpdate DelegatePlayerIsNoLongerNearSquadInvitingPlayer;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFailedToJoinSquad(const AFortPlayerStateAthena* PlayerFromSquad, const EAdHocSquads_SquadUpResult FailureReason);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOtherPlayerJoinedSquad(const AFortPlayerStateAthena* JoiningPlayer, const bool bInviteInstigatedByThisPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOtherPlayerLeftSquad(const AFortPlayerStateAthena* LeavingPlayer, const EAdHocSquads_LeaveSquadReason LeaveReason);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOwningPlayerJoinedSquad(const AFortPlayerStateAthena* PlayerTheOwningPlayerIsJoining, const bool bInviteInstigatedByThisPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOwningPlayerLeftSquad(const EAdHocSquads_LeaveSquadReason LeaveReason);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerInitiatedSquadInvite(const AFortPlayerStateAthena* PlayerInitiatingInvite);

	UFUNCTION()
	void OnRep_AdHocSquadsMutator(AFortAthenaMutator_AdHocSquads* OldAdHocSquadsMutator);

	UFUNCTION()
	void OnSquadInviteDataChanged(const FAdHocSquad_InviteData& InviteData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSquadInviteInitiationFailed(const EAdHocSquads_SquadUpResult FailureReason);

	UPROPERTY(ReplicatedUsing=OnRep_AdHocSquadsMutator)
	TObjectPtr<AFortAthenaMutator_AdHocSquads> AdHocSquadsMutator;

private:
	UFUNCTION()
	void HandleServerSquadChange(AFortPlayerStateAthena* PlayerState, const uint8 OldSquadIndex);

	UFUNCTION()
	void HandleServerTeamChange();

	UPROPERTY()
	TObjectPtr<UAdHocSquadData> AdHocSquadData;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> NearbySquadInvitingPlayers;

	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> ClosestNearbySquadInvitingPlayerState;

};

