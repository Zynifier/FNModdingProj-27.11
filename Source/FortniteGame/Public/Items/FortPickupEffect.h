// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortPickupEffect.generated.h"

class AFortPawn;
class AFortPickup;
class UFortAlterationItemDefinition;
class UFortItem;
class UFortWorldItemDefinition;
class UMaterialInstanceDynamic;
class UMeshComponent;
class USkeletalMesh;
class USoundBase;
class UStaticMesh;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Navigation", "Replication"))
class AFortPickupEffect : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UMaterialInstanceDynamic* ApplyCosmeticOverridesToMaterial(UMeshComponent* MeshComponent, int32 MatIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void DisableBacchusHighlight();

	UFUNCTION(BlueprintImplementableEvent)
	void EnableBacchusHighlight();

	UFUNCTION(BlueprintPure)
	UFortItem* GetPickupDummyItem() const;

	UFUNCTION(BlueprintNativeEvent)
	void OnAboutToEnterBackpack(AFortPawn* PickupTarget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPickedUp(AFortPawn* PickupTarget);

	UFUNCTION(BlueprintNativeEvent)
	void OnTossed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupProperties")
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupProperties")
	TObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PickupProperties")
	TObjectPtr<AFortPickup> ParentPickupActor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PickupProperties")
	TArray<TObjectPtr<UFortAlterationItemDefinition>> ActiveAlterations;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PickupProperties")
	TObjectPtr<UFortWorldItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupProperties")
	bool bDoNotShowSpawnParticles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupProperties")
	bool bDoNotTickSkeletalMeshComponents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupProperties")
	FVector PickupColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PickupProperties")
	FLinearColor BackpackWorldPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PickupProperties")
	uint8 bOwnedByALocalPlayer : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PickupProperties")
	uint8 bOwnedByPlayer : 1;

	UPROPERTY(BlueprintReadOnly, Category="PickupProperties")
	bool bRandomRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds")
	TObjectPtr<USoundBase> PickupByNearbyPawnSound;

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortPickupEffect")
	bool bTossed;

};

