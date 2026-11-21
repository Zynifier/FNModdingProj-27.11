// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayTagContainer.h"
#include "FortSpawnActorComponent.generated.h"

class AActor;
class AFortGameStateAthena;
class UFortPlaylist;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortSpawnActorComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortSpawnActorComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Spawn Actor Component | Actor Data", meta=(OnlyPlaceable))
	TSubclassOf<AActor> ActorToSpawnClass;

	UPROPERTY(EditAnywhere, Category="Spawn Actor Component | Location Data")
	uint8 bAttachSpawnedActorToOwner : 1;

	UPROPERTY(EditAnywhere, Category="Spawn Actor Component | Location Data")
	FName SocketName;

	UPROPERTY(EditAnywhere, Category="Spawn Actor Component | Location Data")
	FName ComponentTag;

private:
	UFUNCTION()
	void OnPlaylistDataLoaded(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

};

