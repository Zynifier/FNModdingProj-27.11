// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortExhibitActor.h"
#include "FortItemExhibitActor.generated.h"

class AFortPickup;

UCLASS()
class AFortItemExhibitActor : public AFortExhibitActor
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FString ItemInstanceId;

	UPROPERTY(Transient)
	TObjectPtr<AFortPickup> ExhibitItem;

};

