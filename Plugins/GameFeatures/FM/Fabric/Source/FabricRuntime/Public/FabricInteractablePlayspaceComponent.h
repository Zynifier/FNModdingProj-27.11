// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/SpatialGameplay/SpatialGameplayContextEvent.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "PlayspaceComponent.h"
#include "PlayspaceUsers.h"
#include "FabricInteractablePlayspaceComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FABRICRUNTIME_API UFabricInteractablePlayspaceComponent : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetFabricDeviceExistsInPlayspace();

protected:
	UFUNCTION()
	void OnDownloadOnDemandCompleteIndividualClient(FEventMessageTag Channel, const FClientFinishedDownloadOnDemand& Context);

	UFUNCTION()
	void OnPlayspaceUserAdded(const FPlayspaceUser& PlayspaceUser);

};

