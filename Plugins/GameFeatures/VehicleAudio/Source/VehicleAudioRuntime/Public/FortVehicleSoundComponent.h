// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VehicleAudioLifecycleInterface.h"
#include "FortVehicleSoundComponent.generated.h"

class AFortAthenaVehicle;
class AFortVehicleAudioController;
class UAudioComponent;
class UAudioMotorModelComponent;
class UAudioParameterComponent;
class UFortLayeredAudioComponent;
class UFortPhysicsVehicleConfigs;
class UREVComponent;
class USceneComponent;

UCLASS(Config=Game, EditInlineNew, HideDropdown, BlueprintType, Blueprintable, HideCategories=("Tags", "ComponentReplication", "Activation", "Variable", "Cooking", "AssetUserData", "Replication", "Collision"), meta=(ChildCanTick))
class VEHICLEAUDIORUNTIME_API UFortVehicleSoundComponent : public UActorComponent, public IVehicleAudioLifecycleInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="VehicleSound")
	AFortVehicleAudioController* GetAudioController() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	UAudioParameterComponent* GetAudioParameterComponent() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	UAudioComponent* GetEngineAudioComponent() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	UFortLayeredAudioComponent* GetLayeredAudioComponent() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	UAudioMotorModelComponent* GetMotorModelComponent() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	const UFortPhysicsVehicleConfigs* GetPhysicsVehicleConfigs() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	UREVComponent* GetREVComponent() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	USceneComponent* GetRootComponent() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	bool GetUseMetasounds() const;

	UFUNCTION(BlueprintPure, Category="VehicleSound")
	AFortAthenaVehicle* GetVehicleActor() const;

	UFUNCTION(BlueprintCallable, Category="VehicleSound")
	virtual void Init();

	UFUNCTION(BlueprintCallable, Category="VehicleSound")
	virtual void Shutdown();

	UFUNCTION(BlueprintCallable, Category="VehicleSound")
	virtual void Update(float DeltaSeconds);

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortVehicleAudioController> AudioController;

};

