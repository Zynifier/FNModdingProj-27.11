// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortSlateHUDIndicator.h"
#include "FortSpottedActorIndicator.generated.h"

class AFortPlayerController;

UCLASS()
class UFortSpottedActorIndicator : public UFortSlateHUDIndicator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> OwnerPC;

};

