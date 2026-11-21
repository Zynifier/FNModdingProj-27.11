// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "Components/GameFrameworkComponent.h"
#include "DronePickUpIndicatorComponent.generated.h"

class AActor;
class AFortScoutDrone;
class UFortActorIndicatorWidget;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UDronePickUpIndicatorComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UDronePickUpIndicatorComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	void Init(AFortScoutDrone* Drone);

	UFUNCTION()
	void OnDroneDestroyed(AActor* DestroyedActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DronePickUpIndicatorComponent")
	TSubclassOf<UFortActorIndicatorWidget> ItemIndicatorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="DronePickUpIndicatorComponent")
	TSubclassOf<UFortActorIndicatorWidget> DbnoIndicatorType;

private:
	UPROPERTY(Transient)
	FUserWidgetPool IndicatorPool;

};

