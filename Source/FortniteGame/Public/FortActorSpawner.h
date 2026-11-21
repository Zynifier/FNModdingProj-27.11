// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortActorSpawner.generated.h"

class AActor;
class UChildActorComponent;

UENUM()
enum class EFortActorSpawnerAuthority : uint8
{
	// The actor will spawn on the server and may be replicated to clients.

	ServerAuthoritative = 0,
	// The actor will only spawn on clients.  Listen servers will need to make sure the actor isn't replicated.

	ClientAuthoritative = 1,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Collision", "Input"))
class AFortActorSpawner : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Spawning")
	FORTNITEGAME_API virtual bool TrySpawnActor();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Spawning", meta=(DisplayName="OnActorSpawned"))
	FORTNITEGAME_API void BP_OnActorSpawn(AActor* SpawnedActor);

	UPROPERTY(EditAnywhere, Category="Spawning")
	TSoftClassPtr<AActor> ActorClassToSpawn;

	UPROPERTY(EditAnywhere, Category="Spawning")
	EFortActorSpawnerAuthority SpawnerAuthority;

	UPROPERTY(EditAnywhere, Category="Spawning")
	uint8 bSpawnOnBeginPlay : 1;

	UPROPERTY(EditAnywhere, Category="Spawning")
	uint8 bDestroyAfterSpawn : 1;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UChildActorComponent> PreviewActorComponent;
#endif

};

