// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameFramework/Volume.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortAthenaLivingWorldPointProviderInterface.h"
#include "FortAthenaLivingWorldPointProviderUtils.h"
#include "FortAthenaLivingWorldVolume.generated.h"

class AActor;
class AFortAthenaLivingWorldVolume;
class AFortGameStateAthena;
class ANavigationData;
class UEnvQuery;
class UFortAthenaLivingWorldManager;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class LAGERRUNTIME_API AFortAthenaLivingWorldVolume : public AVolume, public IFortAthenaLivingWorldPointProviderInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActorSpawnedResult, AActor*, SpawnedActor, bool, bResult);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPointProviderRegistered, AFortAthenaLivingWorldVolume*, PointProviderVolume);

public:
	UFUNCTION(BlueprintCallable)
	virtual void DisablePointProvider();

	UFUNCTION(BlueprintPure)
	bool DoesStartEnabled() const;

	UFUNCTION(BlueprintCallable)
	virtual void EnablePointProvider();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsPointProviderEnabled() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetSpawnRotation();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetEQSQuery(UEnvQuery* Query);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetEQSQueryConfigParam(const FName ParameterName, float Value);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetFiltersTags(const FGameplayTagContainer& TagContainer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetSpawnRotation(const FRotator& Rotation);

private:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnNavigationFinishedGeneration(ANavigationData* NavData);

	UFUNCTION()
	void OnWorldFinishedInitialization(const FGameplayTagContainer& ContextTags);

	UFUNCTION()
	void RunEQS();

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bStartEnabled;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bWaitForNavigation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LivingWorld", meta=(AllowPrivateAccess))
	FGameplayTagContainer FiltersTags;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TObjectPtr<UEnvQuery> EnvironmentQuery;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TArray<FAIDynamicParam> QueryConfig;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bRemoveUsedPoint;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	bool bRemoveUsedPointPermenantly;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FFortAthenaLivingWorldPointProviderSpawnLimiter SpawnLimiter;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FScalableFloat EQSRefreshInterval;

	UPROPERTY(EditAnywhere, Category="Water Level")
	FScalableFloat WaterLevelIndexMin;

	UPROPERTY(EditAnywhere, Category="Water Level")
	FScalableFloat WaterLevelIndexMax;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameStateAthena> CachedGameState;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnActorSpawnedResult OnActorSpawnedResult;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnPointProviderRegistered OnPointProviderRegistered;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaLivingWorldManager> CachedLivingWorldManager;

};

