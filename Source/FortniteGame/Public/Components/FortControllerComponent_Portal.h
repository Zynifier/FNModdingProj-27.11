// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "OnlineLinkId.h"
#include "FortControllerComponent_Portal.generated.h"

class UFortPortalComponent;

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Portal : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanCancelPortalMatchmaking() const;

	UFUNCTION(BlueprintPure)
	bool CanInitiateMatchmakingToPortalOrigin() const;

	UFUNCTION(BlueprintPure)
	bool CanInitiatePortalMatchmkaing(UFortPortalComponent* PortalComponent) const;

	UFUNCTION(BlueprintPure, Category="Matchmaking")
	static bool CanInitiatePrivateMatchmaking();

	UFUNCTION(BlueprintCallable)
	void InitiateMatchmakingToPortalOrigin();

	UFUNCTION(BlueprintPure, Category="Matchmaking")
	static bool IsGameDetailPreviewScreenEnabled();

	UFUNCTION(BlueprintPure, Category="Matchmaking")
	static bool IsOnPortalHudEnabled();

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void ServerSetPortalLinkCode(UFortPortalComponent* PortalComponent, const FOnlineLinkId& LinkId);

	UPROPERTY(Config)
	bool bAllowRequeueToLinks;

protected:
	UFUNCTION(Client, Reliable)
	void ClientInitiateMatchmakingToPortalOrigin();

private:
	UFUNCTION()
	void OnPortalMatchmakingComplete(const bool bSuccess);

};

