// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "AttachableWheel.generated.h"

class AActor;
class AAttachableWheel;
class UPhysicsConstraintComponent;
class UPrimitiveComponent;
class UStaticMeshComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttachableWheelDelegate, AAttachableWheel*, AttachableWheel, UPrimitiveComponent*, AttachedComponent);

USTRUCT(BlueprintType)
struct FAttachableWheelAttachData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="AttachableWheelAttachData")
	TWeakObjectPtr<UPrimitiveComponent> PrimitiveComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AttachableWheelAttachData")
	FVector Pos;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AttachableWheelAttachData")
	FVector Axis1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AttachableWheelAttachData")
	FVector Axis2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AttachableWheelAttachData")
	FName AttachmentName;

};

UCLASS(BlueprintType, Blueprintable)
class ATTACHABLEWHEELSRUNTIME_API AAttachableWheel : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool AttachInPlace(UPrimitiveComponent* InComponent);

	UFUNCTION(BlueprintCallable)
	bool AttachTo(UPrimitiveComponent* InComponent, const FVector& WorldLocation, const FVector& AxleDirection);

	UFUNCTION(BlueprintCallable)
	void Detach();

	UFUNCTION(BlueprintCallable)
	bool DetachFrom(UPrimitiveComponent* InComponent);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void DrawDebug() const;

	UFUNCTION(BlueprintCallable)
	AActor* GetActorRef();

	UFUNCTION(BlueprintPure)
	UPrimitiveComponent* GetAttachedComponent() const;

	UFUNCTION(BlueprintPure)
	bool GetWorldSpaceAttachData(FAttachableWheelAttachData& OutAttachData, UPrimitiveComponent* PrimitiveComponent = nullptr, const FName BodyName = NAME_None) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttached(UPrimitiveComponent* AttachedComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDetached(UPrimitiveComponent* DetachedComponent);

	UFUNCTION(BlueprintCallable)
	void SetActorRef(AActor* NewActorRef);

protected:
	UFUNCTION()
	void OnPhysicsStateChanged(UPrimitiveComponent* PrimitiveComponent, EComponentPhysicsStateChange StateChange);

	UFUNCTION()
	void OnRep_AttachData(const FAttachableWheelAttachData& AttachDataPrev);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Export, Category="AttachableWheel", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="Mesh,Rendering,Physics,Components|StaticMesh"))
	TObjectPtr<UStaticMeshComponent> WheelMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AttachableWheel")
	FRotator WheelOrientation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AttachableWheel")
	float WheelDistance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="AttachableWheel", meta=(AllowPrivateAccess="true", EditInline="true", ExposeFunctionCategories="JointDrive,Physics|Components|PhysicsConstraint"))
	TObjectPtr<UPhysicsConstraintComponent> AxleConstraint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_AttachData, Category="AttachableWheel")
	FAttachableWheelAttachData AttachData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="AttachableWheel")
	AActor* ActorRef;

};

