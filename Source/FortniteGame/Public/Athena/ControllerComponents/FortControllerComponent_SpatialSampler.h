// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_SpatialSampler.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class FORTNITEGAME_API UFortControllerComponent_SpatialSampler : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	bool BeginSpatialSampling();

	UFUNCTION(Exec)
	void EndSpatialSampling();

private:
	UFUNCTION(Client, Reliable)
	void ClientTeleportedToNextSamplingLocation(const FVector& Location);

	UFUNCTION(Server, Reliable)
	void ServerAddSamplingLocation(const FVector& Location);

	UFUNCTION(Server, Reliable)
	void ServerAddSamplingLocations(const TArray<FVector>& Locations);

	UFUNCTION(Server, Reliable)
	void ServerBeginSpatialSampling();

	UFUNCTION(Server, Reliable)
	void ServerEndSpatialSampling();

	UFUNCTION(Server, Reliable)
	void ServerRegisterOnSamplingLocationChangedHandleID(const uint64 ID);

	UFUNCTION(Server, Reliable)
	void ServerReleaseSamplingLocation();

	UFUNCTION(Server, Reliable)
	void ServerRemoveAllSamplingLocations();

	UFUNCTION(Server, Reliable)
	void ServerUnregisterOnSamplingLocationChangedHandleID(const uint64 ID);

	UPROPERTY(Replicated)
	int32 NumPendingSamplingLocations;

	UPROPERTY(Replicated)
	bool bIsSampling;

};

