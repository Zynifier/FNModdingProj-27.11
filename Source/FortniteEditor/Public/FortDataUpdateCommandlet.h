// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/ResavePackagesCommandlet.h"
#include "FortDataUpdateCommandlet.generated.h"

UCLASS(Abstract, Config=Editor)
class UFortDataUpdateCommandlet : public UResavePackagesCommandlet
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FName> PersistentMapsNames;

};

