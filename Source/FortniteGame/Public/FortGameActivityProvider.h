// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortGameActivityProvider.generated.h"

class AFortPlayerController;
class UFortGameActivity;

UCLASS(Abstract, MinimalAPI)
class UFortGameActivityProvider : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TObjectPtr<UFortGameActivity>> Activities;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerController> OwningPlayer;

};

