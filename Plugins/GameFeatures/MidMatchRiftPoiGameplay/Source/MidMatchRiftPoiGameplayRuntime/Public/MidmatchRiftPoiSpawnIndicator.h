// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Athena/FortVehicleTeleportPortal.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "MidmatchRiftPoiSpawnIndicator.generated.h"

class AActor;
class UDataLayerInstance;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AMidmatchRiftPoiSpawnIndicator : public AActor, public IVehicleTeleportPortal, public IFortMarkableActorInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Rift Poi")
	bool IsActorInDataLayerInstance(const AActor* Actor, const UDataLayerInstance* DataLayerInstance) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Rift Poi")
	void TeleportVehicleActor(AActor* VehicleActor, const FVector& TeleportLocation);

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	FMarkedActorDisplayInfo MarkerDisplay;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	FVector MarkerPositionOffset;

};

