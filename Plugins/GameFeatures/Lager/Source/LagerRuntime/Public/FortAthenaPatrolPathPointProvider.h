// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortAthenaLivingWorldPointProviderInterface.h"
#include "FortAthenaLivingWorldPointProviderUtils.h"
#include "FortAthenaPatrolPathPointProvider.generated.h"

class AActor;
class AFortAthenaPatrolPath;
class AFortGameStateAthena;
class UBillboardComponent;
class UFortAthenaLivingWorldManager;

UCLASS(MinimalAPI)
class AFortAthenaPatrolPathPointProvider : public AActor, public IFortAthenaLivingWorldPointProviderInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorSpawnedResult, AActor*, SpawnedActor, bool, bResult);

public:
	UFUNCTION(BlueprintCallable)
	LAGERRUNTIME_API virtual void DisablePointProvider();

	UFUNCTION(BlueprintCallable)
	LAGERRUNTIME_API virtual void EnablePointProvider();

private:
	UFUNCTION()
	LAGERRUNTIME_API void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FGameplayTagContainer FiltersTags;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TObjectPtr<AFortAthenaPatrolPath> AssociatedPatrolPath;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	uint8 bStartEnabled : 1;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	uint8 bSpawnOnPatrolPath : 1;

	UPROPERTY(EditAnywhere, Category="LivingWorld", meta=(EditCondition="bSpawnOnPatrolPath"))
	uint8 bAlignOrientationToPath : 1;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FFortAthenaLivingWorldPointProviderSpawnLimiter SpawnLimiter;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnActorSpawnedResult OnActorSpawnedResult;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortAthenaPatrolPath> RuntimePatrolPathWeakPtr;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaLivingWorldManager> CachedLivingWorldManager;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSoftObjectPtr<AFortAthenaPatrolPath> AssociatedPatrolPathSoftCopy;
#endif

};

