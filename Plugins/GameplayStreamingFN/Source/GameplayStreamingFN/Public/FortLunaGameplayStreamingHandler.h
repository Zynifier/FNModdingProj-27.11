// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameplayStreamingHandler.h"
#include "LunaGameplayStreamingHandler.h"
#include "FortLunaGameplayStreamingHandler.generated.h"

UCLASS()
class UFortLunaGameplayStreamingHandler : public ULunaGameplayStreamingHandler, public IFortGameplayStreamingHandler
{
	GENERATED_BODY()

};

