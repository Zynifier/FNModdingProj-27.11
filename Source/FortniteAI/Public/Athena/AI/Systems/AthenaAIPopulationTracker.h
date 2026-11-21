// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "AthenaAIPopulationTracker.generated.h"

class AActor;
class AController;
class AFortAthenaAIBotController;
class AFortGameModeAthena;
class AFortPawn;
class AFortPlayerPawn;
class APawn;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyAIDestroyed, AFortPawn*, DestroyedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FNotifyAIDied, AController*, KilledController, bool, bIsABot, AFortPawn*, KilledAIPawn, AFortPlayerPawn*, KilledPlayerPawn, AController*, KillerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FNotifyAISpawned, AController*, SpawnedController, bool, bIsABot, AFortPawn*, FortAIPawn, AFortPlayerPawn*, PlayerPawn);

USTRUCT(BlueprintType)
struct FAIPopulationCountSnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AIPopulationCountSnapshot")
	int32 NumTotalSpawnedBots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AIPopulationCountSnapshot")
	int32 NumAliveBots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AIPopulationCountSnapshot")
	int32 NumAlivePlayerBots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AIPopulationCountSnapshot")
	int32 NumAliveNPCBots;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AIPopulationCountSnapshot")
	int32 NumAliveAIPawns;

};

UCLASS(BlueprintType)
class UAthenaAIPopulationTracker : public UAISubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	TArray<AController*> GetAIMatchingQuery(const FGameplayTagQuery& TagQuery) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FAIPopulationCountSnapshot GetAIPopulationTrackerCount() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetNumAIPawn() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetNumNonAthenaParticipantBots() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetNumPlayerBots() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetNumTotalBots() const;

	UFUNCTION()
	void OnFortPawnDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnFortPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="AI")
	FNotifyAIDied OnAIPawnDied;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="AI")
	FNotifyAIDestroyed OnAIPawnDestroyed;

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, Category="AI")
	FNotifyAISpawned OnAIPawnSpawned;

private:
	UFUNCTION()
	void OnAgentGameOver(AFortAthenaAIBotController* AIBotController, AFortPawn* Pawn, AController* Instigator);

	UFUNCTION()
	void OnAISpawned(APawn* Pawn, const int32 RequestID);

	UPROPERTY(Transient)
	TArray<TObjectPtr<AController>> AIList;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameModeAthena> CachedGameMode;

};

