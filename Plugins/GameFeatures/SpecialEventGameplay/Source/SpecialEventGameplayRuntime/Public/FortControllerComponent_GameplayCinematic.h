// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_GameplayCinematic.generated.h"

class AFortPlayerControllerAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDynamicGameplayIntroPanelEvent, AFortPlayerControllerAthena*, PlayerControllerAthena);

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class SPECIALEVENTGAMEPLAYRUNTIME_API UFortControllerComponent_GameplayCinematic : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void HideHUDElementsForLoadingScreen(const bool bHideElements);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetReadyForGameplay(bool bIsReady);

	UFUNCTION(BlueprintCallable, Exec, BlueprintCosmetic)
	void ShowCinematicWidget(FName WidgetName);

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="OnStartGameplayOutro"))
	FDynamicGameplayIntroPanelEvent BP_OnStartGameplayOutro;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Gameplay Intro Finished"))
	FDynamicGameplayIntroPanelEvent BP_OnGameplayIntroFinished;

protected:
	UFUNCTION()
	void OnRep_bIsReadyForGameplay();

	UFUNCTION(Server, Reliable)
	void ServerOnGameplayIntroFinished();

	UPROPERTY(ReplicatedUsing=OnRep_bIsReadyForGameplay)
	bool bIsReadyForGameplay;

};

