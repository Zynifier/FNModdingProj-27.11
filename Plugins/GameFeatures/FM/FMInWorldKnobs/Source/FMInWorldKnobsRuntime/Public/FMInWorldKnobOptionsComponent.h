// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TimerHandle.h"
#include "FabricModulatorInterface.h"
#include "FMInWorldKnobOptionsComponent.generated.h"

class AActor;
class ABuildingActor;
class AFortPlayerPawn;
class APlayerController;
class UFMDeviceCableModulatorPortComponent;
class UFabricModulatable;
class UFabricUserOptionSaveComponent;
class UObject;
class UPlaylistUserOptionBase;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMINWORLDKNOBSRUNTIME_API UFMInWorldKnobOptionsComponent : public UActorComponent, public IFabricModulatorSource
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllKnobsLoaded);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnyKnobRuntimeValueChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnyKnobSerializedValueChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitialKnobValuesLoaded);

public:
	UFUNCTION(BlueprintPure)
	bool AreAllKnobsLoadedForNotify() const;

	UFUNCTION(BlueprintPure)
	bool CanMakeUserOptionChanges() const;

	UFUNCTION(BlueprintPure)
	bool OwnsInWorldKnobObject(UObject* InWorldKnobObject) const;

	UPROPERTY(BlueprintAssignable)
	FOnInitialKnobValuesLoaded OnInitialKnobValuesLoaded;

	UPROPERTY(BlueprintAssignable)
	FOnAllKnobsLoaded OnAllKnobsLoaded;

	UPROPERTY(BlueprintAssignable)
	FOnAnyKnobRuntimeValueChanged OnAnyKnobRuntimeValueChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAnyKnobRuntimeValueChanged OnAnyKnobSerializedValueChanged;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	bool ActorHasValidControllerBP(AActor* Actor, AFortPlayerPawn*& OutFortPlayerPawn, APlayerController*& OutPlayerController);

private:
	UFUNCTION()
	void OnAnyOptionUpdated();

	UFUNCTION()
	void OnInWorldKnobRuntimeOptionChanged(const FString& Value, UPlaylistUserOptionBase* Option);

	UFUNCTION()
	void OnInWorldKnobSerializedOptionChanged(const FString& Value, UPlaylistUserOptionBase* Option, APlayerController* PlayerController);

	UFUNCTION()
	void OnOptionsLoaded();

	UFUNCTION()
	void OnRep_ReplicatedFabricInteractableObjects();

	UFUNCTION()
	void OnRep_ReplicatedInWorldKnobInterfaceObjects();

	UFUNCTION()
	void OnRep_ReplicatedModulatorPorts();

	UFUNCTION()
	void OnSaveOverridesChanged();

	UPROPERTY(Transient)
	TSet<UObject*> InWorldKnobInterfaceObjects;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedInWorldKnobInterfaceObjects)
	TArray<UObject*> ReplicatedInWorldKnobInterfaceObjects;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedFabricInteractableObjects)
	TArray<UObject*> ReplicatedFabricInteractableObjects;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ReplicatedModulatorPorts, Export, meta=(EditInline="true"))
	TArray<UFMDeviceCableModulatorPortComponent*> ReplicatedModulatorPorts;

	UPROPERTY(Transient)
	ABuildingActor* BuildingActorOwner;

	UPROPERTY(Transient)
	UClass* OwnerClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFabricUserOptionSaveComponent> SaveComponent;

	UPROPERTY(Transient)
	TMap<FString, UPlaylistUserOptionBase*> PropertiesEditedByUserOptions;

	UPROPERTY(Transient)
	TMap<FString, UObject*> OptionKeyToInWorldKnobObject;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<FString, UFMDeviceCableModulatorPortComponent*> OptionKeyToModulatorPort;

	UPROPERTY(Transient)
	TArray<UFabricModulatable*> PendingFabricModulatables;

	UPROPERTY(Transient)
	FTimerHandle ActorSaveRequestTimer;

};

