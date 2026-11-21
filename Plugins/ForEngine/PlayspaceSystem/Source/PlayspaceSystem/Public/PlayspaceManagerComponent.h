// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "PlayspaceManagerComponent.generated.h"

class AGameplayVolume;
class APlayerController;
class APlayerState;
class APlayspace;

UENUM()
enum class EPlayspaceRootType : uint8
{
	ShouldBeRoot = 0,
	ShouldBeClobbered = 1,
};

USTRUCT()
struct FActorOverlapEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY()
	TObjectPtr<AGameplayVolume> Volume;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class PLAYSPACESYSTEM_API UPlayspaceManagerComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UPlayspaceManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Transient, ReplicatedUsing=OnRep_RootPlayspace)
	TObjectPtr<APlayspace> RootPlayspace;

	UPROPERTY(Transient)
	EPlayspaceRootType PlayspaceRootType;

private:
	UFUNCTION()
	void OnPlayerBeginOverlapGameplayVolume(APlayerState* PlayerState, AGameplayVolume* Volume);

	UFUNCTION()
	void OnPlayerEndOverlapGameplayVolume(APlayerState* PlayerState, AGameplayVolume* Volume);

	UFUNCTION()
	void OnRep_RootPlayspace();

	UFUNCTION()
	bool ProcessOverlapEvents(float DeltaTime);

	UPROPERTY()
	TArray<FActorOverlapEvent> UnhandledEnterEvents;

	UPROPERTY()
	TArray<FActorOverlapEvent> UnhandledExitEvents;

	UPROPERTY()
	TSet<TObjectPtr<APlayerController>> UnassignedPlayers;

};

