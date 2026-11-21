// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingActor.h"
#include "FabricHoldableInterface.h"
#include "FabricInteractableInterface.h"
#include "FMDeviceCable.generated.h"

class UFMDeviceCableAnimatorBase;
class UFMDeviceCablePortComponent;
class UMaterialInstanceDynamic;
class USplineComponent;
class USplineMeshComponent;
class UStaticMesh;
class UStaticMeshComponent;
enum class EDeviceCablePortDataType : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), ClassGroup=("Harmonix"), SparseClassDataType=BuildingActorClassData)
class AFMDeviceCable : public ABuildingActor, public IFabricInteractable, public IFabricHoldable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ConnectConstantPort(UFMDeviceCablePortComponent* Port);

	UFUNCTION(BlueprintCallable)
	void ConnectPort(UFMDeviceCablePortComponent* Port);

	UFUNCTION(BlueprintCallable)
	void Disconnect();

	UFUNCTION(BlueprintPure)
	EDeviceCablePortDataType GetCableDataType() const;

	UFUNCTION(BlueprintPure)
	USplineComponent* GetCableSpline() const;

	UFUNCTION(BlueprintPure)
	UFMDeviceCablePortComponent* GetConstantPort() const;

	UFUNCTION(BlueprintPure)
	UStaticMeshComponent* GetDeviceCableHead() const;

	UFUNCTION(BlueprintPure)
	UFMDeviceCablePortComponent* GetPortA() const;

	UFUNCTION(BlueprintPure)
	UFMDeviceCablePortComponent* GetPortB() const;

	UFUNCTION(BlueprintCallable)
	void SetFocusedVisuals(bool bIsFocused);

	UFUNCTION(BlueprintCallable)
	void UpdateDeviceCableAnimator();

	UFUNCTION(BlueprintCallable)
	void UpdateVisualParameters();

protected:
	UFUNCTION(BlueprintCallable)
	void BuildMeshOnSpline(bool bCollisionEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCableConnected(bool bThroughReplication);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCableDisconnected(bool bThroughReplication);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCableGrabbed(bool bThroughReplication);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCableReturned();

	UFUNCTION(BlueprintImplementableEvent)
	void OnScalesUpdated(FVector StartScale, FVector EndScale);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSplineUpdated(bool bCollisionEnabled);

	UPROPERTY(BlueprintReadWrite, Export, Category="FMDeviceCable", meta=(EditInline="true"))
	TObjectPtr<USplineComponent> SplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FMDeviceCable", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> DeviceCableHead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMDeviceCable")
	TSubclassOf<USplineMeshComponent> SplineMeshComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	TSoftObjectPtr<UStaticMesh> ScalarStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	TSoftObjectPtr<UStaticMesh> AudioStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	TSoftObjectPtr<UStaticMesh> NoteStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	TSoftObjectPtr<UStaticMesh> TextureStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	TSoftObjectPtr<UStaticMesh> MeshStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	FName SplineLengthParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	FName SplineStartParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	FName SplineEndParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	FName PortTypeParam;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float CableStubLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float CableDistanceFromPortB;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float CableMinTangent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float CableMaxTangent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float CableSectionLengthAtCableCenter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float CableSectionLengthAtCableHeads;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	int32 CableSectionCountAtCableHeads;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	int32 CableCenterSectionsMaxCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float ExtremeMinDotProduct;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float MaxExtremeCableBendSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMDeviceCable")
	float ExtremeAngleTangentScale;

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="FMDeviceCable", meta=(EditInline="true"))
	TArray<TObjectPtr<USplineMeshComponent>> CableSplineMeshArray;

	UPROPERTY(BlueprintReadOnly, Category="FMDeviceCable")
	TWeakObjectPtr<UFMDeviceCableAnimatorBase> DeviceCableAnimator;

	UPROPERTY(BlueprintReadWrite, Category="FMDeviceCable")
	TObjectPtr<UMaterialInstanceDynamic> DeviceCableMaterial;

	UPROPERTY(BlueprintReadWrite, Category="FMDeviceCable")
	TObjectPtr<UMaterialInstanceDynamic> DeviceCableHeadMaterial;

private:
	UFUNCTION()
	void OnRep_ServerPortA();

	UFUNCTION()
	void OnRep_ServerPortB();

	UPROPERTY(Transient, Replicated, Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* ConstantPort;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* PortA;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerPortA, Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* ServerPortA;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* PortB;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerPortB, Export, meta=(EditInline="true"))
	UFMDeviceCablePortComponent* ServerPortB;

};

