// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManager_Coupled.generated.h"

class AActor;
class AFortPlayerController;
class UObject;

UCLASS(MinimalAPI)
class UFortCheatManager_Coupled : public UChildCheatManager
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UObject> TargetedObject;

	UPROPERTY()
	TObjectPtr<AFortPlayerController> OwningController;

private:
	UFUNCTION()
	FORTNITEGAME_API void OnTargetedActorDestroyed(AActor* DestroyedActor);

};

