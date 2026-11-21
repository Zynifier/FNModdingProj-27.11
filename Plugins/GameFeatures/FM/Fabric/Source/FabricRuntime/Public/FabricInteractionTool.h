// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Weapons/FortWeapon.h"
#include "FabricInteractionTool.generated.h"

class AFortCreativeDeviceProp;
class UObject;
class USceneComponent;
class USplineComponent;
enum class EFabricContinuousInteractionDirection : uint8;
enum class EFabricInteractableType : uint8;
enum class EFabricInteractionToolStates : uint8;

UENUM(BlueprintType)
enum class EFabricInteractionToolStates : uint8
{
	Equipped = 0,
	// FIT is equipped on player
// HoveredDevice,			// FIT cursor is hovering over a FABRIC device

	HoveredControl = 1,
	// FIT cursor is hovering over a control on a FABRIC device

	HoveredValidCablePort = 2,
	// FIT cursor is hovering over a port that they can connect to

	HoveredInvalid = 3,
	// FIT cursor is hovering over a port that they cannot connect to

	ContinuousSelected = 4,
	// FIT has selected a continuous control, like a knob
// ContinuousChanged,		// FIT is changing the value of a continuous control, like a knob

	MomentarySelected = 5,
	// FIT is changing the value of momentary control, like a button

	CableSelected = 6,
	// FIT is holding a cable
// ActivationChanged,		// FIT is changing the value of the activate/deactivate button on a device

	None = 7,
};

USTRUCT()
struct FInteractionData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFabricInteractionToolStates InteractionState;

	UPROPERTY()
	TWeakObjectPtr<AFortCreativeDeviceProp> InteractableOwnerDevice;

};

USTRUCT()
struct FInteractionSplinePoints
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize10 SplineStartLocation;

	UPROPERTY()
	FVector_NetQuantize10 SplineStartForward;

	UPROPERTY()
	FVector_NetQuantize10 SplineEndLocation;

	UPROPERTY()
	FVector_NetQuantize10 SplineEndForward;

};

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class FABRICRUNTIME_API AFabricInteractionTool : public AFortWeapon
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCableHeldStateChanged, AFortCreativeDeviceProp*, Device);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInteractionStateChanged, EFabricInteractionToolStates, NewState, AFortCreativeDeviceProp*, Device);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMetasoundGeneratorCrossfadeStarted, float, CrossfadeSeconds);

public:
	UFUNCTION(BlueprintCallable)
	void HandleMetasoundGeneratorCrossfade(float CrossfadeSeconds);

	UFUNCTION(BlueprintPure, Category="FabricInteractionTool")
	bool IsRunningOnOwningClient() const;

	UPROPERTY(BlueprintAssignable)
	FOnInteractionStateChanged OnInteractionStateChanged;

	UPROPERTY(BlueprintAssignable)
	FOnCableHeldStateChanged OnCablesGrabbed;

	UPROPERTY(BlueprintAssignable)
	FOnCableHeldStateChanged OnCablesDropped;

	UPROPERTY(BlueprintAssignable)
	FOnMetasoundGeneratorCrossfadeStarted OnMetasoundGeneratorCrossfadeStarted;

protected:
	UFUNCTION(Client, Reliable)
	void ClientDeactiveWeaponAndState();

	UFUNCTION(Client, Reliable)
	void ClientStopInteracting();

	UFUNCTION(BlueprintCallable)
	virtual void DeactiveWeaponAndState();

	UFUNCTION(BlueprintPure)
	float GetContinuousInteractableValueNormalized();

	UFUNCTION(BlueprintCallable)
	EFabricContinuousInteractionDirection GetContinuousInteractionDirection();

	UFUNCTION(BlueprintPure)
	float GetContinuousMovementValue();

	UFUNCTION(BlueprintPure)
	int32 GetContinuousStateValue();

	UFUNCTION(BlueprintPure)
	EFabricInteractionToolStates GetFabricInteractionToolState();

	UFUNCTION(BlueprintCallable)
	USceneComponent* GetHoveredInteractableHitComponent();

	UFUNCTION(BlueprintCallable)
	EFabricInteractableType GetHoveredInteractableType();

	UFUNCTION(BlueprintCallable)
	UObject* GetPressedInteractable();

	UFUNCTION(BlueprintPure)
	bool IsHoldingCables();

	UFUNCTION()
	void OnRep_ServerContinuousInteractableValue();

	UFUNCTION()
	void OnRep_ServerInteractionData();

	UFUNCTION()
	void OnRep_ServerIsHoldingCable();

	UFUNCTION()
	void OnRep_ServerTriggerPressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSplineUpdated(EFabricInteractionToolStates NewInteractionState);

	UFUNCTION(Server, Unreliable)
	void ServerHandleFITFired();

	UFUNCTION(Server, Unreliable)
	void ServerSetContinuousInteractableValue(float Value);

	UFUNCTION(Server, Reliable)
	void ServerSetInteractionData(FInteractionData NewData);

	UFUNCTION(Server, Reliable)
	void ServerSetIsHoldingCable(bool bHoldingCable);

	UFUNCTION(Server, Reliable)
	void ServerSetSplinePoints(FInteractionSplinePoints SplinePoints);

	UFUNCTION(Server, Reliable)
	void ServerSetTriggerPressed(bool bPressed);

	UFUNCTION(BlueprintCallable)
	void UnholsterWeapon();

	UPROPERTY(BlueprintReadWrite, Export, Category="FabricInteractionTool", meta=(EditInline="true"))
	USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, Category="FabricInteractionTool")
	float MaxRange;

	UPROPERTY(EditDefaultsOnly, Category="FabricInteractionTool")
	float MinDragAndDropTriggerTime;

	UPROPERTY(EditAnywhere, Category="FortWeapon")
	float FiringRate;

	UPROPERTY(EditDefaultsOnly, Category="Spline")
	float SplineEndForwardMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Spline")
	float SplineStartForwardMultiplier;

private:
	UPROPERTY(Transient)
	TObjectPtr<UObject> HoveredInteractable;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> HoveredInteractableHitComponent;

	UPROPERTY(Transient)
	TObjectPtr<UObject> PressedInteractable;

	UPROPERTY(Transient)
	TWeakObjectPtr<UObject> LastPressedInteractable;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> PressedInteractableHitComponent;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortCreativeDeviceProp> InteractableOwnerDevice;

	UPROPERTY(Transient)
	float AccumulatedDragAndDropTriggerTime;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerInteractionData)
	FInteractionData ServerInteractionData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerTriggerPressed)
	bool bServerTriggerPressed;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerIsHoldingCable)
	bool bServerIsHoldingCable;

	UPROPERTY(Transient, Replicated)
	FInteractionSplinePoints ServerSplinePoints;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerContinuousInteractableValue)
	float ServerContinuousInteractableValue;

};

