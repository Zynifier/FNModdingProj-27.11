// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortProjectPlayComponent.h"
#include "FortProjectEditComponent.generated.h"

class APlayerController;
class UDeltaFileSaveHandler;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortProjectEditComponent : public UFortProjectPlayComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortProjectEditComponent")
	bool bRestrictContentToTeamMembers;

private:
	UFUNCTION()
	FORTNITEGAME_API void OnAnyPlayerLoggedIn(APlayerController* PlayerController);

	UPROPERTY(Config)
	int32 DeltasPeriodicSaveIntervalSeconds_Default;

	UPROPERTY(Config)
	int32 DeltasPeriodicSaveIntervalSeconds_PIEOverride;

	UPROPERTY()
	TObjectPtr<UDeltaFileSaveHandler> DeltasSaveHandler;

};

