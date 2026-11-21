// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortAthenaLivingWorldPointProviderInterface.h"
#include "FortAthenaLivingWorldPointProviderUtils.h"
#include "FortAthenaPointAroundPlayerProvider.generated.h"

class AActor;
class AFortGameStateAthena;
class APawn;
class UEnvQuery;

UCLASS(MinimalAPI)
class AFortAthenaPointAroundPlayerProvider : public AActor, public IFortAthenaLivingWorldPointProviderInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorSpawnedResult, AActor*, SpawnedActor, bool, bResult);

public:
	UFUNCTION(BlueprintCallable)
	virtual void DisablePointProvider();

	UFUNCTION(BlueprintCallable)
	virtual void EnablePointProvider();

	UFUNCTION(BlueprintCallable)
	void SetForcedPawnToUse(const APawn* InForcedPawnToUse);

private:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnWorldFinishedInitialization(const FGameplayTagContainer& ContextTags);

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FGameplayTagContainer FiltersTags;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TObjectPtr<UEnvQuery> QueryTemplate;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TEnumAsByte<EEnvQueryRunMode::Type> RunMode;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	uint8 bStartEnabled : 1;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	uint8 bGenerateAroundPlayerBots : 1;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FGameplayTag IgnorePlayerWithTag;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FFortAthenaLivingWorldPointProviderSpawnLimiter SpawnLimiter;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnActorSpawnedResult OnActorSpawnedResult;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

};

