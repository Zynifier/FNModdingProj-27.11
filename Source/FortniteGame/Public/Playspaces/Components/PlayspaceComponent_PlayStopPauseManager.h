// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_PlayStopPauseManager.generated.h"

class AActor;
class UPlayspaceComponent_PlayStopPauseManager;

USTRUCT()
struct FReplicatedPlayPauseStopActor : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> Actor;

};

USTRUCT()
struct FReplicatedPlayPauseStopActors : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	UPlayspaceComponent_PlayStopPauseManager* Owner;

	UPROPERTY()
	TArray<FReplicatedPlayPauseStopActor> PlayPauseStopActors;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_PlayStopPauseManager : public UFortPlayspaceComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_PlayDevices();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayDevices)
	bool bPlayDevices;

	UPROPERTY(Transient)
	bool bCachedPlaying;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> ServerPlayPauseStopActors;

	UPROPERTY(Transient, Replicated)
	FReplicatedPlayPauseStopActors ReplicatedPlayPauseStopActors;

};

