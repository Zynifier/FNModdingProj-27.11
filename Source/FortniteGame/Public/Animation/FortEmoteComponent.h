// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortEmoteComponent.generated.h"

class AFortPersistentProp;

UCLASS()
class UFortEmoteComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DespawnActivePersistentProp(bool bShouldInstantDestroy);

	UFUNCTION(BlueprintPure, Category="Persistent Prop")
	AFortPersistentProp* GetActivePersistentProp() const;

	UFUNCTION(BlueprintCallable)
	AFortPersistentProp* SpawnPersistentProp(TSubclassOf<AFortPersistentProp> PropClass, FName AttachSocket);

private:
	UPROPERTY()
	AFortPersistentProp* ActivePersistentProp;

};

