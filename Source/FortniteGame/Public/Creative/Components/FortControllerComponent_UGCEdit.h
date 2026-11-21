// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_UGCEdit.generated.h"

class AActor;
class UFortUserOptionContainerComponent;

UCLASS(Config=Game, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_UGCEdit : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOptInForDeviceUpgrades(AActor* ContextActor);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerOptInForMemorySystemUpgrades(AActor* ContextActor);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateUserOptionValues(UFortUserOptionContainerComponent* UserOptionContainerComponent, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues);

};

