// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ActorMetadata/FortActorMetadata.h"
#include "Components/FortControllerComponent.h"
#include "FortMemorySamplerTypes.h"
#include "FortControllerComponent_MemorySampler.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMemorySamplerProgressUpdated, float, Progress);

USTRUCT()
struct FMemorySamplingLocationStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	int32 ActorMemoryValue;

	UPROPERTY()
	TArray<FFortActorTemplateStats> ActorStats;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class FORTNITEGAME_API UFortControllerComponent_MemorySampler : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void BeginMemorySampling();

	UFUNCTION(Exec)
	void EndMemorySampling();

	UPROPERTY(BlueprintAssignable)
	FOnMemorySamplerProgressUpdated OnProgressUpdated;

private:
	UFUNCTION(Client, Reliable)
	void ClientBroadcastResults(bool bSuccess, int32 MemoryValue, int32 MemoryThreshold);

	UFUNCTION(Client, Reliable)
	void ClientEndMemorySampling();

	UFUNCTION(Client, Reliable)
	void ClientNotifyPreBeginSampling();

	UFUNCTION(Client, Reliable)
	void ClientNotifyRefreshMemoryTracker();

	UFUNCTION()
	void OnRep_MemorySamplerProgress() const;

	UFUNCTION()
	void OnRep_MemorySamplerState();

	UFUNCTION(Server, Reliable)
	void ServerAckClientReadyForSampling(bool bRequiresSpatialSampling);

	UFUNCTION(Server, Reliable)
	void ServerBeginMemorySampling();

	UFUNCTION(Server, Reliable)
	void ServerEndMemorySampling();

	UFUNCTION(Server, Reliable)
	void ServerReleaseSamplingLocation(int32 MemoryValue, const TArray<FFortActorTemplateStats>& ActorStats);

	UPROPERTY(ReplicatedUsing=OnRep_MemorySamplerState)
	EMemorySamplerState MemorySamplerState;

	UPROPERTY(ReplicatedUsing=OnRep_MemorySamplerProgress)
	float MemorySamplerProgress;

};

