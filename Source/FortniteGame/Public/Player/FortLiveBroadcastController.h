// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Player/FortLiveSpectatorController.h"
#include "FortLiveBroadcastController.generated.h"

class AActor;
class AFortPlayerMarkerBase;
enum class ESpectatorCameraType : uint8;

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortLiveBroadcastController : public AFortLiveSpectatorController
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNoParamDelegate);

public:
	UFUNCTION(BlueprintCallable)
	bool CanStartBattleBus();

	UFUNCTION(Client, Reliable)
	void ClientHideBusButton();

	UFUNCTION(BlueprintCallable)
	void TryBeginBusPhase();

	UPROPERTY(BlueprintAssignable)
	FNoParamDelegate OnHideBusButtonFromServer;

	UPROPERTY(BlueprintAssignable)
	FNoParamDelegate OnToggleOffAirWidgetVisibilty;

	UPROPERTY(BlueprintAssignable)
	FNoParamDelegate OnToggleNetUIWidgetVisibilty;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PostProcess")
	TSubclassOf<AActor> BroadcastPostProcessingActorClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortLiveBroadcastController")
	TSubclassOf<AFortPlayerMarkerBase> SquadMarkerActorClass;

protected:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerBeginBusPhase();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOnSpectatorCameraTypeChanged(ESpectatorCameraType NewCameraMode, const FVector& SpectatorLocation, bool bValidPos);

};

