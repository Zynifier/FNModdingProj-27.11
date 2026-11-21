// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "FortTemporaryItemsComponent.generated.h"

class UFortMcpProfileAthena;
class UFortTemporaryItemsManager;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortTemporaryItemsComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortTemporaryItemsComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void OnAthenaProfileInitialized();

	UPROPERTY()
	TObjectPtr<UFortTemporaryItemsManager> TemporaryItemsManager;

	UPROPERTY()
	TWeakObjectPtr<UFortMcpProfileAthena> AthenaProfile;

};

