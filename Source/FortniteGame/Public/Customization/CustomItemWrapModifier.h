// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCosmeticModifierBase.h"
#include "CustomItemWrapModifier.generated.h"

class AActor;
class AFortPlayerPawn;
class AFortWeapon;
class UAudioComponent;
class UMeshComponent;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(ChildCanTick))
class ACustomItemWrapModifier : public ACustomCosmeticModifierBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Custom Item Wrap")
	AActor* GetVehicle() const;

	UFUNCTION(BlueprintPure, Category="Custom Item Wrap")
	AFortWeapon* GetWeapon() const;

	UFUNCTION(BlueprintPure, Category="Custom Item Wrap", meta=(DisplayName="Get Single Wrapped Mesh Component"))
	UMeshComponent* GetWrappedMeshComponent() const;

	UFUNCTION(BlueprintPure, Category="Custom Item Wrap")
	TArray<UMeshComponent*> GetWrappedMeshComponents() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void NotifyAudioComponentAdded(UAudioComponent* AudioComponent);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void NotifyAudioComponentVehicleTriggered(UAudioComponent* AudioComponent, int32 Priority);

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic)
	void OnSetWrapTarget();

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> GenericActorPtr;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> VehiclePtr;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> WeaponPtr;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UMeshComponent> MeshPtr;

private:
	UFUNCTION()
	void HandlePawnPostResIn(AFortPlayerPawn* Pawn);

};

