// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Physics/Experimental/ChaosEventType.h"
#include "FortPhysicsChainConstraint.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;
class USceneComponent;
class UStaticMesh;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FChainAttachPoint
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ChainAttachPoint")
	TWeakObjectPtr<UPrimitiveComponent> AttachPointComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="ChainAttachPoint")
	TWeakObjectPtr<UPrimitiveComponent> AttachPointGCComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="ChainAttachPoint")
	FName BoneName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="ChainAttachPoint")
	FVector AttachNormal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="ChainAttachPoint")
	FVector AttachPosition;

};

UCLASS(Config=Game, PerObjectConfig, MinimalAPI, BlueprintType, Blueprintable)
class AFortPhysicsChainConstraint : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void DestroyAttachPoint(AActor* DamagedActor);

	UFUNCTION()
	void DestroyAttachPointConstraint(bool bStart);

	UFUNCTION()
	void DestroyAttachPointConstraintForComponent(UPrimitiveComponent* DamagedComponent);

	UFUNCTION()
	void DestroyBuildingPoint(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void DestroyGCBuildingPoint(const FChaosBreakEvent& BreakEvent);

	UFUNCTION(BlueprintCallable)
	bool LandscapeCheck();

	UFUNCTION()
	void OnPhysicsStateChange(UPrimitiveComponent* PrimitiveComponent, EComponentPhysicsStateChange StateChange);

	UFUNCTION()
	void OnRep_CreateChain();

	UFUNCTION()
	void OnRep_DestroyAttachPoint();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Export, Category="ChainConstraint", meta=(EditInline="true"))
	USceneComponent* ChainBaseComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint", meta=(ClampMin="0.0"))
	float MaxTwistLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint", meta=(ClampMin="0.0"))
	float MaxSwingLimit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint", meta=(ClampMin="1.0"))
	float LinkLengthModification;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint", meta=(ClampMin="0.0"))
	float MassOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint", meta=(ClampMin="1.0"))
	float InertiaTensorScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint", meta=(ClampMax="1.0", ClampMin="0.0"))
	float ShockPropagationScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint")
	AActor* StartPointAttachmentActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ChainConstraint")
	AActor* EndPointAttachmentActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Constraint")
	FName StartPointComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Constraint")
	FName EndPointComponentName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="ChainConstraint", meta=(EditInline="true"))
	TArray<UStaticMeshComponent*> ChainLinkMeshes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Replicated, Category="FortPhysicsChainConstraint")
	FChainAttachPoint StartPointAttachData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Replicated, Category="FortPhysicsChainConstraint")
	FChainAttachPoint EndPointAttachData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="ChainConstraint", meta=(ClampMin="0"))
	int32 NumberOfLinks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="ChainConstraint")
	UStaticMesh* ChainLinkMesh;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CreateChain)
	bool bCreateChainOnClient;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DestroyAttachPoint)
	bool bDestroyAttachPointOnClient;

	UPROPERTY(Transient, Replicated)
	bool bDestroyStart;

};

