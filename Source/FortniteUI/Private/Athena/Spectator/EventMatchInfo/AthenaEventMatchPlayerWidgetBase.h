// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "AthenaEventMatchPlayerWidgetBase.generated.h"

class AFortPlayerPawn;
class AFortPlayerStateAthena;
class UAthenaRemotePlayerViewData;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaEventMatchPlayerWidgetBase : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerData(UAthenaRemotePlayerViewData* InPlayerData);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnBeingRevivedStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsBeingRevived);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnDBNOStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDBNO);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDead);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnDisconnectedChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bIsDisconnected);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnHealthDamaged(UAthenaRemotePlayerViewData* InPlayerData, float InHealth, float InHealthMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnHealthHealed(UAthenaRemotePlayerViewData* InPlayerData, float InHealth, float InHealthMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnIsFollowedPlayerChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsFollowedPlayer);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnIsInRelevancyChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsInRelevancy);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnIsReplayRelevancyPlayerChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsReplayRelevancyPlayer);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnKillScoreChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InKillScore);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnLocationChanged(UAthenaRemotePlayerViewData* InPlayerData, const FString& InLocation);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnMaterialCountChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InCount);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnPlaceChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InPlace);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnPlayerDataChanged(UAthenaRemotePlayerViewData* InPlayerData);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnPlayerNameChanged(UAthenaRemotePlayerViewData* InPlayerData, const FString& InPlayerName);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnPlayerPawnChanged(UAthenaRemotePlayerViewData* InPlayerData, AFortPlayerPawn* InPlayerPawn);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnPlayerStateChanged(UAthenaRemotePlayerViewData* InPlayerData, AFortPlayerStateAthena* InPlayerState);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnShieldDamaged(UAthenaRemotePlayerViewData* InPlayerData, float InShield, float InShieldMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnShieldHealed(UAthenaRemotePlayerViewData* InPlayerData, float InShield, float InShieldMax);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnSquadIdChanged(UAthenaRemotePlayerViewData* InPlayerData, uint8 InSquadId);

	UFUNCTION(BlueprintImplementableEvent, Category="Event Match Player Widget")
	void OnTeamColorChanged(UAthenaRemotePlayerViewData* InPlayerData, FLinearColor InTeamColor);

	UPROPERTY(BlueprintReadWrite, Category="Event Match Player Widget")
	TWeakObjectPtr<UAthenaRemotePlayerViewData> PlayerData;

};

