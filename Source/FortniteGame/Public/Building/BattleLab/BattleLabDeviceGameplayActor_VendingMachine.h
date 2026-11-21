// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Building/BattleLab/BattleLabDeviceGameplayActor.h"
#include "FortInteractInterface.h"
#include "BattleLabDeviceGameplayActor_VendingMachine.generated.h"

class AActor;
class AFortPickup;
class UArrowComponent;
class UBoxComponent;
class UFortItemDefinition;
class UPrimitiveComponent;
class UStaticMeshComponent;
class UTexture2D;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABattleLabDeviceGameplayActor_VendingMachine : public ABattleLabDeviceGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(NetMulticast, Reliable)
	void AddStoredItemDefinitionMulti(const UFortItemDefinition* InItemDefinition);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Battle Lab Vending")
	void MachineTookCycleDamage(const int32 NextIndex);

	UFUNCTION()
	void OnFunnelCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnRep_DroppedIntoFunnelPickup();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Battle Lab Vending")
	void PickupDroppedIntoFunnel(AFortPickup* Pickup);

	UFUNCTION()
	void PreviewImageLoadedFromItemDef(TSoftObjectPtr<UTexture2D> PreviewImage);

	UFUNCTION()
	virtual bool ServerOnAttemptInteract(const FInteractionType& InteractType);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Battle Lab Vending", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> VendingMachineMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Battle Lab Vending", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> FunnelMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Battle Lab Vending", meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> FunnelCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Battle Lab Vending", meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> SpawnLootTransformArrow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Battle Lab Vending")
	float LootTossSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Battle Lab Vending")
	float LootTossAngleDegrees;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_DroppedIntoFunnelPickup, Category="Battle Lab Vending")
	TObjectPtr<AFortPickup> DroppedIntoFunnelPickup;

	UPROPERTY(BlueprintReadOnly, Category="Battle Lab Vending")
	TArray<TObjectPtr<UFortItemDefinition>> StoredItemDefinitions;

};

