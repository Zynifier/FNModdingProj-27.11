// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/HitResult.h"
#include "FortPhysicsOverlapComponent.generated.h"

class AActor;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortPhysicsOverlapComponent : public USceneComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortPhysicsOverlapComponent")
	bool bBeginPlayDisablePhysicsObjectSleepWhenOverlapping;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortPhysicsOverlapComponent")
	float OverlapRadius;

private:
	UFUNCTION()
	void OnPhysicsObjectBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnPhysicsObjectEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void SetNeverSleepWhenOverlapping(const bool bShouldSleep = true);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USphereComponent> OverlapComponent;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> SleepIncrementedPhysicsObjects;

};

