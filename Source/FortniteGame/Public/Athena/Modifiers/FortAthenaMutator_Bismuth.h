// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortDeathCauseEnum.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Bismuth.generated.h"

class AActor;
class AAthenaBismuthSpawner;
class AController;
class AFortPlayerPawnAthena;
class UEnvQuery;
class UFortAthenaAIBotCustomizationData;
class UGameplayEffect;
class UPrimitiveComponent;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Bismuth : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Bot")
	TObjectPtr<UFortAthenaAIBotCustomizationData> BotData;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Bot")
	FScalableFloat NumOfBotsToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Bot")
	FScalableFloat AIBotsHostileToEachOther;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Bot")
	int32 BotTeamStartIndex;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Bot")
	TSoftObjectPtr<UEnvQuery> SpawnersSelectionQuery;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Bot")
	FScalableFloat MinimumDistanceBetweenSpawners2D;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Gameplay")
	FScalableFloat ReflectKillDelay;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Gameplay")
	FGameplayTag ReflectDeathReason;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Gameplay")
	TArray<EDeathCause> ValidDeathReasons;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Cues")
	TSubclassOf<UGameplayEffect> ReflectGameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category="Bismuth|Cues")
	TSubclassOf<UGameplayEffect> InitiateGameplayEffect;

private:
	UFUNCTION()
	void AIBotPawnDeath(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void ReflectEliminatePlayer(AFortPlayerPawnAthena* PlayerPawn);

	UPROPERTY()
	TArray<TObjectPtr<AAthenaBismuthSpawner>> BismuthSpawners;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawnAthena>> BismuthAIBots;

};

UCLASS()
class UFortCheatManager_Bismuth : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void BismuthSetAIBotsHostileToEachOther(const bool bHostile);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void BismuthSetMinimumDistanceBetweenSpawners2D(const float Distance);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void BismuthSetNumOfBotsToSpawn(const int32 Num);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void BismuthSetReflectKillDelay(const float Delay);

};

