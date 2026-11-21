// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/OnlineReplStructs.h"
#include "CreativeRegisteredPlayersManagerComponent.generated.h"

class AController;
class AFortPlayerState;
class UFortMinigameLogicComponent;

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class ECreativeRegisteredPlayerGroups : uint8
{
	None = 0,
	RegisteredPlayers = 1,
	NonRegisteredPlayers = 2,
	Everyone = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllPlayersUnregistered);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRegisterPlayersChanged, const AFortPlayerState*, PlayerState);

UCLASS(Config=Creative, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UCreativeRegisteredPlayersManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Minigame")
	void GetRegisteredPlayers(TArray<AFortPlayerState*>& OutPlayerStateArray);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void RegisterPlayer(AController* Controller);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void UnregisterAllPlayers();

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void UnregisterPlayer(AController* Controller);

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnRegisterPlayersChanged OnPlayerRegistered;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnRegisterPlayersChanged OnPlayerUnregistered;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnAllPlayersUnregistered OnAllPlayersUnregistered;

private:
	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION()
	void OnPlayerRemoved(FUniqueNetIdRepl NetId, bool bIsLocalPlayer);

	UPROPERTY(Transient, Replicated)
	TArray<TWeakObjectPtr<AFortPlayerState>> RegisteredPlayers;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMinigameLogicComponent> FortMinigameLogicComponent;

};

