// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaBroadcastFollowedPlayerInfoBase.generated.h"

class AActor;
class AFortPlayerControllerSpectating;
class AFortPlayerState;
class UAthenaRemotePlayerViewData;
class UAthenaSpectatorHitPointBarBase;
class UAthenaSpectatorPlayerWidgetBase;

UCLASS(Abstract)
class UAthenaBroadcastFollowedPlayerInfoBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	UAthenaRemotePlayerViewData* GetFollowedPlayerData();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEliminatedStateChanged(UAthenaRemotePlayerViewData* PlayerData, bool bIsEliminated);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPipModeChanged(bool bPipModeEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnVehicleStateChanged(AActor* NewVehicle, AActor* OldVehicle);

private:
	UFUNCTION()
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatingPC, AFortPlayerState* FollowedPlayerState);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaBroadcastFollowedPlayerInfoBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorPlayerWidgetBase> PlayerWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorHitPointBarBase> HitPointBar_Health;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorHitPointBarBase> HitPointBar_Shield;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpectatorHitPointBarBase> HitPointBar_Vehicle;

};

