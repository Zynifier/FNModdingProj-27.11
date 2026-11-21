// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortActorIsRelevantInterface.generated.h"

class AActor;

UINTERFACE(BlueprintType, Blueprintable)
class UFortActorIsRelevantInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortActorIsRelevantInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	bool IsActorRelevant(const AActor* OtherActor) const;

	UFUNCTION(BlueprintImplementableEvent)
	bool IsLocationRelevant(FVector Location) const;

};

