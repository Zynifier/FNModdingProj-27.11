// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FMDeviceCableWildcardOrderingComponent.generated.h"

class UCurveFloat;
class UFMDeviceCablePortComponent;
class UFMDeviceCableWildcardPortComponent;
class UStaticMeshComponent;
enum class EDeviceCablePortDataType : uint8;

UENUM()
enum class EFMDeviceCableWildcardOrderingState : int32
{
	Inactive = 0,
	Pending = 1,
	Active = 2,
};

USTRUCT(BlueprintType)
struct FFMDeviceCableOrderingMovementState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FMDeviceCableOrderingMovementState")
	TObjectPtr<UCurveFloat> Curve;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableOrderingMovementState")
	FVector Vector;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableOrderingMovementState")
	float MovementTimeSeconds;

protected:
	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableOrderingMovementState")
	bool bMovementActive;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableOrderingMovementState")
	bool bInvertVector;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableOrderingMovementState")
	bool bMovementState;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCableOrderingMovementState")
	float RunningMovementTimeSeconds;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFMDeviceCableWildcardPortComponent>> RelevantPorts;

};

USTRUCT(BlueprintType)
struct FFMDeviceCableOrderingMovementStateIndividual : public FFMDeviceCableOrderingMovementState
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFMDeviceCableOrderingMovementStateSlot : public FFMDeviceCableOrderingMovementState
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFMDeviceCableOrderingPortState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FMDeviceCableOrderingPortState", meta=(EditInline="true"))
	TObjectPtr<UFMDeviceCableWildcardPortComponent> WildcardPort;

	UPROPERTY(BlueprintReadWrite, Category="FMDeviceCableOrderingPortState")
	EFMDeviceCableWildcardOrderingState VisualState;

	UPROPERTY(BlueprintReadWrite, Category="FMDeviceCableOrderingPortState")
	EFMDeviceCableWildcardOrderingState State;

	UPROPERTY(BlueprintReadWrite, Category="FMDeviceCableOrderingPortState")
	int32 Slot;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class UFMDeviceCableWildcardOrderingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetInputRoot(FVector RootLocation);

	UFUNCTION(BlueprintCallable)
	void SetOutputPortsExpanded(bool bExpanded);

	UFUNCTION(BlueprintCallable)
	void SetOutputRoot(FVector RootLocation);

protected:
	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FFMDeviceCableOrderingMovementState InputsShowHideMovement;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FFMDeviceCableOrderingMovementStateIndividual OutputsShowHideMovement;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FFMDeviceCableOrderingMovementStateSlot OutputsCollapseExpandMovement;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FFMDeviceCableOrderingMovementStateIndividual OutputListShiftMovement;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FName ClosedMeshTag;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FName TopMeshTag;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FName MiddleMeshTag;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardOrderingComponent")
	FName BottomMeshTag;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> ClosedMesh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> TopMesh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> MiddleMeshes;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> BottomMesh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFMDeviceCableWildcardPortComponent>> InputWildcardPorts;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFMDeviceCableWildcardPortComponent>> OutputWildcardPorts;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFMDeviceCableWildcardPortComponent>> PortsWithPendingDisconnects;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerPortStates)
	TArray<FFMDeviceCableOrderingPortState> ServerPortStates;

private:
	UFUNCTION()
	void OnInputPortConnected(UFMDeviceCablePortComponent* ConnectedPort);

	UFUNCTION()
	void OnInputPortDataTypeChanged(UFMDeviceCableWildcardPortComponent* WildcardPort, EDeviceCablePortDataType DataType);

	UFUNCTION()
	void OnInputPortDisconnected(UFMDeviceCablePortComponent* DisconnectedPort);

	UFUNCTION()
	void OnOutputPortConnected(UFMDeviceCablePortComponent* SourcePort, UFMDeviceCablePortComponent* ConnectedPort);

	UFUNCTION()
	void OnOutputPortDisconnected(UFMDeviceCablePortComponent* SourcePort, UFMDeviceCablePortComponent* DisconnectedPort);

	UFUNCTION()
	void OnOutputPortSlotSetFromSave(UFMDeviceCableWildcardPortComponent* WildcardPort, bool bHasConnections);

	UFUNCTION()
	void OnRep_ServerPortStates();

};

