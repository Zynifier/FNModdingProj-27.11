// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativeGameStreamDeviceComponent.generated.h"

class AFortMinigame;
class UCreativeGameStreamDeviceComponent;
class UFortMinigameLogicComponent;
enum class EFortMinigameState : uint8;

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UCreativeGameStreamDeviceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FCreativeGameStreamDeviceComponentSignature, UCreativeGameStreamDeviceComponent, OnTriggered, UCreativeGameStreamDeviceComponent*, CreativeGameStreamDeviceComponent);

public:
	UFUNCTION(BlueprintCallable)
	void AddToEndGameQueue();

	UFUNCTION(BlueprintCallable)
	void Init(UFortMinigameLogicComponent* InMinigameLogicComponent);

	UFUNCTION(BlueprintPure)
	bool IsWithinPublishedPlayspace() const;

	UFUNCTION(BlueprintCallable)
	void RemoveFromEndGameQueue();

	UPROPERTY(BlueprintAssignable)
	FCreativeGameStreamDeviceComponentSignature OnTriggered;

private:
	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, const EFortMinigameState NewMinigameState);

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortMinigameLogicComponent> MinigameLogicComponent;

};

