// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "PlayspaceComponent_PlayerManager.generated.h"

class APawn;
class APlayerState;
class UActorComponent;
class UControllerComponent;
class UPlayerStateComponent;

USTRUCT()
struct PLAYSPACESYSTEM_API FPlayspace_ComponentInfo_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Playspace Components Info")
	bool bCreateOnClient;

	UPROPERTY(EditDefaultsOnly, Category="Playspace Components Info")
	bool bCreateOnServer;

};

USTRUCT(BlueprintType, meta=(Category="Playspace Components Info"))
struct PLAYSPACESYSTEM_API FPlayspace_ActorComponentInfo : public FPlayspace_ComponentInfo_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Playspace Components Info")
	TSubclassOf<UActorComponent> ComponentClass;

};

USTRUCT(BlueprintType, meta=(Category="Playspace Components Info"))
struct PLAYSPACESYSTEM_API FPlayspace_ControllerComponentInfo : public FPlayspace_ComponentInfo_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Playspace Components Info")
	TSubclassOf<UControllerComponent> ComponentClass;

};

USTRUCT(BlueprintType, meta=(Category="Playspace Components Info"))
struct PLAYSPACESYSTEM_API FPlayspace_PlayerStateComponentInfo : public FPlayspace_ComponentInfo_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Playspace Components Info")
	TSubclassOf<UPlayerStateComponent> ComponentClass;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class PLAYSPACESYSTEM_API UPlayspaceComponent_PlayerManager : public UPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPlayerPawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn);

	UPROPERTY(EditDefaultsOnly, Category="Playspace Component Lists")
	TArray<FPlayspace_ControllerComponentInfo> ControllerComponents;

	UPROPERTY(EditDefaultsOnly, Category="Playspace Component Lists")
	TArray<FPlayspace_PlayerStateComponentInfo> PlayerStateComponents;

	UPROPERTY(EditDefaultsOnly, Category="Playspace Component Lists")
	TArray<FPlayspace_ActorComponentInfo> ActorComponents;

};

