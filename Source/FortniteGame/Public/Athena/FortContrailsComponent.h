// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "NiagaraComponentPoolMethodEnum.h"
#include "Particles/WorldPSCPool.h"
#include "FortContrailsComponent.generated.h"

class UAthenaSkyDiveContrailItemDefinition;
class UFXSystemAsset;
class UFXSystemComponent;
enum class EFortContrailsState : uint8;

UENUM()
enum class EFortContrailsState : uint8
{
	/**
	 * Contrails are currently blocked from being displayed or are awaiting a refresh of visibility
	 */
	NotActive = 0,
	/**
	 * Contrails can be displayed and visibility was refreshed, but there is a set activation delay
	 */
	ActivationPending = 1,
	/**
	 * Contrail activation should have occurred (the delay expired or there was none to begin with), but our contrail
	 * assets are still loading
	 */
	AwaitingLoad = 2,
	/**
	 * Contrails have been spawned and activated. Note that we will remain in the active state even if the player's
	 * loadout changed or our override FX changed, so that there is a seamless transition when the new asset loads.
	 */
	Active = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContrailsActivated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContrailsDeactivated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContrailsLoadFinished);

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortContrailsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool AreContrailsLoaded() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetContrailFXComponent() const;

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UFXSystemAsset> GetContrailFXOverride();

	UFUNCTION(BlueprintPure)
	EFortContrailsState GetContrailsState() const;

	UFUNCTION(BlueprintPure)
	bool HasContrailFXOverrde();

	UFUNCTION(BlueprintCallable)
	void RefreshContrailVisibility();

	UFUNCTION(BlueprintCallable)
	void SetContrailFXOverride(TSoftObjectPtr<UFXSystemAsset> InContrailFXOverride);

	UPROPERTY(BlueprintAssignable)
	FOnContrailsLoadFinished OnContrailsLoadFinished;

	UPROPERTY(BlueprintAssignable)
	FOnContrailsActivated OnContrailsActivated;

	UPROPERTY(BlueprintAssignable)
	FOnContrailsDeactivated OnContrailsDeactivated;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortContrailsComponent")
	float SpawnDelay;

protected:
	UFUNCTION()
	void HandleBeginParachuteMovement();

	UFUNCTION()
	void HandleBeginSkydiving();

	UFUNCTION()
	void HandleEndParachuteMovement();

	UFUNCTION()
	void HandleEndSkydiving();

	UFUNCTION()
	void HandleLanded(const FHitResult& Hit);

	UFUNCTION()
	void HandleParachuteSpawned();

	UPROPERTY(VisibleAnywhere, Category="FortContrailsComponent")
	bool bAlwaysShowContrails;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSkyDiveContrailItemDefinition> ActiveContrailDefinition;

	UPROPERTY(Transient)
	TSoftObjectPtr<UFXSystemAsset> ContrailFXOverride;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	TObjectPtr<UFXSystemAsset> VaporEmitterTemplate;

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="FortContrailsComponent")
	TWeakObjectPtr<UFXSystemComponent> ContrailFXComp;

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="FortContrailsComponent")
	TWeakObjectPtr<UFXSystemComponent> VaporFXComp;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	EPSCPoolMethod PoolingMethod;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	ENCPoolMethod NiagaraPoolingMethod;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float VelocityInRangeMin;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float VelocityInRangeMax;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float NiagaraParamsOutRangeMin;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float NiagaraParamsOutRangeMax;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float TrailAlphaOutRangeMin;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float TrailAlphaOutRangeMax;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float TrailWidthOutRangeMin;

	UPROPERTY(EditDefaultsOnly, Category="FortContrailsComponent")
	float TrailWidthOutRangeMax;

};

