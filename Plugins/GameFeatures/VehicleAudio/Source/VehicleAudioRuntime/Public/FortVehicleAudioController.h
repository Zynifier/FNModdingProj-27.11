// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VehicleAudioLifecycleInterface.h"
#include "FortVehicleAudioController.generated.h"

class AFortAthenaVehicle;
class UAudioComponent;
class UAudioMotorModelComponent;
class UAudioParameterComponent;
class UFortLayeredAudioComponent;
class UFortPhysicsVehicleConfigs;
class UFortVehicleSoundComponent;
class UFortVehicleSoundData;
class UREVComponent;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable)
class VEHICLEAUDIORUNTIME_API AFortVehicleAudioController : public AActor, public IVehicleAudioLifecycleInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AudioController")
	virtual void CacheJitterTime();

	UFUNCTION(BlueprintPure, Category="AudioController")
	UAudioMotorModelComponent* GetAudioMotorModelComponent() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	UAudioParameterComponent* GetAudioParameterComponent() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	UAudioComponent* GetEngineAudioComponent() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	virtual float GetJitterTime() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	UFortLayeredAudioComponent* GetLayeredAudioComponent() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	const UFortPhysicsVehicleConfigs* GetPhysicsVehicleConfigs() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	virtual bool GetRedlineActive() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	UREVComponent* GetREVComponent() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	AFortAthenaVehicle* GetVehicleActor() const;

	UFUNCTION(BlueprintCallable, Category="AudioController")
	virtual void Init();

	UFUNCTION(BlueprintPure, Category="AudioController")
	virtual bool IsNativizationEnabled() const;

	UFUNCTION(BlueprintCallable, Category="AudioController")
	void SetLayeredAudioComponent(UFortLayeredAudioComponent* InComponent);

	UFUNCTION(BlueprintCallable, Category="AudioController")
	virtual void SetRedlineActive(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="AudioController")
	virtual void SetVehicle(AFortAthenaVehicle* InVehicle);

	UFUNCTION(BlueprintCallable, Category="AudioController")
	virtual void Shutdown();

	UFUNCTION(BlueprintCallable, Category="AudioController")
	virtual void Update(float DeltaSeconds);

	UFUNCTION(BlueprintPure, Category="AudioController")
	bool UseMetasounds() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AudioController")
	TObjectPtr<UFortVehicleSoundData> VehicleSoundData;

protected:
	UFUNCTION(BlueprintPure, Category="AudioController")
	virtual float GetBrakingNative() const;

	UFUNCTION(BlueprintPure, Category="AudioController")
	virtual float GetThrottleNative() const;

	UFUNCTION(BlueprintCallable, Category="AudioController")
	virtual void UpdateMotorModelNative(float DeltaSeconds);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AudioController", meta=(AllowPrivateAccess="true"))
	int32 CurrentSignificance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AudioController", meta=(AllowPrivateAccess="true"))
	bool bListenerInRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AudioController", meta=(AllowPrivateAccess="true"))
	bool bForceUpdatePastListenerRange;

	UPROPERTY(Transient)
	bool bRedlineAllowed;

	UPROPERTY(Transient)
	float JitterTime;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaVehicle> VehicleBase;

	UPROPERTY(Transient)
	TObjectPtr<UFortPhysicsVehicleConfigs> PhysicsVehicleConfigs;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortLayeredAudioComponent> LayeredAudioComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioParameterComponent> AudioParameterComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioMotorModelComponent> AudioMotorModelComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UREVComponent> RevComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> EngineComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortVehicleSoundComponent>> VehicleSoundComponents;

};

