// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeBudgetLibrary.h"

bool UFortCreativeBudgetLibrary::CanPlaceClassInstances(APlayerController* Controller, const TArray<TSubclassOf<AActor>> Classes, const FVector& Location)
{
	return false;
}

bool UFortCreativeBudgetLibrary::CanPlaceInstanceOfClass(APlayerController* Controller, TSubclassOf<AActor> Class, const FVector& Location)
{
	return false;
}
