// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FMDeviceCableTypes.h"
#include "FMDeviceCableControllerComponent.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerControllerAthena;
class AFortVolume;
class AFortWeapon;
class APlayerController;
class UFMDeviceCableManagerComponent;
class UFMDeviceCablePortComponent;
enum class EDeviceCableActivatedState : uint8;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMDEVICECABLESRUNTIME_API UFMDeviceCableControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnControllerCableConnected, const TArray<UFMDeviceCablePortComponent*>&, ConnectedPorts);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnControllerCableDisconnected);

public:
	UFUNCTION(BlueprintCallable)
	void DropCable();

	UFUNCTION(BlueprintPure)
	bool IsCableConnectionValid(UFMDeviceCablePortComponent* OtherPort) const;

	UFUNCTION(BlueprintPure)
	bool IsHoldingCable() const;

	UFUNCTION(BlueprintCallable)
	void SelectPort(UFMDeviceCablePortComponent* SelectedPort);

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerPortActivatedStateChanged(UFMDeviceCablePortComponent* Port, EDeviceCableActivatedState ActivatedState);

	UPROPERTY(BlueprintAssignable)
	FOnControllerCableConnected OnControllerCableConnected;

	UPROPERTY(BlueprintAssignable)
	FOnControllerCableDisconnected OnControllerCableDisconnected;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetControllerTargetForControllerPortBP(AActor* ControllerPortActor, APlayerController* Controller);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCableControllerComponent")
	TSubclassOf<AActor> ControllerCablePort;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCableControllerComponent")
	TSubclassOf<AActor> DeviceCableManagerClass;

private:
	UFUNCTION()
	void OnCreativePlotLinkedVolumeChanged(AFortVolume* FortVolume);

	UFUNCTION()
	void OnFortPawnChanged(AFortPawn* Pawn);

	UFUNCTION()
	void OnNoFabricInteractablesHit();

	UFUNCTION()
	void OnRep_ServerControllerPort();

	UFUNCTION()
	void OnRep_ServerDeviceCableManager();

	UFUNCTION()
	void OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION(Server, Reliable)
	void ServerDisconnectController();

	UFUNCTION(Server, Reliable)
	void ServerPortsUpdated(const TArray<FPortUpdateInfo>& PortChangeInfos);

	UFUNCTION(Server, Reliable)
	void ServerSelectPort(UFMDeviceCablePortComponent* SelectedPort);

	UFUNCTION(Server, Reliable)
	void ServerVolumeChanged();

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerAthena> PlayerController;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFMDeviceCablePortComponent> LocalControllerPort;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerControllerPort, Export, meta=(EditInline="true"))
	TObjectPtr<UFMDeviceCablePortComponent> ServerControllerPort;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> LocalControllerPortActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFMDeviceCableManagerComponent> LocalDeviceCableManager;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerDeviceCableManager, Export, meta=(EditInline="true"))
	TObjectPtr<UFMDeviceCableManagerComponent> ServerDeviceCableManager;

};

