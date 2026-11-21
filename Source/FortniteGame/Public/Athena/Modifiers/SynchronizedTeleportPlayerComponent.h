// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "SynchronizedTeleportPlayerComponent.generated.h"

class AFortPlayerControllerAthena;
class USoundBase;

USTRUCT()
struct FSynchronizedTeleportFadeOutReplicationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText HUDReasonText;

	UPROPERTY()
	float FadeEndTime;

	UPROPERTY()
	bool bFadeAudio;

	UPROPERTY()
	uint8 ReplicationIndex;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class USynchronizedTeleportPlayerComponent : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void HandleTeleportScreenStatusChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText);

	UFUNCTION()
	void OnRep_FadeOutData();

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> TeleportScreenMusicCue;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	float TeleportScreenFadeoutTime;

	UPROPERTY(ReplicatedUsing=OnRep_FadeOutData)
	FSynchronizedTeleportFadeOutReplicationData FadeOutData;

private:
	UFUNCTION()
	void OnRep_IsServerWaitingForClientToCancelRespawn();

	UFUNCTION(Server, Reliable)
	void ServerRestartRespawn();

	UPROPERTY(ReplicatedUsing=OnRep_IsServerWaitingForClientToCancelRespawn)
	bool bIsServerWaitingForClientToCancelRespawn;

};

