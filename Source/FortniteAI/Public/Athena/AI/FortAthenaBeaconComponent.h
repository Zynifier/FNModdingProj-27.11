// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortAthenaBeaconComponent.generated.h"

class AActor;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBeaconComponentOnConsume);

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAthenaBeaconComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Attraction", meta=(ClampMin="1"))
	int32 MaxAttractedBots;

	UPROPERTY(EditDefaultsOnly, Category="Attraction", meta=(ClampMin="100.000000"))
	float AttractionRadius;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> RegisteredActors;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FBeaconComponentOnConsume OnConsumeEvent;

	UPROPERTY(Transient)
	bool bIsConsumed;

};

