// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameplayStreamingHandler.h"
#include "SalmonGameplayStreamingHandler.h"
#include "FortSalmonGameplayStreamingHandler.generated.h"

UCLASS()
class UFortSalmonGameplayStreamingHandler : public USalmonGameplayStreamingHandler, public IFortGameplayStreamingHandler
{
	GENERATED_BODY()

};

