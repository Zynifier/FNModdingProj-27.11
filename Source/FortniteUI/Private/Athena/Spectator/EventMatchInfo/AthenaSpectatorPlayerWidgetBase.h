// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "AthenaSpectatorPlayerWidgetBase.generated.h"

class AFortPlayerPawn;
class AFortPlayerStateAthena;
class UAthenaRemotePlayerViewData;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaSpectatorPlayerWidgetBase : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UAthenaRemotePlayerViewData* GetPlayerData() const;

	UFUNCTION(BlueprintCallable)
	void SetPlayerData(UAthenaRemotePlayerViewData* InPlayerData, bool bForceUpdate = false);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Playlist Extension Widget Created"))
	void BP_HandlePlaylistExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnBeingRevivedStateChanged(bool bIsBeingRevived);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnDBNOStateChanged(bool bIsDBNO);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnDeadStateChanged(bool bIsDead);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnDisconnectedChanged(bool bIsDisconnected);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnEventScoreChanged(int32 EventScore);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnHealthDamaged(float Health, float HealthMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnHealthHealed(float Health, float HealthMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnIsFollowedPlayerChanged(bool bIsFollowedPlayer);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnIsInRelevancyChanged(bool bIsInRelevancy);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnIsReplayRelevancyPlayerChanged(bool bIsReplayRelevancyPlayer);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnKillScoreChanged(int32 KillScore);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnLocationChanged(const FString& Location);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnMaterialCountChanged(int32 Count);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnPipModeChanged(bool bPipModeEnabled);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnPlaceChanged(int32 Place);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnPlayerDataChanged(UAthenaRemotePlayerViewData* InPlayerData);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnPlayerNameChanged(const FString& PlayerName);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnPlayerPawnChanged(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnPlayerStateChanged(AFortPlayerStateAthena* PlayerState);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnShieldDamaged(float Shield, float ShieldMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnShieldHealed(float Shield, float ShieldMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnSquadIdChanged(uint8 SquadId);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnSquadIdVisibilityChanged(bool bVisible);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnStormcapScoreChanged(float Score);

	UFUNCTION(BlueprintImplementableEvent, Category="Spectator Player Widget")
	void OnTeamColorChanged(FLinearColor TeamColor);

private:
	UFUNCTION()
	void HandleBeingRevivedStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsBeingRevived);

	UFUNCTION()
	void HandleDBNOStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDBNO);

	UFUNCTION()
	void HandleDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDead);

	UFUNCTION()
	void HandleDisconnectedChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDisconnected);

	UFUNCTION()
	void HandleHealthDamaged(UAthenaRemotePlayerViewData* InPlayerData, float Health, float MaxHealth);

	UFUNCTION()
	void HandleHealthHealed(UAthenaRemotePlayerViewData* InPlayerData, float Health, float MaxHealth);

	UFUNCTION()
	void HandleIsFollowedPlayerChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsFollowedPlayer);

	UFUNCTION()
	void HandleIsInRelevancyChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsInRelevancy);

	UFUNCTION()
	void HandleIsReplayRelevancyPlayerChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsReplayRelevancyPlayer);

	UFUNCTION()
	void HandleKillScoreChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 KillScore);

	UFUNCTION()
	void HandleMaterialCountChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 MaterialCount);

	UFUNCTION()
	void HandlePlaceChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 Place);

	UFUNCTION()
	void HandlePlayerNameChanged(UAthenaRemotePlayerViewData* InPlayerData, const FString& PlayerName);

	UFUNCTION()
	void HandlePlayerStateChanged(UAthenaRemotePlayerViewData* InPlayerData, AFortPlayerStateAthena* PlayerState);

	UFUNCTION()
	void HandleShieldDamaged(UAthenaRemotePlayerViewData* InPlayerData, float Shield, float MaxShield);

	UFUNCTION()
	void HandleShieldHealed(UAthenaRemotePlayerViewData* InPlayerData, float Shield, float MaxShield);

	UFUNCTION()
	void HandleSquadIdChanged(UAthenaRemotePlayerViewData* InPlayerData, uint8 SquadId);

	UFUNCTION()
	void HandleTeamColorChanged(UAthenaRemotePlayerViewData* InPlayerData, FLinearColor TeamColor);

};

