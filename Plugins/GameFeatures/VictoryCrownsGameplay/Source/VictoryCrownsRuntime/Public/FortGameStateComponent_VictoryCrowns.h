// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_VictoryCrowns.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerStateAthena;
class UFortItem;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_VictoryCrowns : public UFortGameStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void ClientKillFeedMessage(const AFortPlayerStateAthena* FortPSA, bool bAdded);

	UFUNCTION(BlueprintPure)
	bool IsCrownBearer(const AFortPlayerStateAthena* FortPSA) const;

protected:
	UFUNCTION()
	void HandleCrownStatusChanged(AFortPlayerControllerAthena* FortPlayerControllerAthena, const UFortItem* CrownItem);

	UFUNCTION()
	void OnRep_CrownBearerPlayerStates();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CrownBearerPlayerStates)
	TArray<TObjectPtr<AFortPlayerStateAthena>> CrownBearerPlayerStates;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_VictoryCrowns")
	FText KillFeedFormat_Dropped;

	UPROPERTY(EditDefaultsOnly, Category="FortGameStateComponent_VictoryCrowns")
	FText KillFeedFormat_PickedUp;

};

